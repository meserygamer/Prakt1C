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
	printf("�������� ������ ��� �������:\n1) ���������� ���������\n2) C������ ���� �������� ���������\n3) ������������ (���������)\n");
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