#ifndef moraRoot_h
#define moraRoot_h

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <limits>

#include "TH1F.h"
#include "TF1.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TFile.h"

#define nan(T) std::numeric_limits<T>::quiet_NaN()

using namespace std;

struct ScientificNotation {
    double n;
    int exp;
};

ScientificNotation Exponential(
    double n
)
{
    ScientificNotation a; 
    int i = 0;

    if (n < 1) {
        while (n < 1) {
            n *= 10;
            i--;
        }
        a.n = n;
        a.exp = i;
    } else if (n >= 10) { 
        while (n >= 10) {
            n /= 10;
            i++;
        }
        a.n = n;
        a.exp = i;
    } else {
        a.n = n;
        a.exp = 0;
    }

    return a;
}

double mean(
    vector<double> data
)
{
    double sum = 0;
    for(auto d : data)  sum += d;
    return sum / data.size();
};

template<typename T>
T Min (const vector<T> & v)
{
    T min = v.at (0);
    for (T x : v)
      if (x < min)  min = x;
    return min;
}

template<typename T>
T Max (const vector<T> & v)
{
    T max = v.at (0) ;
    for (T x : v)
      if (x > max)  max = x;
    return max;
}

template<typename T>
T  import_Tobject (
    const string & fileNameROOT, 
    const string & ObjectName
)
{
    TFile file(fileNameROOT.c_str());
    if (file.IsZombie()) {
        cerr << "\nErrore nell'aprire il file ROOT\n" << endl;
    }

    T *temp = dynamic_cast<T*>(file.Get(ObjectName.c_str()));
    if (!temp) {
        cerr << "\nErrore nel trovare l'oggetto" << ObjectName.c_str() << "\n" << endl;
        file.Close();
    }
    T obj = *static_cast<T*>(temp->Clone(ObjectName.c_str()));

    file.Close();

    return obj;
};

template<typename T, typename Q>
T FillHist(  
	vector<Q> data, 
	int nbin,
	const string & histoName, 
    bool Normalization = true //if true the histogram'll be normalized
)
{
	Q min = Min(data);
    Q max = Max(data);

	T h(histoName.c_str(), histoName.c_str(), nbin, min, max);
    
	for(double d : data)	h.Fill(d);
	
    if(Normalization){
        Q num = 0.;
    	Q den = 0.;

	    for(int i = 0; i < nbin + 1; i++){
		    num = h.GetBinContent(i);
		    den = h.GetBinWidth(i);
		    h.SetBinContent(i, num / (data.size() * den));
    	}

	    return h;
    }
    else    return h;
};

template<typename T>
void fit(
    T *point,
    TF1 *function,
    int n_parameters,
    const string & Option,
    int precision,
    double min = nan(double),
    double max = nan(double),
    bool covMat = true // if true-->print covariance matrix
)
{
    TFitResultPtr fit_result;
    if(isnan(min) && isnan(max))    fit_result = point -> Fit(function, Option.c_str());

    else    fit_result = point -> Fit(function, Option.c_str(), "", min, max);

    cout.precision(precision);
	cout << "\n\nRisultato del fit:\t" << fit_result -> IsValid();

    cout << "\n\n";
    for(int i = 0; i < n_parameters; i++)   cout << "\npar " << i << ":\t" << function -> GetParameter(i) << " +- " << function -> GetParError(i);

	cout << "\n\nNumero di gradi di liberta':\t" << fit_result -> Ndf();
	cout << "\nChi 2:\t" << fit_result -> Chi2();
	cout << "\nProbabilita':\t" <<fit_result->Prob() << "\t\t" << (fit_result -> Prob()) * 100 << "%\n\n";

	if(covMat)    fit_result -> PrintCovMatrix(cout);
};

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
)
{
    TCanvas c;

    point -> Draw(GraphicOption.c_str());
	point -> SetTitle(graphName.c_str());
	point -> GetXaxis() -> SetTitle(XaxisName.c_str());
    point -> GetYaxis() -> SetTitle(YaxisName.c_str());

    TFitResultPtr fit_result;
    if(isnan(min) && isnan(max))        fit_result = point -> Fit(function, "S");

    else    fit_result = point -> Fit(function, "S", "", min, max);
        
    if(isnan(PaveCoordinates.at(0))) c.Print(destinationPNG.c_str(), "png");

    else{
        TPaveText* text_box = new TPaveText(PaveCoordinates.at(0), PaveCoordinates.at(1), PaveCoordinates.at(2), PaveCoordinates.at(3), "NDC");

        ScientificNotation chi2 = Exponential(fit_result -> Chi2());
        vector<ScientificNotation> par_error;
        for(int i = 0; i < n_parameters; i++)   par_error.push_back(Exponential(function -> GetParError(i)));

        text_box -> SetFillColor(0);
        text_box -> SetTextAlign(12);
        text_box -> AddText(Form("Fit result:"));

        if(fabs(chi2.exp) < 3)    text_box -> AddText(Form("#chi^{2}/dof = %.3f/%d = %.3f", fit_result -> Chi2(), fit_result -> Ndf(), fit_result -> Chi2() / fit_result -> Ndf()));
        else    text_box -> AddText(Form("#chi^{2}/dof = %.2f*10^{%d}/%d = %.2f * 10^{%d}", chi2.n, chi2.exp, fit_result -> Ndf(), Exponential(fit_result -> Chi2() / fit_result -> Ndf()).n, Exponential(fit_result -> Chi2() / fit_result->Ndf()).exp));
        
        for (int i = 0; i < n_parameters; i++) {
            if (fabs(par_error.at(i).exp) < 3) {
                text_box->AddText(Form((PaveEntries.at(i) + " = %.3f #pm %.3f").c_str(), function -> GetParameter(i), function -> GetParError(i)));
            } 
            else{
                text_box->AddText(Form((PaveEntries.at(i) + " = (%.3f #pm %.3f) * 10^{%d}").c_str(), function -> GetParameter(i) * pow(10, -par_error.at(i).exp), par_error.at(i).n, par_error.at(i).exp));
            }
        }

        text_box -> Draw();
    
        c.Print(destinationPNG.c_str(), "png");

        delete(text_box);
    }
};

#endif
