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
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Graphic Options", Additional Parameters...);
```
### Examples
 - Single or Multiple Graphs
```cpp
TGraph graph1;
TGraphErrors graph2;
stampaGraph(graph1, graph2, "destination.png", "Title", "X-axis", "Y-axis", {"Option1", "Option2"});
```
 - Log Scales
```cpp
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", "x");
```
 - Set Axis Range
``` cpp
Copia codice
vector<double> extremes = {xmin, xmax, ymin, ymax};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", "x", extremes);
```
 - Add Lines
```cpp
vector<double> lineCoords = {x1, y1, x2, y2};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", lineCoords, kRed, 2);
```
 - Legends
```cpp
vector<double> legendCoords = {x1, y1, x2, y2};
vector<string> legendEntries = {"Dataset 1", "Dataset 2"};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", legendCoords, "Legend Title", "TR", legendEntries);
```
 - Boxes
```cpp
vector<double> boxCoords = {x1, y1, x2, y2};
vector<string> boxEntries = {"Box 1", "Box 2"};
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", boxCoords, boxEntries);
```
 - Advanced Combination
```cpp
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Option", "x", extremes, lineCoords, kRed, 2, legendCoords, "Legend Title", "TR", legendEntries);
```
## Utility Library: `moraRoot.h`
### Features
This header file provides utility functions for:
 - Scientific Notation
```cpp
ScientificNotation Exponential(double n);
```
 - Mean Calculation
```cpp
double mean(vector<double> data);
```
 - Min/Max Calculation
```cpp
template<typename T> T Min(const vector<T>& v);
template<typename T> T Max(const vector<T>& v);
```
 - ROOT Object Import
```cpp
template<typename T> T import_Tobject(const string& fileNameROOT, const string& ObjectName);
```
 - Histogram Creation
```cpp
template<typename T, typename Q>
T FillHist(vector<Q> data, int nbin, const string& histoName, bool Normalization = true);
```
 - Fit Handling
```cpp
template<typename T>
void fit(T* point, TF1* function, int n_parameters, const string& Option, int precision, double min = nan(double), double max = nan(double), bool covMat = true);
```
 - Best Fit Extremes
```cpp
pair<double, double> best_fit_extremes(TH1D h, double increments_sx, double increments_dx, pair<double, double> initial_extremes);
```

### ROOT Dependencies
This library requires ROOT classes such as:
`TH1F, TF1, TGraph, TCanvas, TLegend, and others`. Ensure the ROOT framework is installed and configured.

### Example
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
### Dependencies
 - ROOT Framework: This library requires ROOT classes such as:`TH1F, TF1, TGraph, TCanvas, TLegend, and others`. Ensure the ROOT framework is installed and configured.
 - C++ Standard Library: Required for vector, string, cmath, etc.
