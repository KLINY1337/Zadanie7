#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << "������������ ������ �7 ����-13-21 ���������� �.�. ������� 23" << endl << endl;
	cout << "�������� ����� �������:\n1) ��������� �������� ����������� ���������\n0) ��������� ���������\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 0);

	system("cls");

	switch (choice1) {

	case 1: {
		cout << "������� ��������� � ���������� �����: ";
		string expression;
		cin.ignore(32767, '\n');
		getline(cin, expression);
		cout << "�������� ���������: " << solve_prefix(expression)<<"\n\n";
		break; }

	case 0:
		return 0;
	}
	main();
}