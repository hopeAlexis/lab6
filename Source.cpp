#include "Header.hpp"
#include <iostream>

void matrixCreate(int (*mas)[100], int m)
{
	std::cout << "Enter matrix: \n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			std::cin >> mas[i][j]; //enter matrix
		}
	}
	if3or5andPlus(mas, m);
}

void if3or5andPlus(int(*mas)[100], int m) //checking if number > 0 and contains 3 or 5
{
	bool okay = true;
	for (int i = 0; i < m; i++)
	{
		if (mas[i][i] > 0) //checking main diagonal
			okay = if3or5(mas[i][i]); //function that searches for digits 3 or 5
		if (!okay)
			break;

		if (mas[i][m - i - 1] > 0 /*&& i != (m - i - 1)*/) //checking secondary diagonal
			okay = if3or5(mas[i][m - i - 1]); //function that searches for digits 3 or 5
		if (!okay)
			break;
	}

	if (okay)
	{
		std::cout << "all requirments are met, so matrix changes.\n";
		changeMin(mas, m);
	}
	else
		std::cout << "doesn't satisfy the conditions, so no changes.\n";
}

bool if3or5(int mas)
{
	bool number = false;
	while (mas > 0)
	{
		if (mas % 10 == 3 || mas % 10 == 5) //checks if the number contains 3 or 5
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
	for (int j = 0; j < m; j++) //checking the columns
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
		mas[iMin][j] = sumSquare; //changing the minimal element in the matrix
	}
}

void printMatrix(int(*mas)[100], int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << mas[i][j] << " "; //output the matrix
		}
		std::cout << std::endl;
	}
}