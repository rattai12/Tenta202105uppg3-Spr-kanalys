#include <iostream>
#include "ordlista.h"
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

vector <string> ordlista;
double tot_words_eng = 0;
double totWordSwe = 0;
void svenska() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

}


double decideLanguage(double antal_ord) {
	double procent;
	if (antal_ord == 0) {
		return 0;
	}
	else {
		procent = (antal_ord / size(ordlista) * 100);

	}
	return procent;
}

void clearList() { // funktion to clear lsit
	ordlista.clear();
}

void readFile() {
	string filnamn;
	string line;
	string word;
	cout << "Ange vilken fil du vill läsa in: ";
	cin >> filnamn;

	while (true)
	{
		ifstream inFile(filnamn);
		while (getline(inFile, line)) {
			stringstream ss(line);
			while (ss >> word)
				ordlista.push_back(word);
		}
		break;
	}
	cout << "Totalt antal ord i texten är: " << size(ordlista) << endl;
}

void compareSwed(vector <string> ordlistSweComp) {
	int numWords_swe = 0;
	totWordSwe = 0;
	
	for (int i = 0; i < size(ord_sve); i++) {
		numWords_swe = 0;
		for (int j = 0; j < size(ordlistSweComp); j++) {
			if (ord_sve[i] == ordlistSweComp[j]){
				numWords_swe++;
				totWordSwe++;
				
				}
			else {
				continue;
			}
		}
		cout << setw(10)<< ord_sve[i] << setw(5) << numWords_swe << endl;
	}
	cout << "Antal svenska ord i texten är: " << totWordSwe << endl;
	cout << "Antal procent är: " << decideLanguage(totWordSwe) << "% " <<endl;
	


}

void compareEng(vector<string>ordlistSweComp) {
	int numWords_eng = 0;
	tot_words_eng = 0;

	for (int i = 0; i < size(ord_sve); i++) {
		numWords_eng = 0;
		for (int j = 0; j < size(ordlistSweComp); j++) {
			if (ord_eng[i] == ordlistSweComp[j]) {
				numWords_eng++;
				tot_words_eng++;
			}
			else {
				continue;
			}
		}
		cout << setw(10) << ord_eng[i] << setw(5) << numWords_eng << endl;
		
	}
	
	cout << "Antal engelska ord i texten är: " << tot_words_eng<<endl;
	cout << "Antal procent är: " << decideLanguage(tot_words_eng) << "% " <<endl;

}


void SwedOrdEng(double swedPercent, double engPercent) {

	if (swedPercent < 10 && engPercent < 10) {
		cout << "Det är för få ord för att avgöra språk av texten.." << endl;
	}
	else if (swedPercent > 10) {
		cout << "Språket är svenska" << endl;
	}
	else if (engPercent > 10) {
		cout << "Språket är engelska" << endl;
	}



}
int main() {

	bool run = true;

	while (run) {


		svenska();
		readFile();
		compareSwed(ordlista);
		compareEng(ordlista);
		SwedOrdEng(totWordSwe, tot_words_eng);
		clearList();
	}

}

/*

double calculatePercentage(double value, double total) {
	return (value / total) * 100;
}
*/