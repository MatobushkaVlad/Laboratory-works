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
	if ((n <= 10000) & (n >= 1))
	{
		int arr[10000];
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ")" << " ";
			int t;
			cin >> t;
			arr[i] = t;
		}
		bool sum_19 = false;
		for (int j = 0; j < n; j++)
		{
			int x = 0, a = arr[j];
			while (a > 0)
			{
				x = x + a % 10;
				a = a / 10;
			}
			if (abs(x) == 19)
			{
				sum_19 = true;
				break;
			}
		}
		if (!sum_19)
		{
			for (int j = 0; j < n - 1; j++)
			{
				for (int i = j + 1; i < n; i++)
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
		cout << "Число n не входит в диапазон";
	}
	return 0;
}