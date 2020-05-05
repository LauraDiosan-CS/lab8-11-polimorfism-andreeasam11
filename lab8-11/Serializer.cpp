#include "Serializer.h"
#include "Utilites.h"

Serie* Serializer::serialize(string linie, char delim) {
	vector<string> tokens = splitLine(linie, delim);
	if (tokens[0] == "Telefon")
	{
		Serie* newTelefon = new Telefon(linie, delim);
		return newTelefon;
	}
	else
	{
		Serie* newDrona = new Drona(linie, delim);
		return newDrona;
	}
	
}