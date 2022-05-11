#include <iostream>
#include "Lab6Var5Functions.hpp"


/*Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если все диагональные элементы матрицы положительны и содержат цифры 3 или 5, 
заменить минимальные элементы столбцов на суммы квадратов элементов соответствующих столбцов.*/

int main()
{
	setlocale(LC_ALL, "rus");
	int i, j;
	int A[fc::N][fc::N_1];
	fc::Read(i, j, A);
	if (fc::Diagonal(i, j, A))
	{
		fc::Resh(i, j, A);
		fc::Write(i, j, A);
	}
	else
		std::cout << "не получилось";
	return 0;
}
