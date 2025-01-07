#ifndef MatriceStampa_h
#define MatriceStampa_h

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

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

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// FUNZIONI PER COSTRUIRE LE FUNZIONI DI STAMPA
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

template<typename T1, typename T2, typename T3, typename T4>
vector<bool> WhereBetter(
    vector<T1*> * graph1,
    vector<T2*> * graph2,
    vector<T3*> * graph3,
    vector<T4*> * graph4
){
    vector<bool> check(4, true);
    if(graph1 -> empty())  check.at(0) = false;
    if(graph2 -> empty())  check.at(1) = false;
    if(graph3 -> empty())  check.at(2) = false;
    if(graph4 -> empty())  check.at(3) = false;

    return check;
}

template<typename T1, typename T2, typename T3, typename T4>
TCanvas & MakeCanvas(
    TCanvas & c,
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<T1*> * graph1,
    vector<string> GraphicOption1,
    vector<T2*> * graph2,
    vector<string> GraphicOption2,
    vector<T3*> * graph3,
    vector<string> GraphicOption3,
    vector<T4*> * graph4, 
    vector<string> GraphicOption4
)
{
    vector<bool> check = WhereBetter(graph1, graph2, graph3, graph4);

    if(check.at(0)){
        graph1 -> at(0) -> SetTitle(graphName.c_str());
        graph1 -> at(0) -> GetXaxis()->SetTitle(XaxisName.c_str());
        graph1 -> at(0) -> GetYaxis()->SetTitle(YaxisName.c_str());
    }
    else if(check.at(1)){
        graph2 -> at(0) -> SetTitle(graphName.c_str());
        graph2 -> at(0) -> GetXaxis()->SetTitle(XaxisName.c_str());
        graph2 -> at(0) -> GetYaxis()->SetTitle(YaxisName.c_str());
    }
    else if(check.at(2)){
        graph3 -> at(0) -> SetTitle(graphName.c_str());
        graph3 -> at(0) -> GetXaxis()->SetTitle(XaxisName.c_str());
        graph3 -> at(0) -> GetYaxis()->SetTitle(YaxisName.c_str());
    }
    else if(check.at(3)){
        graph4 -> at(0) -> SetTitle(graphName.c_str());
        graph4 -> at(0) -> GetXaxis()->SetTitle(XaxisName.c_str());
        graph4 -> at(0) -> GetYaxis()->SetTitle(YaxisName.c_str());
    }
    
    if(check.at(0))  for(int i = 0; i < graph1 -> size(); i++)  graph1 -> at(i) -> Draw(GraphicOption1.at(i).c_str());
    if(check.at(1))  for(int i = 0; i < graph2 -> size(); i++)  graph2 -> at(i) -> Draw(GraphicOption2.at(i).c_str());
    if(check.at(2))  for(int i = 0; i < graph3 -> size(); i++)  graph3 -> at(i) -> Draw(GraphicOption3.at(i).c_str());
    if(check.at(3))  for(int i = 0; i < graph4 -> size(); i++)  graph4 -> at(i) -> Draw(GraphicOption4.at(i).c_str());

    return c;
}

TCanvas & LogScale(
    TCanvas & c, 
    const string & log_axis
)
{
    if(log_axis == "x" || log_axis == "X")    c.SetLogx();
    if(log_axis == "y" || log_axis == "Y")    c.SetLogy();
    if(log_axis == "xy" || log_axis == "XY" || log_axis == "Xy" || log_axis == "Xy"){
        c.SetLogx(); 
        c.SetLogy();
    }

    return c;
};

template<typename T, typename Q>
void SetRange(
    T * point, 
    const string & set_axis,
    vector<Q> extremes
)
{
    if(set_axis == "x" || set_axis == "X")    point -> GetXaxis() -> SetRangeUser(extremes.at(0), extremes.at(1));
    if(set_axis == "y" || set_axis == "Y")    point -> GetYaxis() -> SetRangeUser(extremes.at(0), extremes.at(1));
    if(set_axis == "xy" || set_axis == "XY" || set_axis == "Xy" || set_axis == "Xy"){
        if(extremes.size()==4){
            point -> GetXaxis() -> SetRangeUser(extremes.at(0), extremes.at(1)); 
            point -> GetYaxis() -> SetRangeUser(extremes.at(2), extremes.at(3));
        }
        else{
            point -> GetXaxis() -> SetRangeUser(extremes.at(0), extremes.at(1)); 
            point -> GetYaxis() -> SetRangeUser(extremes.at(0), extremes.at(1));
        }    
    } 
};

template<typename T1, typename T2, typename T3, typename T4, typename Q>
void SetRange_in_code(
    const string & set_axis,
    vector<Q> extremes,
    vector<T1*> * graph1,
    vector<T2*> * graph2,
    vector<T3*> * graph3,
    vector<T4*> * graph4
)
{
    vector<bool> check = WhereBetter(graph1, graph2, graph3, graph4);
    
    if(check.at(0))  SetRange(graph1 -> at(0), set_axis.c_str(), extremes);
    else if(check.at(1))  SetRange(graph2 -> at(0), set_axis.c_str(), extremes);
    else if(check.at(2))  SetRange(graph3 -> at(0), set_axis.c_str(), extremes);
    else if(check.at(3))  SetRange(graph4 -> at(0), set_axis.c_str(), extremes);
}

TLine MakeLine(
    vector<double> LineCoordinates, //(x1, y1, x2, y2)
    int LineColor,
    int LineThickness
)
{
    TLine line (LineCoordinates.at(0), LineCoordinates.at(1), LineCoordinates.at(2), LineCoordinates.at(3));
    line.SetLineColor(LineColor);
    line.SetLineWidth(LineThickness);
    return line;
};

