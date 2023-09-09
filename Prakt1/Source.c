#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma region FuncPrototypes

void startInfoToConsole();
int taskSelection();
double* solutionQuadraticEquation(double* coefVector);
int solutionNumberOfObjectPermutations(int NumberOfObjects);
double* solvingSystemOfTwoLinearEquations(double** TwoLinearEquationsMatrix);
void startCalculate(int userChoice);
double* userInputQuadraticEquation();
double** userInputSystemOfTwoLinearEquations();
int userInputNumberOfObjectPermutations();
void outputQuadraticEquation(double* resultQuadraticEquation);
void outputSystemOfTwoLinearEquations(double* resultSystemOfTwoLinearEquations);
void outputNumberOfObjectPermutations(int resultNumberOfObjectPermutations);

#pragma endregion

int main()
{
	startInfoToConsole(); //Настройка консоли и вывод стартовой информации
	int userChoice = taskSelection(); //Выбор пользователем задачи 
	startCalculate(userChoice); //Начало решения задачи
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
			system("cls");
			switch (userChoice)
			{
			case 1:
				printf("Вы выбрали задачу на решение квадратного уравнения\n");
				break;
			case 2:
				printf("Вы выбрали задачу на решение системы двух линейных уравнений\n");
				break;
			case 3:
				printf("Вы выбрали задачу на подсчет количества перестановок\n");
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
		outputQuadraticEquation(solutionQuadraticEquation(userInputQuadraticEquation()));
		break;
	case 2:
		outputSystemOfTwoLinearEquations(solvingSystemOfTwoLinearEquations(userInputSystemOfTwoLinearEquations()));
		break;
	case 3:
		outputNumberOfObjectPermutations(solutionNumberOfObjectPermutations(userInputNumberOfObjectPermutations()));
		break;
	}
}

#pragma region Функции обработки пользовательского ввода параметров для задач
/// <summary>
/// Функция обработки пользовательского ввода для задачи решения квадратного уравнения
/// </summary>
double* userInputQuadraticEquation()
{
	printf("Введите коэффициенты квадратного уравнения через пробел (Маска ввода: a b c) \n");
	double* userInput = (double*)malloc(sizeof(double) * 3);
	int rightNumberCount;
	do
	{
		rightNumberCount = scanf_s("%lf %lf %lf", &userInput[0], &userInput[1], &userInput[2]);
		if (rightNumberCount != 3)
		{
			printf("Одно или несколько значений не соответствуют маске, повторите ввод\n");
			while ((getchar()) != '\n');
		}
	} while (rightNumberCount != 3);
	return userInput;
}

/// <summary>
/// Функция обработки пользовательского ввода для задачи решения системы двух линейных уравнений
/// </summary>
double** userInputSystemOfTwoLinearEquations()
{
	printf("Введите коэффициенты линейных уравнений через пробел (Маска ввода: a1 b1 c1 a2 b2 c2) \n");
	double** twoLinearEquationsMatrix = (double**)malloc(sizeof(double*) * 2);
	int rightNumberCount;
	for (int i = 0; i < 2; i++)
	{
		twoLinearEquationsMatrix[i] = (double*)malloc(sizeof(double) * 3);
	}
	do
	{
		rightNumberCount = scanf_s("%lf %lf %lf %lf %lf %lf", &twoLinearEquationsMatrix[0][0]
			, &twoLinearEquationsMatrix[0][1], &twoLinearEquationsMatrix[0][2], &twoLinearEquationsMatrix[1][0]
			, &twoLinearEquationsMatrix[1][1], &twoLinearEquationsMatrix[1][2]);
		if (rightNumberCount != 6)
		{
			printf("Одно или несколько значений не соответствуют маске, повторите ввод\n");
			while ((getchar()) != '\n');
		}
	} while (rightNumberCount != 6);
	return twoLinearEquationsMatrix;
}

/// <summary>
/// Функция обработки пользовательского ввода для задачи нахождения количества пепрестановок объектов
/// </summary>
int userInputNumberOfObjectPermutations()
{
	printf("Введите количество предметов, для расчета количества вариантов перестановок \n");
	int NumberOfObjects, rightNumberCount;
	do
	{
		rightNumberCount = scanf_s("%d", &NumberOfObjects);
		if (rightNumberCount != 1)
		{
			printf("Введенное значение не является числом, повторите ввод\n");
			while ((getchar()) != '\n');
		}
		else
		{
			if (NumberOfObjects < 0)
			{
				printf("Введено отрицательное количество объектов, повторите ввод\n");
			}
		}
	} while (rightNumberCount != 1 || NumberOfObjects < 0);
	return NumberOfObjects;
}
#pragma endregion

#pragma region Функции нахождения решения задач

double* solutionQuadraticEquation(double* coefVector)
{
	double D = pow(coefVector[1], 2) - 4 * coefVector[0] * coefVector[2];
	double* quadraticEquationResult = (double*)malloc(sizeof(double) * 2);
	quadraticEquationResult[0] = (-coefVector[1] + sqrt(D)) / (2 * coefVector[0]);
	quadraticEquationResult[1] = (-coefVector[1] - sqrt(D)) / (2 * coefVector[0]);
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

#pragma endregion

#pragma region Функции вывода решения задачи в консоль

void outputQuadraticEquation(double* resultQuadraticEquation)
{
	system("cls");
	printf("x1 = %lf\nx2 = %lf", resultQuadraticEquation[0], resultQuadraticEquation[1]);
}

void outputSystemOfTwoLinearEquations(double* resultSystemOfTwoLinearEquations)
{
	system("cls");
	printf("x = %lf\ny = %lf", resultSystemOfTwoLinearEquations[0], resultSystemOfTwoLinearEquations[1]);
}

void outputNumberOfObjectPermutations(int resultNumberOfObjectPermutations)
{
	system("cls");
	printf("Количество возможных перестановок при введенном числе объектов - %d", resultNumberOfObjectPermutations);
}

#pragma endregion