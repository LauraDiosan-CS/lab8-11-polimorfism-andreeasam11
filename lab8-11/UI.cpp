#include "UI.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

UI::UI() {
}

UI::UI(Service& s) {
	service = s;
}
void UI::showAll() {
	for (int i = 0;i < service.getAll().size();i++)
		cout << service.getAll()[i]->toString() << endl;
}

bool UI :: login() {
	string user, password;
	try {
		cout << "username: ";	cin >> user;
		cout << "password: ";	cin >> password;
		service.login(user, password);
		u.setPassword(password);
		u.setUserName(user);
		cout << "Ai intrat cu succes!" << endl;
		return true;
	}
	catch (LogginException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		login();
	}
	catch (...) {
		cout << "other exception: " << endl;
		login();
	}
}

void UI::addDrona() {
	try {
		string numeProducator, numeModel;
		int unitatiProduse, numarRotoare;
		cout << "Nume producator: ";	cin >> numeProducator;
		cout << "Nume model: ";	cin >> numeModel;
		cout << "Unitati produse: ";	cin >> unitatiProduse;
		cout << "Numar rotoare: ";	cin >> numarRotoare;
		service.addDrona(numeProducator, numeModel, unitatiProduse, numarRotoare);
		cout << "Drona adaugata" << endl;
	}
	catch (DomainException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
	}
	catch (...) {
		cout << "other exception: " << endl;
	}
}

void UI::setRepo() {
	string linie;
	try {
		cout << "RepoCSV sau CustomFileRepo?: ";cin >> linie;
		service.changeRepo(linie);
	}
	catch (RepositoryException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
		setRepo();
	}
	catch (...) {
		cout << "other exception: " << endl;
		setRepo();
	}
}

void UI::logout() {
	service.logout(u.getUserName(), u.getPassword());
}

void UI::addTelefon() {
	string numeProducator, numeModel;
	int unitatiProduse, n;
	vector<string> listaGSM;
	try {
		cout << "Nume producator: ";	cin >> numeProducator;
		cout << "Nume model: ";	cin >> numeModel;
		cout << "Unitati produse: ";	cin >> unitatiProduse;
		cout << "Cati operatori gsm are telefonul?: ";	cin >> n;
		cout << "Introduceti operatorii: " << endl;
		for (int i = 1;i <= n;i++)
		{
			string linie;
			cin >> linie;
			listaGSM.push_back(linie);
		}
		service.addTelefon(numeProducator, numeModel, unitatiProduse, listaGSM);
		cout << "Telefon adaugat!" << endl;
	}
	catch (DomainException & exc) {
		cout << "exception: " << exc.getMessage() << endl;
	}
	catch (...) {
		cout << "other exception: " << endl;
	}
}

void UI::searchProducator() {
	string linie;
	cout << "Ce producator cautati: ";	cin >> linie;
	vector<Serie*> final= service.cautareProducator(linie);
	for (int i = 0;i < final.size();i++)
		cout << final[i]->toString() << endl;
}

void UI::showMenu() {
	cout << "1. Adaugare telefon" << endl;
	cout << "2. Adaugare drona" << endl;
	cout << "3. Cautare dupa numar producator" << endl;
	cout << "0. Logout" << endl;
}

void UI::run() {
	setRepo();
	login();
	bool gata = true;
	showAll();
	while (gata)
	{
		int opt;
		showMenu();
		cout << "Dati optiunea: ";	cin >> opt;	cout << endl;
		switch (opt)
		{
		case 0: {service.logout(u.getUserName(), u.getPassword());gata = false;break;}
		case 1: {addTelefon();break;}
		case 2: {addDrona();break;}
		case 3: {searchProducator();break;}
		}
	}
}

UI::~UI() {
}
