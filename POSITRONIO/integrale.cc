
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
#include <vector>

using namespace std;

void integrale() {
	
	ifstream file_in("PlotData2.txt");
	
	int tmp;
	vector <int> Voltage;
	vector<int>::iterator V_Iter;
	int num_linea;
	int minV;
	vector <int> y;
	float integrale = 0;
	
	while (!file_in.eof()){
		
		num_linea=0;
		file_in >> tmp >> tmp; //leggo la seconda colonna
		Voltage.push_back(tmp);//inserisco la seconda colonna in un array
		num_linea++;
		
		}
	/*			
	cout << "The vector c1 contains elements:";
    V_Iter = Voltage.begin();
    for (; V_Iter != Voltage.end(); V_Iter++)
    {
        cout << " " << *V_Iter;
    }
    cout << endl;

	*/
	
	minV = *min_element(Voltage.begin(), Voltage.end()); //trovo ilminimo dell'array
    cout << "min element is: " << minV << endl;
    
    int indice = min_element(Voltage.begin(), Voltage.end()) - Voltage.begin();
    //cout << "indice " << indice << endl;
    
   	V_Iter = min_element(Voltage.begin(), Voltage.end());
	for (; V_Iter != Voltage.end(); V_Iter++)
	{
		y.push_back(*V_Iter);
		
	}
	
	/*
	cout << y.size() << endl;
	
	cout << "The vector y contains elements:";
    V_Iter = y.begin();
    for (; V_Iter != y.end(); V_Iter++)
    {
        cout << " " << *V_Iter;
    }
    cout << endl;
	*/
	
	V_Iter = y.begin();
	for(; V_Iter != (y.end()-1); V_Iter++)
	{
		integrale += (*V_Iter) * 1 + ((*(V_Iter+1) -*V_Iter) * 0.5);
		
	}
    
	cout << "Integrale: " << integrale << endl; 
       
}


