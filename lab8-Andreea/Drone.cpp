#include "Drone.h"
#include<string.h>
#include<sstream>

Drone::Drone() {
	
	this->rotors = 0;
}
Drone::Drone(const char* producer, const char* model, int units, int rotors):Serie(producer, model, units) {
	
	this->rotors = rotors;
}

Drone::Drone(const Drone&e):Serie(e) {
	
	this->rotors = e.rotors;
}

Drone::Drone(string line,char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producer= new char[tokens[0].length() + 1];
	strcpy_s(this->producer, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[1].length() + 1];
	strcpy_s(this->model, tokens[1].length() + 1, tokens[1].c_str());
	units = stoi(tokens[2]);
	rotors = stoi(tokens[3]);
}


Drone::~Drone() {
	if (this->producer) {
		delete[] this->producer;
		this->producer = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}
Serie* Drone::clone() {
	Drone* newSerie = new Drone();
	newSerie->setProducer(this->producer);
	newSerie->setModel(this->model);
	newSerie->setUnits(this->units);
	newSerie->setRotors(this->rotors);
	return newSerie;
}

int Drone::getRotors() {
	return this->rotors;
}

void Drone::setRotors(int rotors) {
	this->rotors = rotors;
}

Drone& Drone::operator =(const Drone& e) {
	if (this == &e) return *this;
	if (e.producer) {
		if (this->producer) delete[] this->producer;
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	if (e.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}
	this->units = e.units;
	this->rotors = e.rotors;
}

string Drone::toString() {
	string x, y;
	x = this->producer;
	y = this->model;
	return  x+ " " + y + " " + to_string(this->units) + " " + to_string(this->rotors);
}
string Drone::toStringDelimiter(char delim) {
	string x, y;
	x = this->producer;
	y = this->model;
	return  x + delim + y + delim + to_string(this->units) + delim + to_string(this->rotors);
}


ostream& operator<<(ostream& os, Drone e) {
	os << e.producer << " " << e.model << " " << e.units << " "<<e.rotors << endl;
	return os;
}

istream& operator>>(istream& is, Drone& e) {
	cout << "Give the producer: ";
	char* producer = new char[10];
	is >> producer;
	cout << "Give the model: ";
	char* model = new char[10];
	is >> model;
	cout << "Give the units: ";
	int units;
	is >> units;
	cout << "Give the rotors: ";
	int rotors;
	is >> rotors;
	e.setProducer(producer);
	e.setModel(model);
	e.setUnits(units);
	e.setRotors(rotors);
	delete[] producer;
	delete[] model;
	return is;
}