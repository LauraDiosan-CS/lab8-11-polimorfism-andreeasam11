#pragma once
#include "Serie.h"
#include <string>
#include <vector>

using namespace std;

class Telefon : public Serie {
	private:
		vector<string> listaOperatoriGSMCompatibili;
	public:
		Telefon();
		Telefon(string,string, int, vector<string>);
		Telefon(string, char);
		void setListaOperatoriGSM(vector<string> lista);
		vector<string> getListaOperatoriGSM();
		Serie* clone();
		string toString();
		string toStringDelimiter(char);
		~Telefon();
};