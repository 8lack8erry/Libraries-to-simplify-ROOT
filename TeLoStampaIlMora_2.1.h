#ifndef TeLoStampaIlMora_h
#define TeLoStampaIlMora_h

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

#include "MatriceStampa.h"

#include"TH1F.h"
#include"TF1.h"
#include"TMath.h"
#include"TGraph.h"
#include"TGraphErrors.h"
#include"TCanvas.h"
#include"TFitResult.h"
#include"TLegend.h"
#include"TPaveText.h"
#include"TMultiGraph.h"
#include"TLatex.h"
#include"TLine.h"

using namespace std;

/*
	kBlue=600 - kRed=632 - kGreen=416 - kOrange=800 - kPink=900 - kViolet=880 - kMagenta=616 - kAzure=860 - kSpring=820 - kYellow=400
*/

// vector<double> Legend_coordinates = {0.1, 0.7, 0.48, 0.9}; In alto a sinistra 
// vector<double> Legend_coordinates = {0.6, 0.1, 0.9, 0.4}; In basso a destra
// vector<double> Legend_coordinates = {0.6, 0.7, 0.9, 0.9}; In alto a destra
// vector<double> Legend_coordinates = {0.52, 0.4, 0.9, 0.6}; In centro a destra


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//STAMPA GRAPH
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\


/*
    graph = T graph --> if you want to plot 1 graph 
    "Graphic Options" = string "Graphic Options"

    graph = T1 graph1, T2 graph2 --> if you want to plot 2 graphs, potentialy they can have different type
    "Graphic Options" = vector<string> Graphic Options = {"Graphic Options 1", "Graphic Options 2"}

    graph = T1 graph1, T2 graph2, T3 graph3 --> if you want to plot 3 graphs, potentialy they can have different type
    "Graphic Options" = vector<string> Graphic Options = {"Graphic Options 1", "Graphic Options 2", "Graphic Options 3"}
    
    graph = T1 graph1, T2 graph2, T3 graph3, T4 graph --> if you want to plot 4 graphs, potentialy they can have different type
    "Graphic Options" = vector<string> Graphic Options = {"Graphic Options 1", "Graphic Options 2", "Graphic Options 3", "Graphic Options 4"}

    graph = vector<T> graphs --> if you want to plot a lot of graphs with same type 
    "Graphic Options" = vector<string> Graphic Options 

    graph = vector<T1> graphs1, vector<T2> graphs2 --> if you want to plot a lot of graphs of 2 different types
    "Graphic Options" = vector<string> Graphic Options 1, vector<string> Graphic Options 2 

    graph = vector<T1> graphs1, vector<T2> graphs2, vector<T3> graphs3 --> if you want to plot a lot of graphs of 3 different types
    "Graphic Options" = vector<string> Graphic Options 1, vector<string> Graphic Options 2, vector<string> Graphic Options 3

    graph = vector<T1> graphs1, vector<T2> graphs2, vector<T3> graphs3, vector<T4> graphs4 --> if you want to plot a lot of graphs 
                                                                                                of 4 different types
    "Graphic Options" = vector<string> Graphic Options 1, vector<string> Graphic Options 2, vector<string> Graphic Options 3, 
                        vector<string> Graphic Options 4
*/


//stampaGraph (graph, "destination.png", "Title", "X", "Y", "Graphic options", Legend*)

//stampaGraph - LogScale (graph, "destination.png", "Title", "X", "Y", "Graphic options", logAxis "x"/"y"/"xy", Legend*)

//stampaGraph - SetRange (graph, "destination.png", "Title", "X", "Y", "Graphic options", setAxis "x"/"y"/"xy", 
                            //extremes (vector<Q>), Legend*)

//stampaGraph - LogScale - SetRange (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                            //logAxis "x"/"y"/"xy", setAxis "x"/"y"/"xy", extremes (vector<Q>), Legend*)

//stampaGraph - TLine (graph, "destination.png", "Title", "X", "Y", "Graphic options", Line Cordinates (vector<double>)
                            //TLineColor, TLineThickness, Legend*)

//stampaGraph - LogScale - TLine (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                            //logAxis "x"/"y"/"xy", Line Cordinates (vector<double>), TLineColor, TLineThickness, Legend*)

//stampaGraph - SetRange - TLine (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                            //setAxis "x"/"y"/"xy", extremes (vector<Q>), Line Cordinates (vector<double>), TLineColor, 
                            //TLineThickness, Legend*)

//stampaGraph - LogScale - SetRange - TLine (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                            //logAxis "x"/"y"/"xy", setAxis "x"/"y"/"xy", extremes (vector<Q>), Line Cordinates (vector<double>), 
                            //TLineColor, TLineThickness, Legend*)

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//* Legend is a boolean variable, if true --> print automatic legend in the plot
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//stampaGraph - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", Legend Cordinates (vector<double>), 
                            //"Legend Title"*, "Legend Title Position", "Legend Options", Legend Entries (vector<string>))

