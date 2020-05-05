#include "Telefon.h"
#include "Utilites.h"
#include <string>

Telefon::Telefon() {
	unitatiProduse = 0;
}

Telefon::Telefon(string numeProducator,string numeModel, int unitatiProduse, vector<string> listaOperatoriGSMCOmpatibili) {
	this->numeProducator = numeProducator;
	this->numeModel = numeModel;
	this->unitatiProduse = unitatiProduse;
	this->listaOperatoriGSMCompatibili.swap(listaOperatoriGSMCOmpatibili);
}

Telefon::Telefon(string linie, char delim) {
	vector<string> tokens = splitLine(linie, delim);
	vector<string> listaGSM;
	vector<int>::iterator ptr;
	for (int i=1;i<tokens.size();i++)
	{
		if (i == 1)
			numeProducator = tokens[1];
		else
			if (i == 2)
				numeModel = tokens[2];
			else
				if (i == 3)
					unitatiProduse = stoi(tokens[3]);
				else
					listaGSM.push_back(tokens[i]);
	}
	listaOperatoriGSMCompatibili = listaGSM;
	
}

vector<string> Telefon::getListaOperatoriGSM() {
	return listaOperatoriGSMCompatibili;
}

void Telefon::setListaOperatoriGSM(vector<string> lista) {
	listaOperatoriGSMCompatibili = lista;
}

Serie* Telefon::clone() {
	Telefon* newTelefon = new Telefon();
	newTelefon->setNumeProducator(numeProducator);
	newTelefon->setNumeModel(numeModel);
	newTelefon->setUnitatiProduse(unitatiProduse);
	newTelefon->setListaOperatoriGSM(listaOperatoriGSMCompatibili);
	return newTelefon;
	
}

string Telefon::toString() {
	string listaGSM;
	for (string crt : listaOperatoriGSMCompatibili) {
		listaGSM += crt + " ";
	}
	return string("Telefon: ") + numeProducator + " " + numeModel + " " + to_string(unitatiProduse) + " " + listaGSM;
}

string Telefon::toStringDelimiter(char delim) {
	string listaGSM;
	for (string crt : listaOperatoriGSMCompatibili) {
		listaGSM += delim + crt;
	}
	return string("Telefon") + delim + string(numeProducator) + delim + string(numeModel) + delim + to_string(unitatiProduse) + listaGSM;
}

Telefon::~Telefon() {
}
