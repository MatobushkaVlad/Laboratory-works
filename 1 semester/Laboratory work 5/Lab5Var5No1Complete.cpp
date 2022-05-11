#include "pch.h"
#include<iostream>
using namespace std;

//Дана строка не более 100 символов. Найти в ней наиболее часто встречающуюся букву. Регистр не учитывать.

int main()
{
	setlocale(LC_ALL, "rus");
	char string[100];
	cout << "Введите строку" << endl;
	cin.getline(string, 100);
	int countmax = 0, imax = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		int counti = 1;
		for (int j = i + 1; j < strlen(string); j++)
		{
			if (toupper(string[i]) == toupper(string[j]))
			{
				counti++;
			}
		}
		if (counti > countmax)
		{
			countmax = counti;
			imax = i;
		}
	}
	cout << string[imax] << "=" << countmax << endl;

	return 0;
}