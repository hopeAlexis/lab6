//Variant 5
//Whole numbers matrix { Aij }i = 1...n; j = 1..n, n <= 100. 
//if all diagonal elements of matrix are > 0 and contain digits 3 or 5,
//swap the minimal elements of each column for sums of squares of all elements in the column.

#include <iostream>
#include "Header.hpp"

int mas[100][100];

int main()
{
	int n = 3;
	matrixCreate(mas, n);
	printMatrix(mas, n);
}

