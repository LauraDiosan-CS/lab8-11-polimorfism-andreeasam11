#pragma once
#include <string>
#include "Service.h"

using namespace std;

class UI {
private:
	Service service;
	User u;
	bool login();
	void addDrona();
	void addTelefon();
	void searchProducator();
	void showAll();
	void setRepo();
	void showMenu();
	void logout();
public:
	UI();
	UI(Service&);
	void run();
	~UI();
};
