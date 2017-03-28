// Lab_1_OOP.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Triangle.h"

using namespace std;

Triangle** readTrianglesFromConsole(int num);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	int num = 0;
	cout << "������� ���������� �������������: ";
	cin >> num;

	Triangle** triangles = readTrianglesFromConsole(num);

	while (true) {
		int index = 0;

		cout << "������� ����� ������������: ";
		cin >> index;

		index--;

		if (index < 0 || index >= num) {
			cout << "������������ �����!";
			continue;
		}

		char *comand = new char[256]{ NULL };
		cout << "������� �������:\n "
			<< "1 - ��������� ����\n "
			<< "2 - ��������� ����\n "
			<< "3 - ����� ���������\n "
			<< "4 - ����� ��������, �� ������� ���������� ����� �������\n "
			<< "5 - �������� �����\n";
		cin >> comand;

		if (strcmp(comand, "1") == 0) {
			int number = 1;

			cout << "���������� ���: ";
			cin >> number;

			if (number == 0)
			{
				cout << "�������!";
			}

			triangles[index]->increaseAngle(number);

			cout << triangles[index]->angle;

		}

		if (strcmp(comand, "2") == 0) {
			int number = 1;

			cout << "���������� ���: ";
			cin >> number;

			if (number == 0)
			{
				cout << "�������!";
			}

			triangles[index]->decreaseAngle(number);

			cout << triangles[index]->angle;
		}

		if (strcmp(comand, "3") == 0) {
			double *bisectors = triangles[index]->getBisector();
			for (int i = 0; i < 3; i++)
			{
				
				cout << "������ ���������� " << i + 1 << " :" << bisectors[i] << endl;
			}

		}

		if (strcmp(comand, "4") == 0){
			double **side = triangles[index]->getSidesByBisector();
			for (int i = 0; i < 3; i++)
			{
				cout << "�������: " << i + 1 << endl;
				for (int j = 0; j < 2; j++)
				{
					cout << "����� �������: " << side[i][j] <<  endl;
				}
				
			}

		}

		if (strcmp(comand, "5") == 0){
			double *angles = triangles[index]->getAngles();
			for (int i = 0; i < 3; i++)
			{

				cout << "�������� ���� " << i + 1 << " : " << angles[i] << endl;
			}
		}

		_getch();
		return 0;
	}

	
}
Triangle** readTrianglesFromConsole(int num) {


	Triangle **result = new Triangle*[num];

	for (int i = 0; i < num; i++) {
		double side_1 = 0,
			side_2 = 0,
			angle = 30;

		cout << "������� ������ ������ �������: ";
		cin >> side_1;
		cout << "������� ������ ������ �������: ";
		cin >> side_2;
		cout << "������� ���� ����� ����(� ��������): ";
		cin >> angle;

		result[i] = new Triangle(side_1, side_2, angle);
	}

	return result;
}