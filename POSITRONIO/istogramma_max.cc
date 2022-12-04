
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
#include "TTree.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

void istogramma_max() {

	int nome;
	int num_linea;
	int Var1;
	int Var2;
	int maxV;
	string nuovonome;
	vector <float> Integrale;
	vector <int> Voltage;
	vector <int> y;
	vector <int> zero;
	vector<float>::iterator I_Iter;
	vector<int>::iterator V_Iter;
	vector<int>::iterator y_Iter;
	vector<int>::iterator zero_Iter;

	float integ = 0;
	int N = 40173;
	float mean = 0;
	float Ampiezza = 0;
	
		
   	//auto Canvas = new TCanvas();
  	
   	TFile *f = new TFile("wave_Co3.root", "RECREATE"); //Creo il file .root
	TTree *tree = new TTree("PMT3Co", "A ROOT tree"); //Creo il TTree
   	tree->Branch("Integrale", &integ, "integ/F"); //Aggiungo il branch
   	tree->Branch("Ampiezza", &Ampiezza, "Ampiezza/F"); //Aggiungo il branch	
   		
	for (nome = 1; nome <= N ; nome++){
		nuovonome = "wave2_out" + to_string(nome) + ".txt";
		ifstream file_in(nuovonome);
		
		while (!file_in.eof()){
			num_linea=0;
			file_in >> Var1 >> Var2; //leggo la seconda colonna
			Voltage.push_back(Var2); //inserisco la seconda colonna in un array
			num_linea++;
		}
			
		// cerchiamo la baseline 			
		V_Iter = Voltage.begin();
		for(; V_Iter <= Voltage.begin()+99; V_Iter++)	
		{ 
			zero.push_back(*V_Iter);
		}
		
		mean = accumulate(zero.begin(), zero.end(), 0.0)/zero.size(); //valore medio della baseline da sottrarre all'altezza dei trapezi
		
		//cout << "Baseline: " << mean << endl;
		
		/*
		zero_Iter = zero.begin();
		for(; zero_Iter != zero.end(); zero_Iter++)	
		{ 
			cout << " " << *zero_Iter;
		}
		cout << endl;
		*/
		
		maxV = *max_element(Voltage.begin(), Voltage.end()); //trovo il minimo dell'array
		//cout << "Valore minimo" << minV << endl;
		Ampiezza = maxV - mean;
		
		/*
		//riempio il vettore dal minimo in poi
		V_Iter = min_element(Voltage.begin(), Voltage.end());
		for (; V_Iter != Voltage.end(); V_Iter++)
		{
			y.push_back(*V_Iter);
		}
		*/
		
		//riempio il vettore dal minimo-100 al minimo+100
		V_Iter = max_element(Voltage.begin(), Voltage.end())-20;
		for (; V_Iter <= max_element(Voltage.begin(), Voltage.end())+20; V_Iter++)
		{
			y.push_back(*V_Iter);
		}
		
		/*
		y_Iter = y.begin();
		for(; y_Iter != y.end(); y_Iter++)	
		{ 
			cout << " " << *y_Iter;
		}
		cout << endl;
		*/
		
		Voltage.erase(Voltage.begin(), Voltage.end()); //svuoto la memoria di Voltage
		
		y_Iter = y.begin();
		integ = 0;
		for(; y_Iter != (y.end()-1); y_Iter++)
		{	
			integ += ((*y_Iter)-mean) * 1 + ((*(y_Iter+1) - *y_Iter) * 0.5);	
		}
		
		y.erase(y.begin(), y.end()); //svuoto la memoria di y
		zero.erase(zero.begin(), zero.end()); //svuoto la memoria di zero
		
		//Integrale.push_back(integ);
	    //cout << integ << endl;
	    	    
		tree->Fill();
	    		
	}

tree->Write();
tree->Print();
//tree->Draw("Integrale >> h(200, -1000e3, 100e3");
f->Close();

	
	
}


