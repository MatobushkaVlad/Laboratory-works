//#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>

using namespace std;

/*Дан файл, содержащий русский текст, размер текста не превышает 10 К байт.
	Найти в тексте N(N ≤ 100) самых длинных слов, не содержащих одинаковых букв.
	Записать найденные слова в текстовый файл в порядке не возрастания длины.
	Все найденные слова должны быть разными.
	Число N вводить из файла.*/

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream text("text.txt");
	string s , t[10000] , c[100];
	int y = 0;
	while (!text.eof()) {
		text >> s;
		//Убираем знаки
		for (int i = 0; i < s.length() ; i++) {
			if (ispunct(((unsigned char) s[i])) != 0) {
				s.erase(i);
			}
		}
		//Проверка на неналичие одинаковых букв, и запись в массив.
		int buk = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j < s.length(); j++) {
				if ( s[i] == s[j] ) {
					buk++;
				}
			}
		}
		if (buk == 0) {
			t[y] = s;
			y++;
		} 
	}
	text.close();
	//Убираем одинаковые слова, и сортируем по убыванию.
	int wordNum = y , ux = y;
	for (int j = 0; j < wordNum; j++) {
		for (int i = j + 1; i < wordNum; i++) {
			if (t[j].length() < t[i].length()) {
				swap(t[j], t[i]);
			}
			if (t[j].length() == t[i].length()) {
				int count = 0;
				for (int n = 0; n < t[j].length(); n++) {
					for (int m = 0; m < t[i].length(); m++) {
						if (toupper(t[j][n]) == toupper(t[i][m])) {
							count++;
							if (count == t[j].length()) {
								t[i].clear();
								ux = ux - 1;
							}
						}
					}
				}
			}
		}
	}
	//Запись из рабочего массива в итоговый
	ofstream otvet("otvet.txt");
	for (int i = 0; i < ux ; i++) {
		c[i] = t[i];
		otvet << c[i] << endl;
	}
	otvet.close();

	cout << "вроде всё сработало";
	return 0;
}