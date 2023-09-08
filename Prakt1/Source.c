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

#pragma endregion

int main()
{
	startInfoToConsole(); //Настройка консоли и вывод стартовой информации
	int userChoice = taskSelection(); //Выбор пользователем задачи 
	double** Test;
	Test = (double**)malloc(sizeof(double*) * 2);
	Test[0] = (double*)malloc(sizeof(double) * 3);
	Test[0][0] = 1;
	Test[0][1] = 5;
	Test[0][2] = -7;
	Test[1] = (double*)malloc(sizeof(double) * 3);
	Test[1][0] = 3;
	Test[1][1] = -2;
	Test[1][2] = -4;
	solvingSystemOfTwoLinearEquations(Test);
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