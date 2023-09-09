#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma region FuncPrototypes

void startInfoToConsole();
int taskSelection();
double* solutionQuadraticEquation(double a, double b, double c);
int solutionNumberOfObjectPermutations(int NumberOfObjects);
double* solvingSystemOfTwoLinearEquations(double** TwoLinearEquationsMatrix);
void startCalculate(int userChoice);

#pragma endregion

int main()
{
	startInfoToConsole(); //Настройка консоли и вывод стартовой информации
	int userChoice = taskSelection(); //Выбор пользователем задачи 
	startCalculate(userChoice); //Начало решения задачи

	/*double** Test;
	Test = (double**)malloc(sizeof(double*) * 2);
	Test[0] = (double*)malloc(sizeof(double) * 3);
	Test[0][0] = 1;
	Test[0][1] = 5;
	Test[0][2] = -7;
	Test[1] = (double*)malloc(sizeof(double) * 3);
	Test[1][0] = 3;
	Test[1][1] = -2;
	Test[1][2] = -4;
	solvingSystemOfTwoLinearEquations(Test);*/
	return 0;
}
/// <summary>
/// Настройка консоли и вывод стартовой информации
/// </summary>
void startInfoToConsole()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Выберите задачу для решения:\n1) Квадратное уравнение\n2) Cистема двух линейных уравнений\n3) Перестановки (факториал)\n");
}

/// <summary>
/// Выбор задачи пользователем
/// </summary>
/// <returns>Номер выбранной задачи</returns>
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

/// <summary>
/// Начало решения задачи
/// </summary>
/// <param name="userChoice">Номер выбранной задачи</param>
void startCalculate(int userChoice)
{
	switch (userChoice)
	{
	case 1:
		printf("Введите коэффициенты квадратного уравнения через пробел (Маска ввода: a b c) \n");
		double a, b, c;
		int rightNumberCount;
		do
		{
			rightNumberCount = scanf_s("%lf %lf %lf", a, b, c);
			if(rightNumberCount != 3)
			{
				printf("Одно или несколько значений не соответствуют маске, повторите ввод");
				while ((getchar()) != '\n');
			}
		} while (rightNumberCount != 3);
		//
		break;
	case 2:
		printf("Введите коэффициенты линейных уравнений через пробел (Маска ввода: a1 b1 c1 a2 b2 c2) \n");
		double** twoLinearEquationsMatrix =  (double**)malloc(sizeof(double*) * 2);
		int rightNumberCount;
		for (int i = 0; i < 2; i++)
		{
			twoLinearEquationsMatrix[i] = (double*)malloc(sizeof(double) * 3);
		}
		do
		{
			rightNumberCount = scanf_s("%lf %lf %lf %lf %lf %lf", twoLinearEquationsMatrix[0][0]
			,twoLinearEquationsMatrix[0][1], twoLinearEquationsMatrix[0][2], twoLinearEquationsMatrix[1][0]
			,twoLinearEquationsMatrix[1][1], twoLinearEquationsMatrix[1][2]);
			if (rightNumberCount != 6)
			{
				printf("Одно или несколько значений не соответствуют маске, повторите ввод");
				while ((getchar()) != '\n');
			}
		} while (rightNumberCount != 6);
		break;
		//
	case 3:
		printf("Введите количество предметов, для расчета количества вариантов перестановок \n");
		int NumberOfObjects, rightNumberCount;
		do
		{
			rightNumberCount = scanf_s("%d", NumberOfObjects);
			if (rightNumberCount != 1)
			{
				printf("Введенное значение не является числом, повторите ввод");
				while ((getchar()) != '\n');
			}
			else
			{
				if (NumberOfObjects < 0)
				{
					printf("Введено отрицательное количество объектов, повторите ввод");
				}
			}
		} while (rightNumberCount != 1 || NumberOfObjects < 0);
		//
		break;
	}
}

double* solutionQuadraticEquation(double a, double b, double c)
{
	double D = pow(b, 2) - 4 * a * c;
	double* quadraticEquationResult = (double*)malloc(sizeof(double) * 2);
	quadraticEquationResult[0] = (-b + sqrt(D)) / (2 * a);
	quadraticEquationResult[1] = (-b - sqrt(D)) / (2 * a);
	return quadraticEquationResult;
}

int solutionNumberOfObjectPermutations(int NumberOfObjects)
{
	int factorial = 1;
	for (int number = 1; number <= NumberOfObjects; number++) factorial *= number;
	return factorial;
}

double* solvingSystemOfTwoLinearEquations(double** TwoLinearEquationsMatrix)
{
	double multiplyingTheSecondEquation = TwoLinearEquationsMatrix[0][0] / TwoLinearEquationsMatrix[1][0];
	for (int i = 0; i < 3; i++)
	{
		TwoLinearEquationsMatrix[0][i] += (-multiplyingTheSecondEquation) * TwoLinearEquationsMatrix[1][i];
	}
	double* systemOfTwoLinearEquationsResult = (double*)malloc(sizeof(double) * 2);
	systemOfTwoLinearEquationsResult[1] = (-TwoLinearEquationsMatrix[0][2]) / TwoLinearEquationsMatrix[0][1];
	systemOfTwoLinearEquationsResult[0] = ((-TwoLinearEquationsMatrix[1][2])
		- TwoLinearEquationsMatrix[1][1] * systemOfTwoLinearEquationsResult[1]) / TwoLinearEquationsMatrix[1][0];
	return systemOfTwoLinearEquationsResult;
}