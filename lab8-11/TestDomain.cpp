#include "TestsDomain.h"
#include <assert.h>
#include <vector>
#include "Telefon.h"
#include "Drona.h"
#include <iostream>
#include <string>

using namespace std;

void testTelefon() {
	vector<string> t1;
	t1.push_back("rx100");
	t1.push_back("rga234");
	Telefon telefon("Samsung", "GalaxyS10", 200, t1);
	assert(telefon.getNumeModel() == "GalaxyS10");
	assert(telefon.getNumeProducator() == "Samsung");
	assert(telefon.getUnitatiProduse() == 200);
	cout << "Telefon tests!" << endl;
}

void testDrona() {
	Drona drona("Samsung", "DronaS10", 100, 30);
	assert(drona.getNumeProducator() == "Samsung");
	assert(drona.getNumeModel() == "DronaS10");
	assert(drona.getUnitatiProduse() == 100);
	assert(drona.getNumarRoatoare() == 30);
	cout << "Drone tests!" << endl;
}