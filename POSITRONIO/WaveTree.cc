
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
#include <string>
#include "TTree.h"
#include "TFile.h"

using namespace std;

void WaveTree(){

	TFile *f = new TFile("prova.root", "RECREATE"); //Creo il file .root
	
	TTree *tree = new TTree("myTree", "A ROOT tree"); //Creo il TTree

	int num;
	int N[1030];
		
	char V[1024];
	string s;
	int num_linea;
	int num_record=0;
	string name;
	
	ifstream file_in("prova2.txt");
	
	while (!file_in.eof()){
		file_in >> s; //legge la prima stringa
		
	if (s == "Record"){
		num_linea=0;
		for(int i=0; i < 7; i++){
			file_in.getline(V, 1024);		
		}
		//num_linea++;
	 			
		num_record++;
		name = "wave0_out" + to_string(num_record);	
		//cout << num_record << endl;
		
	}
	
		
	else {
		num = stoi(s); //converte in numero la stringa
		N[num_linea]=num;
	 	num_linea++;
	 	//cout << num_linea << endl;
	 }
	 
	if(num_linea == 1030) {
		TBranch *b = tree->Branch(name.c_str(), &N, "array[1030]/I"); //Aggiungo il branch
		b->Fill();
	} 
		 
	 
}	


tree->Write();
f->Close();

}



