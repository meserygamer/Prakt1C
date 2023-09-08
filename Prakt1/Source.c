#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#pragma region FuncPrototypes

void StartInfoToConsole();
int TaskSelection();

#pragma endregion

int main()
{
	StartInfoToConsole();
	TaskSelection();
	return 0;
}

void StartInfoToConsole()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Выберите задачу для решения:\n1) Квадратное уравнение\n2) Cистема двух линейных уравнений\n3) Перестановки (факториал)\n");
}

int TaskSelection()
{
	int userChoice;
	do
	{
		scanf_s("%d", &userChoice);
		while ((getchar()) != '\n');
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