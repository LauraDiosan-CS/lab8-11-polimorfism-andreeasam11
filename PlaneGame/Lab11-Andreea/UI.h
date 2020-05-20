#pragma once
#include "Service.h"
#include <iostream>
using namespace std;

class UI {
private:
	Service serv;
public:
	UI() {}
	~UI() {}
	void run();
	void printMenu();
	void showTable(char**);
	void add();
};