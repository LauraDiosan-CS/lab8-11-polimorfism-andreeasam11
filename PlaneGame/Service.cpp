#include "Service.h"
#include "Plane.h"

char** Service::getTabla() {
	char** x = playerTabla.getTabla();
	return x;
}

void Service::addAvion(char beginning[4], char end[4]) {
	char* b = new char[4];
	for (int i = 0; i < 4; i++)
		b[i] = beginning[i];
	char* e = new char[4];
	for (int i = 0; i < 4; i++)
		e[i] = end[i];
	Avion v(b, e);
	delete[] b, e;
	playerTabla.add(v);
}