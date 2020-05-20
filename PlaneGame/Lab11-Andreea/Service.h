#pragma once
#include "GameBoard.h"

class Service {
private:
	Tabla playerTabla;
	Tabla computerTabla;
public:
	Service() {}
	~Service() {}
	char** getTabla();
	void addAvion(char[4], char[4]);
};