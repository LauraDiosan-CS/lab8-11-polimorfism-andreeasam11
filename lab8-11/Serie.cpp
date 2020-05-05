#include "Serie.h"

Serie::Serie() {
	unitatiProduse = 0;
}

Serie* Serie::clone() {
	Serie* newSerie = new Serie();
	newSerie->setUnitatiProduse(0);
	return newSerie;
}

string Serie::getNumeProducator() {
	return numeProducator;
}

string Serie::getNumeModel() {
	return numeModel;
}

int Serie::getUnitatiProduse() {
	return unitatiProduse;
}

void Serie::setNumeProducator(string newNumeProducator) {
	this->numeProducator = newNumeProducator;
}

void Serie::setNumeModel(string newModel) {
	numeModel = newModel;
}

void Serie::setUnitatiProduse(int newUnitatiProduse) {
	unitatiProduse = newUnitatiProduse;
}

string Serie::toString() {
	return "";
}

string Serie::toStringDelimiter(char delim) {
	return "";
}

Serie::~Serie() {
}