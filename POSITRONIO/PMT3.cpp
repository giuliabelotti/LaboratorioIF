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

void PMT3(){

double x[4] = {0.6617, 1.1732 , 1.274, 1.3325}; //energie tabulate in ev
double dx[4] = {0, 0, 0, 0};

double y[4] = { 4.35587e1, 7.98567e1, 8.58343e1, 9.15850e1}; // Cs, Co1, Co2
double dy[4] = {1.92362e-2, 6.33304e-2, 1.22493e-1, 6.0907e-2};

auto c1 = new TCanvas("c1", "", 200, 10, 700, 500);

auto gr = new TGraphErrors(4, x, y, dx, dy);

TF1 *cal = new TF1 ("cal", "([0]*x)/(1+[1]*[2]*x)");
cal->SetParameters(6.33036e+01, -2.40845e-01, 2.40845e-01);

gr->SetTitle("Curva di Calibrazione PMT3; Energie Tabulate [MeV]; Energia misurata [u.a.]");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(20);
gr->Fit("cal", "", "",0, 3);
gr->Draw("AP");

}
