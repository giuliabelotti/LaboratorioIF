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
void PMT1(){
double x[4] = {0.6617, 1.1732, 1.274, 1.3325}; //energie tabulate in ev
double dx[4] = {0, 0, 0, 0};

double y[4] = { 3.30522e1, 4.80070e1, 4.96180e1, 5.09615e1}; // Cs, Co1, Co2
double dy[4] = {0, 0, 0, 0};

auto c1 = new TCanvas("c1", "", 200, 10, 700, 500);

auto gr = new TGraphErrors(4, x, y, dx, dy);

TF1 *cal = new TF1 ("cal", "([0]*x)/(1+[1]*[2]*x)");
cal->SetParameters(71.836, 0.00487843, 134.563);

gr->SetTitle("Curva di Calibrazione PMT1; Energie Tabulate [MeV]; Energia misurata [u.a.]");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(20);
gr->Fit("cal", "", "",0, 2);
gr->Draw("AP");

}
