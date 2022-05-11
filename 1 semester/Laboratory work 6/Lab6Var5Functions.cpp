#include <iostream>
#include "Lab6Var5Functions.hpp"


namespace fc
{
	void Read(int& i, int& j, int A[N][N_1])
	{
		std::cin >> i >> j;
		for (int n = 0; n < i; n++)
			for (int m = 0; m < j; m++)
			{
				std::cout << "A" << n << m << "= ";
				std::cin >> A[n][m];
			}
	}

	int Uslovie(int i, int j, int A[N][N_1])
	{
		int count = 0;
		for (int n = 0; n < i; n++)
			for (int m = 0; m < j; m++)
				if (n == m)
					if (A[n][m] > 0)
					{
						int chislo = A[n][m];
						int ostatok = 0;
						while (chislo > 0)
						{
							ostatok = chislo % 10;
							if ( ((ostatok % 3 == 0) && (ostatok / 3 == 1)) || ((ostatok / 5 == 1) && (ostatok % 5 == 0)) )
							{
								count++;
								break;
							}
							else
								count = 0;
							chislo = chislo / 10;
						} 
					}
		if (count == j)
			return 1;
		else
			return 0;
	}

	bool Diagonal(int i, int j, int A[N][N_1])
	{
		if (Uslovie(i, j, A) == 1)
			return true;
		else
			return false;
	}

	void Resh(int i, int j, int A[N][N_1])
	{
		for (int n = 0; n < i; n++)
		{
			int mini_i = 0, mini_j = 0;
			int mini = 100000;
			int count_1 = 0;
			for (int m = 0; m < j; m++)
			{
				if (A[m][n] < mini)
				{
					mini = A[m][n];
					mini_i = m;
					mini_j = n;
				}
				count_1 = count_1 + A[m][n] * A[m][n];
			}
			A[mini_i][mini_j] = count_1;
		}
	}

	void Write(int i, int j, int A[N][N_1])
	{
		for (int n = 0; n < i; n++)
			for (int m = 0; m < j; m++)
			{
				std::cout << "A" << n << m << "= " << A[n][m] << " ";
				if (m == j - 1)
					std::cout << std::endl;
			}
	}
}