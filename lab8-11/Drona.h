#pragma once
#include <string>
#include "Serie.h"

class Drona : public Serie {
	private:
		int numarRotoare;
	public:
		Drona();
		Drona(string, string, int, int);
		Drona(string, char);
		void setNumarRotoare(int);
		int getNumarRoatoare();
		Serie* clone();
		string toString();
		string toStringDelimiter(char);
		~Drona();
};