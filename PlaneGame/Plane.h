#pragma once
#include <iostream>
using namespace std;

class Avion {
private:
	char beginning[4];
	char end[4];
public:
	Avion();
	Avion(char*, char*);
	~Avion();
	char* getBeginning();
	char* getEnd();
	void setBeginning(char*);
	void setEnd(char*);
};