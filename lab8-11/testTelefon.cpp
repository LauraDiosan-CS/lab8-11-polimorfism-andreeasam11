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
	assert(strcmp(telefon.getNumeModel(), "GalaxyS10") == 0);
	assert(strcmp(telefon.getNumeProducator(), "Samsung") == 0);
	assert(telefon.getUnitatiProduse() == 200);
	cout << "Telefon tests!" << endl;
}

void testDrona() {
	Drona drona("Samsung", "DronaS10", 100, 30);
	assert(strcmp(drona.getNumeProducator(), "Samsung") == 0);
	assert(strcmp(drona.getNumeModel(), "DronaS10") == 0);
	assert(drona.getUnitatiProduse() == 100);
	assert(drona.getNumarRoatoare() == 30);
	cout << "Drones tests!";
}