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
	startInfoToConsole(); //��������� ������� � ����� ��������� ����������
	int userChoice = taskSelection(); //����� ������������� ������ 
	solutionQuadraticEquation(1, 4, 3);
	return 0;
}

void startInfoToConsole()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("�������� ������ ��� �������:\n1) ���������� ���������\n2) C������ ���� �������� ���������\n3) ������������ (���������)\n");
}

int taskSelection()
{
	int userChoice;
	do
	{
		scanf_s("%d", &userChoice);
		while ((getchar()) != '\n'); //�������� �������� ������
		if (userChoice >= 1 && userChoice <= 3)
		{
			switch (userChoice)
			{
			case 1:
				printf("�� ������� ������ �� ������� ����������� ���������\n");
				break;
			case 2:
				printf("�� ������� ������ �� ������� ������� ���� �������� ���������\n");
				break;
			case 3:
				printf("�� ������� ������ �� ������� ���������� ������������");
				break;
			}
			return userChoice;
		}
		else printf("%s", "������������ ����, ��������� �������\n");
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