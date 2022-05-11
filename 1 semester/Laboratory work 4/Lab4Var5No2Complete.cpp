#include "pch.h"
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Ввести кол-во элементов" << endl;
	cin >> n;
	if ((n <= 1000) & (n >= 1))
	{
		int arr[1000];
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ")" << " ";
			int t;
			cin >> t;
			arr[i] = t;
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = j + 1; i < n - 1; i++)
			{
				int sumj = 0, sumi = 0;
				int aj = arr[j], ai = arr[i];
				while ((aj > 0) & (ai > 0))
				{
					sumj += aj % 10;
					sumi += ai % 10;
					aj /= 10;
					ai /= 10;
				}
				if (sumj > sumi)
				{
					swap(arr[j], arr[i]);
				}
				int xj = 0, xi = 0;
				int aj1 = arr[j], ai1 = arr[i];
				if (sumj == sumi)
				{
					while ((aj1 > 0) & (ai1 > 0))
					{
						xj = 0;
						xi = 0;
						xj = aj1 % 10;
						xi = ai1 % 10;
						aj1 /= 10;
						ai1 /= 10;
					}
					if (xj > xi)
					{
						swap(arr[j], arr[i]);
					}
				}
				if ((sumj == sumi) & (xj == xi))
				{
					if (arr[j] > arr[i])
					{
						swap(arr[j], arr[i]);
					}
				}
			}
		}
		for (int p = 0; p < n; p++)
		{
			cout << arr[p] << " ";
		}
	}
	else
	{
		cout << "Число n не попадает в диапазон";
	}
	return 0;
}
