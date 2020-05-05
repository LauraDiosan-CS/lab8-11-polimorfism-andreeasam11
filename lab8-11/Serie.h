#pragma once
#include <string>
using namespace std;

class Serie {
protected:
	string numeProducator, numeModel;
	int unitatiProduse;
public:
	Serie();
	string getNumeProducator();
	string getNumeModel();
	int getUnitatiProduse();
	virtual Serie* clone();
	void setNumeProducator(string);
	void setNumeModel(string);
	void setUnitatiProduse(int);
	virtual string toString();
	virtual string toStringDelimiter(char);
	virtual ~Serie();
};