#include "Plane.h"

Avion::Avion() {
}

Avion::Avion(char* begin, char* ending) {
	strcpy_s(beginning, strlen(begin) + 1, begin);
	strcpy_s(end, strlen(ending) + 1, ending);
}

char* Avion::getBeginning() {
	return this->beginning;
}

char* Avion::getEnd() {
	return this->end;
}

void Avion::setBeginning(char* newB) {
	strcpy_s(beginning, strlen(newB) + 1, newB);
}

void Avion::setEnd(char* newE) {
	strcpy_s(end, strlen(newE) + 1, newE);
}

Avion::~Avion() {
}