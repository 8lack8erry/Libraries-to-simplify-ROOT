# Libraries-to-simplify-ROOT

I often perform data analysis using ROOT, a powerful yet sometimes complex framework. To streamline common tasks like plotting and fitting, I have developed libraries that simplify these processes.

---

## Graphing and Utility Tools

### Overview
This library offers tools to handle and visualize graphs in the ROOT framework. Features include:
- Plotting various graph types.
- Customizing axis ranges, log scales, and legends.
- Adding lines, boxes, and advanced graphical elements.
- Simplifying data analysis through utility functions.

---

## Graph Plotting Tool: `stampaGraph`

### Features
`stampaGraph` is a versatile function that supports:
- Plotting one or multiple graphs (`TGraph`, `TH1F`, `TGraphErrors`, etc.).
- Applying log scales (`x`, `y`, or `xy`).
- Configuring axis ranges.
- Adding lines (`TLine`) or customizable boxes.
- Automatic or manual legend placement.

### General Syntax
```cpp
stampaGraph(
            graph,
            "destination.png",
            "Title",
            "X-axis",
            "Y-axis",
            "Graphic Options",
            Additional Parameters...
);
```

### Examples
#### Single or Multiple Graphs
```cpp
TGraph graph1;
TGraphErrors graph2;
stampaGraph(graph1, graph2, "destination.png", "Title", "X-axis", "Y-axis", {"Option1", "Option2"});
```
Here `{"Option1", "Option2"}` are the graphical options for the graphs, for exaple `APL`. 
#### Log Scales
Specify which axes should use a logarithmic scale:
 - `x` for the x-axis;
 - `y` for the y-axis;
 - `xy` for both axes;
For example:
```cpp
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", "x");
```
#### Set Axis Range
Define the range for the x and y axes by providing values for each axis. Available options:
 - `{xmin, xmax}` and `x` for the x-axes;
 - `{ymin, ymax}` and `y` for the y-axes;
 - `{xmin, xmax, ymin, ymax}` and `xy` for both axes;
Example:
``` cpp
vector<double> extremes = {xmin, xmax};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", "x", extremes);
```
#### Add Lines
Specify the coordinates, color, and width of the line:
```cpp
vector<double> lineCoords = {x1, y1, x2, y2};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", lineCoords, kRed, 2);
```
#### Legends
Define the coordinates, entries, title, and graphical options for the legend:
```cpp
vector<double> legendCoords = {x1, y1, x2, y2};
vector<string> legendEntries = {"Dataset 1", "Dataset 2"};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", legendCoords, "Legend Title", "Legend Option", legendEntries);
```
#### Boxes
Specify the coordinates and entries for the box:
```cpp
vector<double> boxCoords = {x1, y1, x2, y2};
vector<string> boxEntries = {"Box 1", "Box 2"};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", boxCoords, boxEntries);
```
#### Advanced Combination
```cpp
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", "x", extremes, lineCoords, kRed, 2, legendCoords, "Legend Title", "Legend Option", legendEntries);
```

---

## Utility Library: `moraRoot.h`

### Features
This header file provides utility functions for:
#### Scientific Notation
The library provides a class called `ScientificNotation` to represent numbers in scientific notation format. The class takes two arguments: the base and the exponent.

There is also a function named `Exponential` that converts a number into an object of the `ScientificNotation` class. This simplifies working with numbers in scientific notation.

##### Class Definition:

```cpp
class ScientificNotation {
public:
    double base; // The base of the scientific notation
    int exponent; // The exponent in the scientific notation

    ScientificNotation(double base, int exponent) : base(base), exponent(exponent) {}
};
```
##### Function:
```cpp
ScientificNotation Exponential(double n);
```
#### Mean Calculation
```cpp
double mean(vector<double> data);
```
#### Min/Max Calculation
```cpp
template<typename T> T Min(const vector<T>& v);
template<typename T> T Max(const vector<T>& v);
```
#### ROOT Object Import
Import object, like `TF1`, `TH1`, ecc. from a ROOT file.
```cpp
template<typename T> T import_Tobject(const string& fileNameROOT, const string& ObjectName);
```
#### Histogram Creation
Create histograms from data vectors:
```cpp
template<typename T, typename Q>
T FillHist(vector<Q> data, int nbin, const string& histoName, bool Normalization = true);
```
If `Normalization = true`, the total area under the histogram will be 1.
#### Fit Handling
```cpp
template<typename T>
void fit(T* point, TF1* function, int n_parameters, const string& Option, int precision, double min = nan(double), double max = nan(double), bool covMat = true);
```
Here `min`, `max` are the extremes of the fit, if they are `nan` the fit applies to the entire graph.
##### Example
```cpp
#include "moraRoot.h"

int main() {
    // Example: Create a histogram
    vector<double> data = {1.1, 2.2, 3.3, 4.4, 5.5};
    TH1F hist = FillHist<TH1F, double>(data, 10, "Example Histogram");

    // Fit the histogram
    TF1 func("fit", "gaus", 0, 5);
    fit(&hist, &func, 3, "R", 3);

    // Plot the graph
    stampaGraph(hist, "output.png", "Histogram", "X-axis", "Y-axis", "HIST");
}
```

---

## Graph Plotting and Fitting Tool: `stampaGraph_Fit`
### Features
The `stampaGraph_Fit` function extends the functionality of the `stampaGraph` tool by integrating fitting capabilities with detailed graphical customization and automatic annotation. It simplifies the process of visualizing and analyzing fitted data in ROOT.

### Key Functionalities
#### Fitting:
 - Fits a provided function (`TF1`) to the graph data.
 - Supports optional fitting within a specified range (`min`,`max`).
#### Annotation with Fit Results:
Automatically computes and displays:
 - Chi-squared and degrees of freedom (`/chi^{2}/ dof`).
 - Fit parameters and their uncertainties.
#### Customizable Annotations:
Specify the position of annotation boxes using normalized device coordinates (NDC).
Include descriptive entries for fit parameters.

### General Syntax
```cpp
template<typename T>
void stampaGraph_Fit(
    T *point, 
    TF1 *function,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    double min = nan(double), 
    double max = nan(double),
    int n_parameters = 0,
    vector<double> PaveCoordinates = {nan(double)},
    vector<string> PaveEntries = {}
);
```
#### Parameters
 - `T *point`: Pointer to the graph to be plotted.
 - `TF1 *function`: The function to be fitted to the graph.
 - `const string & destinationPNG`: Path and filename to save the output image.
 - `const string & graphName`: Title of the graph.
 - `const string & XaxisName`: Label for the x-axis.
 - `const string & YaxisName`: Label for the y-axis.
 - `const string & GraphicOption`: ROOT graphical option string (e.g., `APL`, `HIST`).
 - `double min, double max`: (Optional) Fit range. If nan, fits the entire graph.
 - `int n_parameters`: Number of parameters in the fit function.
 - `vector<double> PaveCoordinates`: Coordinates of the annotation box in NDC (`{x1, y1, x2, y2}`).
 - `vector<string> PaveEntrie`s: Descriptive entries for the fit parameters.


### Dependencies
 - ROOT Framework: This library requires ROOT classes such as:`TH1F, TF1, TGraph, TCanvas, TLegend, and others`. Ensure the ROOT framework is installed and configured.
 - C++ Standard Library: Required for vector, string, cmath, etc.