//stampaGraph - LogScale - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", logAxis "x"/"y"/"xy",
                                //Legend Cordinates (vector<double>), "Legend Title"*, "Legend Position", "Legend Options", Legend Entries (vector<string>))

//stampaGraph - SetRange - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", setAxis "x"/"y"/"xy", 
                                //extremes (vector<Q>), Legend Cordinates (vector<double>), "Legend Title"*, 
                                //"Legend Title Position", "Legend Options", Legend Entries (vector<string>))

//stampaGraph - LogScale - SetRange - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", logAxis "x"/"y"/"xy",
                                //setAxis "x"/"y"/"xy", extremes (vector<Q>), Legend Cordinates (vector<double>), "Legend Title"*, 
                                //"Legend Title Position", "Legend Options", Legend Entries (vector<string>))

//stampaGraph - TLine - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", Line Cordinates (vector<double>), 
                                //TLineColor, TLineThickness, Legend Cordinates (vector<double>), "Legend Title"*, 
                                //"Legend Title Position", "Legend Options", Legend Entries (vector<string>))

//stampaGraph - LogScale - TLine - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                                //logAxis "x"/"y"/"xy", Line Cordinates (vector<double>), TLineColor, TLineThickness, 
                                //Legend Cordinates (vector<double>), "Legend Title"*, "Legend Title Position",
                                // "Legend Options", Legend Entries (vector<string>))

//stampaGraph - SetRange - TLine - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                                //setAxis "x"/"y"/"xy", extremes (vector<Q>), Line Cordinates (vector<double>), 
                                //TLineColor, TLineThickness, Legend Cordinates (vector<double>), "Legend Title"*, 
                                //"Legend Title Position", "Legend Options", Legend Entries (vector<string>))

//stampaGraph - LogScale - SetRange - TLine - ManualLegend (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                                //logAxis "x"/"y"/"xy", setAxis "x"/"y"/"xy", extremes (vector<Q>), Line Cordinates (vector<double>), 
                                //TLineColor, TLineThickness, Legend Cordinates (vector<double>), "Legend Title"*, 
                                //"Legend Title Position", "Legend Options", Legend Entries (vector<string>))

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//* If "Legend Title" is equal to "" --> No Legend Title
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//stampaGraph - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", Box Cordinates (vector<double>), 
                            // Box Entries (vector<string>))

//stampaGraph - LogScale - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", logAxis "x"/"y"/"xy",
                                //Box Cordinates (vector<double>), Box Entries (vector<string>))

//stampaGraph - SetRange - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", setAxis "x"/"y"/"xy", 
                                //extremes (vector<Q>), Box Cordinates (vector<double>), Box Entries (vector<string>))

//stampaGraph - LogScale - SetRange - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", logAxis "x"/"y"/"xy",
                                //setAxis "x"/"y"/"xy", extremes (vector<Q>), Box Cordinates (vector<double>), Box Entries (vector<string>))

//stampaGraph - TLine - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", Line Cordinates (vector<double>), 
                                //TLineColor, TLineThickness, Box Cordinates (vector<double>), Box Entries (vector<string>))

//stampaGraph - LogScale - TLine - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                                //logAxis "x"/"y"/"xy", Line Cordinates (vector<double>), TLineColor, TLineThickness, 
                                //Box Cordinates (vector<double>), Box Entries (vector<string>))

//stampaGraph - SetRange - TLine - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                                //setAxis "x"/"y"/"xy", extremes (vector<Q>), Line Cordinates (vector<double>), 
                                //TLineColor, TLineThickness, Box Cordinates (vector<double>), Box Entries (vector<string>))

//stampaGraph - LogScale - SetRange - TLine - Box (graph, "destination.png", "Title", "X", "Y", "Graphic options", 
                                //logAxis "x"/"y"/"xy", setAxis "x"/"y"/"xy", extremes (vector<Q>), Line Cordinates (vector<double>), 
                                //TLineColor, TLineThickness, Box Cordinates (vector<double>), Box Entries (vector<string>))


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//STAMPA GRAPH
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

//StampaGraph
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - SetRange
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - SetRange
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - TLine
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - TLine
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - SetRange - TLine
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - SetRange - TLine
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - ManualLegend
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - ManualLegend
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - SetRange - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - SetRange - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - TLine - ManualLegend
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - TLine - ManualLegend
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - SetRange - TLine - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - SetRange - TLine - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - TBox
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - TBox
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis, 
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - SetRange - TBox
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - SetRange - TBox
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - TLine - TBox
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - TLine - TBox
template<typename T>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis, 
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - SetRange - TLine - TBox
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph - LogScale - SetRange - TLine - TBox
template<typename T, typename Q>
void stampaGraph(
    T point, 
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1 = {&point};
    vector<string> GraphicOption1 = {GraphicOption.c_str()};
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};




