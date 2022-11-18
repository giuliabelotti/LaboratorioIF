
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



void grafico1(){

	TCanvas *c1 = new TCanvas("c1","",200,10,700,500);
	c1->SetGrid();
 	TGraph *gr = new TGraph("PlotData.txt");
 	
	gr->GetXaxis()->SetTitle("Voltage [V]");
	gr->GetYaxis()->SetTitle("Entries");
	gr->SetTitle("Grafico prima acquisizione");
	gr->SetMarkerStyle(2);
	gr->SetMarkerColor(4);
	gr->Draw("AP");
	
	return  c1;

}

