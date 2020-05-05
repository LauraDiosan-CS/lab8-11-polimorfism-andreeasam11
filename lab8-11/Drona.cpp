#include "Drona.h"
#include <string>
#include "Utilites.h"
#include <vector>

Drona::Drona() {
	unitatiProduse = 0;
	numarRotoare = 0;
}

Drona::Drona(string numeProducator, string numeModel, int unitatiProduse, int numarRotare) {
	this->numeProducator = numeProducator;
	this->numeModel = numeModel;
	this->unitatiProduse = unitatiProduse;
	this->numarRotoare = numarRotare;
}

Drona::Drona(string linie, char delim) {
	vector<string> tokens = splitLine(linie, delim);
	numeProducator = tokens[1];
	numeModel = tokens[2];
	unitatiProduse = stoi(tokens[3]);
	numarRotoare = stoi(tokens[4]);
}

int Drona::getNumarRoatoare() {
	return numarRotoare;
}

void Drona::setNumarRotoare(int numar) {
	numarRotoare = numar;
}

Serie* Drona::clone() {
	Drona* newDrona = new Drona();
	newDrona->setNumeProducator(numeProducator);
	newDrona->setNumeModel(numeModel);
	newDrona->setUnitatiProduse(unitatiProduse);
	newDrona->setNumarRotoare(numarRotoare);
	return newDrona;
}

string Drona::toString() {
	return string("Drona: ") + numeProducator + " " + numeModel + " " + to_string(unitatiProduse) + " " + to_string(numarRotoare);
}

string Drona::toStringDelimiter(char delim) {
	return string("Drona") + delim + string(numeProducator) + delim + string(numeModel) + delim + to_string(unitatiProduse) + delim + to_string(numarRotoare);
}

Drona::~Drona() {
}