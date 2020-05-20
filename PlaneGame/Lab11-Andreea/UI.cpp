#include "UI.h"
#include <windows.h>


void UI::printMenu() {
	cout << endl;
	cout << "Menu:" << endl;
	cout << "\t 1.Add" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "Choose option: ";
}

void UI::run() {
	int option;
	bool works = true;
	char** table = serv.getTabla();
	showTable(table);;
	while (works != false)
	{
		printMenu();
		cin >> option;
		switch (option)
		{
		case 1: {
			add();
			break;
		}
		case 0: {
			works = false;
			break;
		}
		default: {
			cout << "There is no such option." << endl;
		}
		}
	}
}

void UI::showTable(char** table) {
	int x = 1;
	char y = 'A';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "   | ";
	for (int j = 0; j < 10; j++)
	{
		cout << y << " | ";
		y += 1;
	}
	cout << endl;
	cout << "--------------------------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		if (x == 10)
			cout << x << " | ";
		else
			cout << " " << x << " | ";
		x++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int j = 0; j < 10; j++)
			cout << table[i][j] << " | ";
		cout << endl;
		cout << "--------------------------------------------" << endl;
	}
}

void UI::add() {
	char* begin = new char[4];
	cout << "Head: ";
	cin >> begin;
	char* end = new char[4];
	cout << "End: ";
	cin >> end;
	serv.addAvion(begin, end);
	char** x = serv.getTabla();
	showTable(x);
}