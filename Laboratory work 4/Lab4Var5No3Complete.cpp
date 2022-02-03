#include "pch.h"
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m;
	int arr[100][100];//int Arr[100][100];
	cout << "¬вести кол-во строк и столбцов" << endl;
	cin >> n >> m;
	if ((n <= 100) & (m <= 100))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int t;
				cin >> t;
				cout << "arr[" << i + 1 << "]" << "[" << j + 1 << "]" << " = " << t << endl;
				arr[i][j] = t;
			}
		}
		int summax = 0, u = 0;
		for (int i = 0; i < n; i++)
		{
			int sumn = 0;
			for (int j = 0; j < m; j++)
			{
				sumn = sumn + arr[i][j];
				if (abs(sumn) > summax)
				{
					summax = abs(sumn);
					u = i;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == u)
				{
					arr[i][j] = 9999;
				}
			}
		}
	}
	else
	{
		cout << " n or m > 100"; 
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << i + 1 << "." << j + 1 << ") " << arr[i][j] << endl;
		}
	}
	return 0;
}