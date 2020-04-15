#include "Phone.h"
#include <string.h>
#include <sstream>

Phone::Phone() {
	this->producer = NULL;
	this->model = NULL;
	this->units = 0;
	this->operators = {};
}

Phone::Phone(const char* producer, const char* model, int units, vector<Phone>operators) {
	if (producer) {
		this->producer = new char[strlen(producer) + 1];
		strcpy_s(this->producer, strlen(producer) + 1, producer);
	}
	this->units = units;
	if (model) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	this->operators = operators;
}

Phone::Phone(const Phone& e) {
	if (e.producer) {
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	this->units = e.units;
	if (e.model) {
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}
	this->operators = e.operators;
}

Phone::Phone(string line) {
	std::istringstream iss(line);
	string tok1, tok2, tok3, tok4;
	iss >> tok1 >> tok2 >> tok3;
	this->producer = new char[tok1.length() + 1];
	strcpy_s(this->producer, tok1.length() + 1, tok1.c_str());
	this->model = new char[tok2.length() + 1];
	strcpy_s(this->model, tok2.length() + 1, tok2.c_str());
	this->units = stoi(tok3);
	this
}

char* Phone::getProducer() {
	return this->producer;
}

char* Phone::getModel() {
	return this->model;
}

int Phone::getUnits() {
	return this->units;
}

void Phone::setProducer(const char* producer) {
	if (this->producer) {
		delete[] this->producer;
	}
	this->producer = new char[strlen(producer) + 1];
	strcpy_s(this->producer, strlen(producer) + 1, producer);
}

void Phone::setModel(const char* model) {
	if (this->model) {
		delete[] this->model;
	}
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void Phone::setUnits(int units) {
	this->units = units;
}

Phone::~Phone() {
	if (this->producer) delete[] this->producer;
	if (this->model) delete[] this->model;
}

Phone& Phone::operator =(const Phone& e) {
	if (this == &e) return *this; //in case of self assignment
	if (e.producer) {
		if (this->producer)delete[]this->producer;
		this->producer = new char[strlen(e.producer) + 1];
		strcpy_s(this->producer, strlen(e.producer) + 1, e.producer);
	}
	if (e.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(e.model) + 1];
		strcpy_s(this->model, strlen(e.model) + 1, e.model);
	}
	this->units = e.units;
	return *this;
}

bool Phone::operator==(const Phone& e) {
	if (this->producer and e.producer and this->model and e.model) {
		return (strcmp(this->producer, e.producer) == 0) and (strcmp(this->model, e.model) == 0) and (this->units == e.units);
	}
	return false;
}

bool Phone::operator<(const Phone& e) {
	return (strcmp(this->producer, e.producer) < 0);
}

void Phone::fromString(std::string info) {
	int i1 = info.length() - 1, i2 = info.length() - 1;
	while (info[i1] != ',')
		i1--;
	this->setUnits(stod(info.substr(i1 + 1, i2 - i1 + 1)));
	i1--;
	i2 = i1;
	while (info[i1] != ',')
		i1--;
	this->setModel(info.substr(i1 + 1, i2 - i1).c_str());
	i1--;
	i2 = i1;
	while (info[i1] != ',')
		i1--;
	this->setProducer(info.substr(i1 + 1, i2 - i1).c_str());
	//i2 = i1;
	//i2--;
	//i1 = 0;
}
ostream& operator<<(ostream& os, Phone e) {
	os << e.producer << " " << e.model << " " << e.units << endl;
	return os;
}

istream& operator >>(istream& is, Phone& e) {
	cout << "Give the producer: ";
	char* producer = new char[10];
	is >> producer;
	cout << "Give the number: ";
	char* model = new char[10];
	is >> model;
	cout << "Give the units: ";
	int units;
	is >> units;
	int ok = 0;

	e.setProducer(producer);
	e.setModel(model);
	e.setUnits(units);
	delete[] producer;
	delete[] model;
	return is;
}