//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//STAMPA 2 GRAPHS
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

//StampaGraphs 2
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - SetRange    
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - SetRange    
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - TLine    
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,    
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - TLine
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,   
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - SetRange - TLine
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - SetRange - TLine
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - ManualLegend
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - ManualLegend
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - SetRange - ManualLegend
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - SetRange - ManualLegend
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - TLine - ManualLegend
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - TLine - ManualLegend
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - SetRange - TLine - ManualLegend
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - SetRange - TLine - ManualLegend
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - TBox
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - TBox
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - SetRange - TBox
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - SetRange - TBox
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - TLine - TBox
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - TLine - TBox
template<typename T1, typename T2>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - SetRange - TLine - TBox
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 2 - LogScale - SetRange - TLine - TBox
template<typename T1, typename T2, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T1*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};




//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//STAMPA 3 GRAPHS
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

//StampaGraphs 3
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - SetRange    
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - SetRange    
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - TLine    
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,    
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - TLine
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,   
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - SetRange - TLine
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - SetRange - TLine
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - ManualLegend
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - ManualLegend
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - SetRange - ManualLegend
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - SetRange - ManualLegend
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - TLine - ManualLegend
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - TLine - ManualLegend
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - SetRange - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - SetRange - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - TBox
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - TBox
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - SetRange - TBox
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - SetRange - TBox
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - TLine - TBox
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - TLine - TBox
template<typename T1, typename T2, typename T3>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - SetRange - TLine - TBox
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 3 - LogScale - SetRange - TLine - TBox
template<typename T1, typename T2, typename T3, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T1*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};




//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//STAMPA 4 GRAPHS
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

//StampaGraphs 4
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - SetRange    
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - SetRange    
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - TLine    
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,    
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - TLine
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,   
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - SetRange - TLine
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - SetRange - TLine
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - ManualLegend
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - ManualLegend
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - SetRange - ManualLegend
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - SetRange - ManualLegend
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - SetRange - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - SetRange - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - TBox
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - TBox
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - SetRange - TBox
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - SetRange - TBox
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - TLine - TBox
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - TLine - TBox
template<typename T1, typename T2, typename T3, typename T4>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - SetRange - TLine - TBox
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph 4 - LogScale - SetRange - TLine - TBox
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void stampaGraph(
    T1 point1, 
    T2 point2,
    T3 point3,
    T4 point4,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T1*> graph1 = {&point1};
    vector<string> GraphicOption1 = {GraphicOption.at(0).c_str()};
    vector<T2*> graph2 = {&point2};
    vector<string> GraphicOption2 = {GraphicOption.at(1).c_str()};
    vector<T3*> graph3 = {&point3};
    vector<string> GraphicOption3 = {GraphicOption.at(2).c_str()};
    vector<T4*> graph4 = {&point4};
    vector<string> GraphicOption4 = {GraphicOption.at(3).c_str()};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};




//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//STAMPA VECTOR OF GRAPHS
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

//StampaGraphs vector
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - SetRange    
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - SetRange    
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - TLine    
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,    
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - TLine
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,   
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - SetRange - TLine
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - SetRange - TLine
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes, 
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    bool Legend = false
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis.c_str(), set_axis.c_str(), extremes, LineCoordinates, TLineColor, TLineThickness, Legend, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - ManualLegend
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - ManualLegend
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & log_axis,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - SetRange - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - SetRange - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - TLine - ManualLegend
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - TLine - ManualLegend
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - SetRange - TLine - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - SetRange - TLine - ManualLegend
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int TLineColor,
    int TLineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions, 
    vector<string> LegendEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - TBox
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - TBox
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, PaveCoordinates, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - SetRange - TBox
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - SetRange - TBox
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - TLine - TBox
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - TLine - TBox
template<typename T>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis, 
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - SetRange - TLine - TBox
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};

//StampaGraph vector - LogScale - SetRange - TLine - TBox
template<typename T, typename Q>
void stampaGraph(
    vector<T> points,
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<string> & GraphicOption,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    vector<T*> graph1;
    for(T p : points)   graph1.push_back(&p);
    vector<string> GraphicOption1 = GraphicOption;
    vector<T*> graph2 = {};
    vector<string> GraphicOption2 = {};
    vector<T*> graph3 = {};
    vector<string> GraphicOption3 = {};
    vector<T*> graph4 = {};
    vector<string> GraphicOption4 = {};

    MatriceMultigraph(destinationPNG.c_str(), graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), log_axis, set_axis, extremes, LineCoordinates, LineColor, LineThickness, PaveEntry, graph1, GraphicOption1, graph2, GraphicOption2, graph3, GraphicOption3, graph4, GraphicOption4);
};



#endif