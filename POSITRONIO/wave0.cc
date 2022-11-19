
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


using namespace std;


void wave0() {
	
	char V[1024];
	string s;
	int num_linea=0;
	int num_record=0;
	string nuovonome;
	
	ifstream file_in("wave0.txt");
	
	while (!file_in.eof()){
		file_in >> s; //legge la prima stringa
		if (s == "Record"){
			num_linea=0;
			for(int i=0; i < 7; i++){
				file_in.getline(V, 1024);		
			}
			
			num_linea++;
			num_record++;
		}
		
		else {
			nuovonome = "wave_out" + to_string(num_record) + ".txt";
			ofstream file_out (nuovonome, fstream::app); //RICORDARSI DI BUTTARE I FILE GIÀ CREATI
			file_out << num_linea << " " << s << endl;
		 	num_linea++;
		 }
	}	
		
}



