#include "Header.hpp"
#include <iostream>

void matrixCreate(int (*mas)[100], int m)
{
	std::cout << "Enter matrix: \n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			std::cin >> mas[i][j]; //������ �������
		}
	}
	if3or5andPlus(mas, m);
}

void if3or5andPlus(int(*mas)[100], int m) //�������� �� ������������� �����, ���������� ����� 3 ��� 5
{
	bool okay = true;
	for (int i = 0; i < m; i++)
	{
		if (mas[i][i] > 0) //��������� ������� ���������
			okay = if3or5(mas[i][i]); //�������� ������� �� ���������� ������ ����
		if (!okay)
			break;

		if (mas[i][m - i - 1] > 0 /*&& i != (m - i - 1)*/)//��������� �������� ���������
			okay = if3or5(mas[i][m - i - 1]); //�������� ������� �� ���������� ������ ����
		if (!okay)
			break;
	}

	if (okay)
	{
		std::cout << "all requirments are met, so matrix changes.\n";
		changeMin(mas, m); //���� ������������� �������, �������� ������� �� ������ ����
	}
	else
		std::cout << "doesn't satisfy the conditions, so no changes.\n";
}

bool if3or5(int mas)
{
	bool number = false;
	while (mas > 0)
	{
		if (mas % 10 == 3 || mas % 10 == 5) //��������� ������� � ����� 3 ��� 5
		{
			number = true;
			break;
		}
		mas = mas / 10;
	}
	return number;
}

void changeMin(int(*mas)[100], int m)
{
	for (int j = 0; j < m; j++) //��������� �������
	{
		int minInColumn = INT_MAX;
		int sumSquare = 0;
		int iMin;
		for (int i = 0; i < m; i++)
		{
			sumSquare += mas[i][j] * mas[i][j];
			if (mas[i][j] < minInColumn)
			{
				minInColumn = mas[i][j];
				iMin = i;
			}
		}
		mas[iMin][j] = sumSquare; //�������� ����������� ������� � �������
	}
}

void printMatrix(int(*mas)[100], int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << mas[i][j] << " "; //����� �������
		}
		std::cout << std::endl;
	}
}