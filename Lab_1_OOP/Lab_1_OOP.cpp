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
	setlocale(LC_ALL, "Russian");

	int num = 0;
	cout << "Введите количество треугольников: ";
	cin >> num;

	Triangle** triangles = readTrianglesFromConsole(num);

	while (true) {
		int index = 0;

		cout << "ВВедите номер треугольника: ";
		cin >> index;

		index--;

		if (index < 0 || index >= num) {
			cout << "Неправильный номер!";
			continue;
		}

		char *comand = new char[256]{ NULL };
		cout << "Введите команду:\n "
			<< "1 - Увеличить угол\n "
			<< "2 - Уменьшить угол\n "
			<< "3 - Длина бисексрис\n "
			<< "4 - Длина отрезков, на которые бисектриса делит сторону\n "
			<< "5 - Величина углов\n";
		cin >> comand;

		if (strcmp(comand, "1") == 0) {
			int number = 1;

			cout << "Количество раз: ";
			cin >> number;

			if (number == 0)
			{
				cout << "Неверно!";
			}

			triangles[index]->increaseAngle(number);

			cout << triangles[index]->angle;

		}

		if (strcmp(comand, "2") == 0) {
			int number = 1;

			cout << "Количество раз: ";
			cin >> number;

			if (number == 0)
			{
				cout << "Неверно!";
			}

			triangles[index]->decreaseAngle(number);

			cout << triangles[index]->angle;
		}

		if (strcmp(comand, "3") == 0) {
			double *bisectors = triangles[index]->getBisector();
			for (int i = 0; i < 3; i++)
			{
				
				cout << "Длинна бисектрисы " << i + 1 << " :" << bisectors[i] << endl;
			}

		}

		if (strcmp(comand, "4") == 0){
			double **side = triangles[index]->getSidesByBisector();
			for (int i = 0; i < 3; i++)
			{
				cout << "Сторона: " << i + 1 << endl;
				for (int j = 0; j < 2; j++)
				{
					cout << "Длина отрезка: " << side[i][j] <<  endl;
				}
				
			}

		}

		if (strcmp(comand, "5") == 0){
			double *angles = triangles[index]->getAngles();
			for (int i = 0; i < 3; i++)
			{

				cout << "Величина угла " << i + 1 << " : " << angles[i] << endl;
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

		cout << "Введите размер первой стороны: ";
		cin >> side_1;
		cout << "Введите размер второй стороны: ";
		cin >> side_2;
		cout << "Введите угол между ними(в градусах): ";
		cin >> angle;

		result[i] = new Triangle(side_1, side_2, angle);
	}

	return result;
}