// Lab_1_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Triangle.h"

using namespace std;

Triangle** readTrianglesFromConsole(int num);

int _tmain(int argc, _TCHAR* argv[])
{
	int num = 0;
	cout << "Input count of triangles: ";
	cin >> num;

	Triangle** triangles = readTrianglesFromConsole(num);

	while (true) {
		int index = 0;

		cout << "Input triangle's index: ";
		cin >> index;

		index--;

		if (index < 0 || index >= num) {
			cout << "Wrong index!";
			continue;
		}

		char *comand = new char[256]{ NULL };
		cout << "Input command: "
			<< "1 - Increase angle "
			<< "2 - Decrease angle "
			<< "3 - Calculate bisector "
			<< "4 - Calculate sides by bisector "
			<< "5 - Info about triangles\n";
		cin >> comand;

		if (strcmp(comand, "1") == 0) {
			int number = 1;

			cout << "Input numer of times ";
			cin >> number;

			if (number == 0)
			{
				cout << "Incorrect data!";
			}

			triangles[index]->increaseAngle(number);

			cout << triangles[index]->angle;

		}

		if (strcmp(comand, "2") == 0) {
			int number = 1;

			cout << "Input numer of times ";
			cin >> number;

			if (number == 0)
			{
				cout << "Incorrect data!";
			}

			triangles[index]->decreaseAngle(number);

			cout << triangles[index]->angle;
		}

		if (strcmp(comand, "3") == 0) {
			double *bisectors = triangles[index]->getBisector();
			for (int i = 0; i < 3; i++)
			{
				
				cout << "The lenght of bisector " << i + 1 << " :" << bisectors[i] << endl;
			}

		}

		if (strcmp(comand, "4") == 0){
			double **side = triangles[index]->getSidesByBisector();
			for (int i = 0; i < 3; i++)
			{
				cout << "Side: " << i + 1 << endl;
				for (int j = 0; j < 2; j++)
				{
					cout << "The lenght of sides (by bisector): " << side[i][j] <<  endl;
				}
				
			}

		}

		if (strcmp(comand, "5") == 0){
			double *angles = triangles[index]->getAngles();
			for (int i = 0; i < 3; i++)
			{

				cout << "The size of angle " << i + 1 << " :" << angles[i] << endl;
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

		cout << "Input first side: ";
		cin >> side_1;
		cout << "Input second side: ";
		cin >> side_2;
		cout << "Input angle (degrees) between them: ";
		cin >> angle;

		result[i] = new Triangle(side_1, side_2, angle);
	}

	return result;
}