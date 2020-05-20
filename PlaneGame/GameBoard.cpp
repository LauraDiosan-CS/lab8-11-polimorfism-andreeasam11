#include "GameBoard.h"
#include <iostream>
#include <string>
using namespace std;


char** Tabla::getTabla() {
	char** y;
	y = new char* [10];
	for (int i = 0; i < 10; i++) {
		y[i] = new char[10];
		for (int j = 0; j < 10; j++)
			y[i][j] = this->tabla[i][j];
	}
	return y;
}

void Tabla::add(Avion v) {
	char beginning[4] = { ' ' };
	for (int i = 0; i < strlen(v.getBeginning()); i++)
		beginning[i] = v.getBeginning()[i];
	char ending[4] = { ' ' };
	for (int i = 0; i < strlen(v.getEnd()); i++)
		ending[i] = v.getEnd()[i];
	int c1 = beginning[0] - 65;
	int c2 = ending[0] - 65;
	int l1;
	if (beginning[1] == '1' and beginning[2] == '0')
		l1 = 9;
	else
		l1 = beginning[1] - 49;
	int l2;
	if (ending[1] == '1' and ending[2] == '0')
		l2 = 9;
	else
		l2 = ending[1] - 49;
	if (l1 == l2 and l1 - 2 <= 9 and l1 + 2 <= 9)
	{
		if (c1 < c2 and c2 - c1 == 3)
		{
			tabla[l1][c1] = '*';
			for (int i = l1 - 2; i <= l1 + 2; i++)
				tabla[i][c1 + 1] = '#';
			tabla[l1][c1 + 2] = '#';
			for (int i = l1 - 1; i <= l1 + 1; i++)
				tabla[i][c2] = '#';

		}
		else if (c1 > c2 and c1 - c2 == 3)
		{
			tabla[l1][c1] = '*';
			for (int i = l1 - 2; i <= l1 + 2; i++)
				tabla[i][c1 - 1] = '#';
			tabla[l1][c1 - 2] = '#';
			for (int i = l1 - 1; i <= l1 + 1; i++)
				tabla[i][c2] = '#';

		}
	}
	if (c1 == c2 and c1 - 2 <= 9 and c1 + 2 <= 9) {
		if (l1 < l2 and l2 - l1 == 3)
		{
			tabla[l1][c1] = '*';
			for (int i = c1 - 2; i <= c1 + 2; i++)
				tabla[l1 + 1][i] = '#';
			tabla[l1 + 2][c1] = '#';
			for (int i = c1 - 1; i <= c1 + 1; i++)
				tabla[l2][i] = '#';

		}
		else if (l1 > l2 and l1 - l2 == 3)
		{
			tabla[l1][c1] = '*';
			for (int i = c1 - 2; i <= c1 + 2; i++)
				tabla[l1 - 1][i] = '#';
			tabla[l1 - 2][c1] = '#';
			for (int i = c1 - 1; i <= c1 + 1; i++)
				tabla[l2][i] = '#';

		}
	}
}