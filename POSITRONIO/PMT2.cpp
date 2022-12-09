#include "TMath.h"
#include "TFitResult.h"
#include "TMatrixD.h"
#include "TLorentzVector.h"
#include "TH1.h"
#include "TString.h"
#include "THStack.h"
#include "TClass.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLegend.h"
#include <iostream>
#include <fstream>

using namespace std;

void PMT2(){

double x[4] = {0.6617, 1.1732 , 1.274, 1.3325}; //energie tabulate in ev
double dx[4] = {0, 0, 0, 0};

double y[4] = { 1.466638e1, 2.38566e1,2.54168e1, 2.66191e1}; // Cs, Co1, Co2
double dy[4] = {4.14697e-3, 9.58111e-3, 2.308253-2, 9.85754e-3};

auto c1 = new TCanvas("c1", "", 200, 10, 700, 500);

auto gr = new TGraphErrors(4, x, y, dx, dy);

TF1 *cal = new TF1 ("cal", "([0]*x)/(1+[1]*[2]*x)");
cal->SetParameters(2.49052e+01, -5.60943e+01, -3.34386e-03);

gr->SetTitle("Curva di Calibrazione PMT2; Energie Tabulate [MeV]; Energia misurata [u.a.]");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(20);
gr->Fit("cal", "", "",0, 3);
gr->Draw("AP");

}