template<typename T1, typename T2, typename T3, typename T4>
TLegend * MakeLegend(
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> * graph1,
    vector<T2*> * graph2,
    vector<T3*> * graph3,
    vector<T4*> * graph4
)
{
    TLegend * legend = new TLegend(LegendCoordinates.at(0), LegendCoordinates.at(1), LegendCoordinates.at(2), LegendCoordinates.at(3));

    if (!LegendTitle.empty()) {
        legend -> SetHeader(LegendTitle.c_str(), LegendTitlePosition.c_str());
    }

    int entryIndex = 0;
    for (int i = 0; i < graph1 -> size(); ++i, ++entryIndex) {
        legend -> AddEntry(graph1 -> at(i), LegendEntry.at(entryIndex).c_str(), LegendOptions.c_str());
    }
    for (int i = 0; i < graph2 -> size(); ++i, ++entryIndex) {
        legend -> AddEntry(graph2 -> at(i), LegendEntry.at(entryIndex).c_str(), LegendOptions.c_str());
    }
    for (int i = 0; i < graph3 -> size(); ++i, ++entryIndex) {
        legend -> AddEntry(graph3 -> at(i), LegendEntry.at(entryIndex).c_str(), LegendOptions.c_str());
    }
    for (int i = 0; i < graph4 -> size(); ++i, ++entryIndex) {
        legend -> AddEntry(graph4 -> at(i), LegendEntry.at(entryIndex).c_str(), LegendOptions.c_str());
    }

    return legend;
};

TPaveText MakeBox(
    vector<double> PaveCoordinates,
    vector<string> PaveEntry
)
{
    TPaveText text_box(PaveCoordinates.at(0), PaveCoordinates.at(1), PaveCoordinates.at(2), PaveCoordinates.at(3), "NDC");

    text_box.SetFillColor(0);
    text_box.SetTextAlign(12);
    for(auto p : PaveEntry)   text_box.AddText(p.c_str());
    
    return text_box;
};

//StampaMultigraph (4 different vector) 
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);
    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    LogScale(c, log_axis.c_str());

    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - SetRange
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale - SetRange
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    LogScale(c, log_axis.c_str());
    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - TLine
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale - TLine
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    LogScale(c, log_axis.c_str());

    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - SetRange - TLine
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();
    
    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale - SetRange - TLine
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    bool Legend,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    LogScale(c, log_axis.c_str());
    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

    if(Legend)  c.BuildLegend();
	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - ManualLegend
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - LogScale - ManualLegend 
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

    LogScale(c, log_axis.c_str());

	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - SetRange - ManualLegend
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;

    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - LogScale - SetRange - ManualLegend 
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;    
    
    LogScale(c, log_axis.c_str());
    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - LogScale - TLine - ManualLegend 
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);
    
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

    LogScale(c, log_axis.c_str());
    
	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - SetRange - TLine - ManualLegend
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);
    
	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - LogScale - SetRange - TLine - ManualLegend 
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> LegendCoordinates,
    const string & LegendTitle,
    const string & LegendTitlePosition,
    const string & LegendOptions,
    vector<string> LegendEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    TLegend * legend = MakeLegend(LegendCoordinates, LegendTitle.c_str(), LegendTitlePosition.c_str(), LegendOptions.c_str(), LegendEntry, &graph1, &graph2, &graph3, &graph4);
    legend -> Draw("Same");

    LogScale(c, log_axis.c_str());
    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);
    
	c.Print(destinationPNG.c_str(), "png");
    delete(legend);
};

//StampaMultigraph (4 different vector) - TBox
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale - TBox 
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

    LogScale(c, log_axis.c_str());

	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - SetRange - TBox
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);
    
    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale - SetRange - TBox 
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

    LogScale(c, log_axis.c_str());
    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - TLine - TBox
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale - TLine - TBox 
template<typename T1, typename T2, typename T3, typename T4>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

    LogScale(c, log_axis.c_str());

	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - SetRange - TLine - TBox
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);

    line.Draw();

    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

	c.Print(destinationPNG.c_str(), "png");
};

//StampaMultigraph (4 different vector) - LogScale - SetRange - TLine - TBox 
template<typename T1, typename T2, typename T3, typename T4, typename Q>
void MatriceMultigraph(
    const string & destinationPNG, 
    const string & graphName,
    const string & XaxisName,
    const string & YaxisName,
    const string & log_axis, 
    const string & set_axis,
    vector<Q> extremes,
    vector<double> LineCoordinates,
    int LineColor,
    int LineThickness,
    vector<double> PaveCoordinates,
    vector<string> PaveEntry,
    vector<T1*> graph1,
    vector<string> GraphicOption1,
    vector<T2*> graph2,
    vector<string> GraphicOption2,
    vector<T3*> graph3,
    vector<string> GraphicOption3,
    vector<T4*> graph4, 
    vector<string> GraphicOption4
)
{
    TLine line = MakeLine(LineCoordinates, LineColor, LineThickness);

    TCanvas c;
    MakeCanvas(c, graphName.c_str(), XaxisName.c_str(), YaxisName.c_str(), &graph1, GraphicOption1, &graph2, GraphicOption2, &graph3, GraphicOption3, &graph4, GraphicOption4);


    line.Draw();

    TPaveText t_box = MakeBox(PaveCoordinates, PaveEntry);
    t_box.Draw();

    LogScale(c, log_axis.c_str());
    SetRange_in_code(set_axis.c_str(), extremes, &graph1, &graph2, &graph3, &graph4);

	c.Print(destinationPNG.c_str(), "png");
};

#endif