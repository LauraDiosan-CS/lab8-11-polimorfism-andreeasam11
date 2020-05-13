#include "UI.h"
#include <iostream>
#include<string.h>
using namespace std;

void UI::addElem() {
	cout << "ce doresti sa adaugi? :"<<endl;
	cout << "	1. Phone" << endl;
	cout << "	2.Drone" << endl;
	try {
	string ras = "";
	cin >> ras;
	Serie* ser;
	if (ras == "1") {
		try {
			Phone p;
			cin >> p;
			ser = p.clone();
			s.addElem(ser);
			delete[]ser;
		}
		catch (PhoneException e)
		{
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
	}
	else {
		try {
			Drone p;
			cin >> p;
			ser = p.clone();
			s.addElem(ser);
			delete[]ser;
		}
		catch (SerieException e) {
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
	}
	}
	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}



void UI::findElem() {
	string prod;
	cout << "dati producatoul: ";
	cin >> prod;
	list<Serie*> l = s.findProducer(prod);
	list <Serie*>::iterator it;
	for (it = l.begin(); it != l.end(); ++it) {
		cout << (*it)->toString() << endl;
	}

}

void UI::delElem() {
	cout << "ce vrei sa stergi? :" << endl;
	cout << "	1. Phone" << endl;
	cout << "	2.Drone" << endl;
	try {
		string ras = "";
		cin >> ras;
		Serie* ser;
		if (ras == "1") {
			Phone p;
			cin >> p;
			ser = p.clone();
		}
		else {
			Drone p;
			cin >> p;
			ser = p.clone();
		}
		s.deleteElem(ser);
		cout << "seria a fost stearsa cu succes" << endl;
		delete[]ser;
	}
	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}


int UI::logIn() {
	cout << "Username: ";
	string user;
	cin >> user;
	cout << "Password: ";
	string pass;
	cin >> pass;
	return s.login(user, pass);
}

void UI::logOut() {
	s.logout();
}

void UI::showAll() {
	
	for (int i = 0; i < s.getSize(); i++)
	{
		cout << (*s.getItemFromPos(i)).toString() << endl;
	}
}

void UI::updateElem() {
	cout << "ce vrei sa modifici? :" << endl;
	cout << "	1. Phone" << endl;
	cout << "	2.Drone" << endl;
	try {
		string ras = "";
		cin >> ras;
		Serie* ser;
		Serie* nser;
		if (ras == "1") {
			Phone p;
			Phone np;
			cin >> p;
			ser = p.clone();
			cout << "modifica cu:" << endl;
			cin >> np;
			nser = np.clone();
		}
		else {
			Drone p,np;
			cin >> p;
			ser = p.clone();
			cout << "modifica cu:" << endl;
			cin >> np;
			nser = np.clone();
		}
		s.updateElem(ser,nser);
		delete[]ser;
		delete[]nser;
	}
		catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}

void UI::showUI()
{
	bool gata = false;
	bool stop = false;
	while (!gata) {
		cout << "Vrei sa te loghei? " << endl;
		cout << "		1.da" << endl;
		cout << "		2.nu" << endl;
		char r;
		cin >> r;
		if (r == '1') {
			if (logIn()) {

				while (s.logedIn() and !gata) {
					cout << endl;
					cout << "	1. Add " << endl;
					cout << "	2. Search by producer " << endl;
					cout << "	3. Delete " << endl;
					cout << "	4. Update " << endl;
					cout << "	5. Show " << endl;
					cout << "	6. Log out" << endl;
					cout << "	0. EXIT!" << endl;
					cout << "option: (give the number):  ";
					int opt;
					cin >> opt;
					cout << endl;
					cout << endl;
					switch (opt) {
						case 1: {addElem(); break; }
						case 2: {findElem(); break; }
						case 3: {delElem(); break; }
						case 4: {updateElem(); break; }
					case 5: {showAll(); break; }
					case 6: {logOut(); cout << "you have been logged outtttt" << endl; break; }
					case 0: {gata = true; cout << "BYE BYE..." << endl; }
					}
				}
			} else{ cout << "incorrect username or password" << endl; }
		}
			else {
				if (r == 'b') gata = true;
			}
		}
	}

UI::~UI()
{

}
