#include "Phone.h"
#include <string.h>
#include <sstream>

Phone::Phone():Serie(){
	this->operators = {};
}

Phone::Phone(const char* producer, const char* model, int units, vector<string>operators):Serie(producer,model, units){
	
	this->operators = operators;
}

Phone::Phone(const Phone& e):Serie(e) {
	
	this->operators = e.operators;
}

Phone::Phone(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	this->producer = new char[tokens[0].length() + 1];
	strcpy_s(this->producer, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[1].length() + 1];
	strcpy_s(this->model, tokens[1].length() + 1, tokens[1].c_str());

	units = stoi(tokens[2]);
	if (tokens[3] != "$$")
	{
		vector <string> tok = splitLine(tokens[3], '-');
		for (int i = 0; i < tok.size(); i++) {
			
			this->operators.push_back(tok[i]);
		}
	}
}


Serie* Phone::clone() {
	Phone* newSerie = new Phone();
	newSerie->setProducer(this->producer);
	newSerie->setModel(this->model);
	newSerie->setUnits(this->units);
	newSerie->setOperators(this->operators);
	return newSerie;
}
vector<string> Phone::getOperators() {
	return this->operators;
}


void Phone::setOperators(vector<string> operators) {
	this->operators =operators;
}
Phone::~Phone() {
	if (this->producer) {
		delete[] this->producer;
		this->producer = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}

Phone& Phone::operator =(const Phone& e) {
	if (this == &e) return *this; 
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
	this->operators = e.operators; 
	return *this;
}


string Phone::toString() {
	string x, y,s;
	x = this->producer;
	y = this->model;
	if (this->operators.size() == 0) { s = "$$"; }
	else {
		s = this->operators[0];
		for (int i = 1; i < this->operators.size(); i++)
		{
			s = s + "-" + this->operators[i];
		}
	}
	return  x + " " + y + " " + to_string(this->units)+" "+s;
}

string Phone::toStringDelimiter(char delim) {
	string x, y,s;
	x = this->producer;
	y = this->model;
	if (this->operators.size() == 0) { s = "$$";}
	else {
		s = this->operators[0];
		for (int i = 1; i < this->operators.size(); i++)
		{
			s = s + "-" + this->operators[i];
		}
	}
	return  x + delim + y + delim + to_string(this->units) + delim + s;
}

ostream& operator<<(ostream& os, Phone e) {
	os << e.producer << " " << e.model << " " << e.units << " "; 
	for (int i = 0; i < e.operators.size() - 1; i++)
		os << e.operators[i] << "-";
	os << e.operators[e.operators.size() - 1] << endl;
	return os;

}

istream& operator >>(istream& is, Phone& e) {
	cout << "Give the producer: ";
	char* producer = new char[10];
	is >> producer;
	cout << "Give the model: ";
	char* model = new char[10];
	is >> model;
	cout << "Give the units: ";
	int units;
	is >> units;
	int ok = 0;
	vector<string> operators = {};
	cout << "the operators:" << endl;
	cout << "how many operators will you enter? ";
	int n=0;
	is >> n;
	char* op = new char[10];
	
	int i = 0;
	while (i < n)
	{
		cout << "enter operator no " << i + 1;
		is >> op;
		operators.push_back(op);
		i++;
	}
	e.setProducer(producer);
	e.setModel(model);
	e.setUnits(units);
	e.setOperators(operators);
	delete[] producer;
	delete[] model;
	return is;
}