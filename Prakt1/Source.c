#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma region FuncPrototypes

void startInfoToConsole();
int taskSelection();
double* solutionQuadraticEquation(double a, double b, double c);

#pragma endregion

int main()
{
	startInfoToConsole(); //Настройка консоли и вывод стартовой информации
	int userChoice = taskSelection(); //Выбор пользователем задачи 
	solutionQuadraticEquation(1, 4, 3);
	return 0;
}

void startInfoToConsole()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Выберите задачу для решения:\n1) Квадратное уравнение\n2) Cистема двух линейных уравнений\n3) Перестановки (факториал)\n");
}

int taskSelection()
{
	int userChoice;
	do
	{
		scanf_s("%d", &userChoice);
		while ((getchar()) != '\n'); //Отчистка входного потока
		if (userChoice >= 1 && userChoice <= 3)
		{
			switch (userChoice)
			{
			case 1:
				printf("Вы выбрали задачу на решение квадратного уравнения\n");
				break;
			case 2:
				printf("Вы выбрали задачу на решение системы двух линейных уравнений\n");
				break;
			case 3:
				printf("Вы выбрали задачу на подсчет количества перестановок");
				break;
			}
			return userChoice;
		}
		else printf("%s", "Неправильный ввод, повторите попытку\n");
	} while (!(userChoice >= 1 && userChoice <= 3));
}

double* solutionQuadraticEquation(double a, double b, double c)
{
	double D = pow(b, 2) - 4 * a * c;
	double* quadraticEquationResult = (double*)malloc(sizeof(double) * 2);
	quadraticEquationResult[0] = (-b + sqrt(D)) / (2 * a);
	quadraticEquationResult[1] = (-b - sqrt(D)) / (2 * a);
	return quadraticEquationResult;
}