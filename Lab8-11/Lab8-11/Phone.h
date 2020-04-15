#pragma once
#include<iostream>
#include<string>
using namespace std;
#include <vector>
class Phone {
private:
	char* producer;
	char* model;
	int units;
	vector<Phone>operators;
public:
	Phone();
	Phone(const char*, const char*, int, vector<Phone>);
	Phone(const Phone&);
	Phone& operator= (const Phone&);
	Phone(string); //conversion

	char* getProducer();
	char* getModel();
	int getUnits();
	void setProducer(const char*);
	void setModel(const char*);
	void setUnits(int);

	bool operator ==(const Phone&);
	bool operator <(const Phone&);
	void fromString(std::string info);
	friend ostream& operator <<(ostream& os, Phone e);
	friend istream& operator >>(istream& is, Phone& e);

	~Phone();
};