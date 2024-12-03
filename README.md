# Libraries-to-simplify-ROOT
I usually perform data analysis in ROOT, which I find very useful but sometimes quite complex. To make things easier, I have written some libraries to simplify plotting and fitting.

# Graphing and Utility Tools
This library provides tools to handle and visualize graphs using ROOT framework. It includes methods for plotting various graph types, applying graphical options, and analyzing data with utility functions.

## Graph Plotting Tool: '''stampaGraph'''
### Overview
stampaGraph is a versatile graphing function that supports multiple features:

Plotting 1 or multiple graphs of different types.
Applying log scales.
Setting axis ranges.
Adding lines (TLine) or boxes to the plot.
Configuring legends (automatic or manual).
General Syntax
cpp
Copia codice
stampaGraph(graph, "destination.png", "Title", "X", "Y", "Graphic Options", Additional Parameters...);
Supported Features
Single or Multiple Graphs

Pass one or more graphs of the same or different types (TGraph, TH1F, TGraphErrors, etc.).
Example:
cpp
Copia codice
TGraph graph1;
TGraphErrors graph2;
stampaGraph(graph1, graph2, "destination.png", "Title", "X", "Y", {"Option1", "Option2"});
Log Scales

Enable log scaling on specific axes (x, y, or xy).
Example:
cpp
Copia codice
stampaGraph(graph, "destination.png", "Title", "X", "Y", "Option", "x");
Set Axis Range

Specify axis ranges using setAxis and extremes.
Example:
cpp
Copia codice
vector<double> extremes = {xmin, xmax, ymin, ymax};
stampaGraph(graph, "destination.png", "Title", "X", "Y", "Option", "x", extremes);
Add Lines

Draw lines using coordinates, color, and thickness.
Example:
cpp
Copia codice
vector<double> lineCoords = {x1, y1, x2, y2};
stampaGraph(graph, "destination.png", "Title", "X", "Y", "Option", lineCoords, kRed, 2);
Legends

Automatic or manual legends.
Example (manual):
cpp
Copia codice
vector<double> legendCoords = {x1, y1, x2, y2};
vector<string> legendEntries = {"Dataset 1", "Dataset 2"};
stampaGraph(graph, "destination.png", "Title", "X", "Y", "Option", legendCoords, "Legend Title", "TR", "Option", legendEntries);
Boxes

Draw customizable boxes with entries.
Example:
cpp
Copia codice
vector<double> boxCoords = {x1, y1, x2, y2};
vector<string> boxEntries = {"Box 1", "Box 2"};
stampaGraph(graph, "destination.png", "Title", "X", "Y", "Option", boxCoords, boxEntries);
Advanced Combinations
You can combine multiple features in one call:

Example:
cpp
Copia codice
stampaGraph(graph, "destination.png", "Title", "X", "Y", "Option", "x", extremes, lineCoords, kRed, 2, legendCoords, "Legend Title", "TR", "Option", legendEntries);
Utility Library: moraRoot.h
Overview
This header includes utility functions for data analysis and graph preparation.

Key Features
Scientific Notation Conversion

cpp
Copia codice
ScientificNotation Exponential(double n);
Converts a number into scientific notation.
Mean Calculation

cpp
Copia codice
double mean(vector<double> data);
Find Minimum/Maximum

cpp
Copia codice
template<typename T> T Min(const vector<T>& v);
template<typename T> T Max(const vector<T>& v);
Import ROOT Objects

cpp
Copia codice
template<typename T> T import_Tobject(const string& fileNameROOT, const string& ObjectName);
Imports a ROOT object (e.g., histogram or graph) from a .root file.
Histogram Creation

cpp
Copia codice
template<typename T, typename Q>
T FillHist(vector<Q> data, int nbin, const string& histoName, bool Normalization = true);
Generates a histogram with optional normalization.
Fit Handling

cpp
Copia codice
template<typename T>
void fit(T* point, TF1* function, int n_parameters, const string& Option, int precision, double min = nan(double), double max = nan(double), bool covMat = true);
Performs fitting with options for parameter control and covariance matrix output.
Best Fit Extremes

cpp
Copia codice
pair<double, double> best_fit_extremes(TH1D h, double increments_sx, double increments_dx, pair<double, double> initial_extremes);
Determines the optimal fit range for a dataset.
ROOT Dependencies
The library uses ROOT classes such as:

TH1F, TF1, TGraph, TCanvas, TLegend, and more. Ensure the ROOT framework is installed and properly configured.
Usage Example
cpp
Copia codice
#include "moraRoot.h"

int main() {
    // Example histogram creation
    vector<double> data = {1.1, 2.2, 3.3, 4.4, 5.5};
    TH1F hist = FillHist<TH1F, double>(data, 10, "Example Histogram");

    // Fit function
    TF1 func("fit", "gaus", 0, 5);
    fit(&hist, &func, 3, "R", 3);

    // Graph plotting
    stampaGraph(hist, "output.png", "Histogram", "X-axis", "Y-axis", "HIST");
}
Dependencies
ROOT Framework: Install ROOT (https://root.cern/) to use the library.
C++ Standard Library: Required for vector, string, cmath, etc.
License
This library is free for academic and research use. For other uses, please contact the author.

Author
Developed by Andrea Morandi.
