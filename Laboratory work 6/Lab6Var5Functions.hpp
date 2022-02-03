#pragma once

namespace fc
{
	const int N = 100, N_1 = 100;

	//Чтение
	void Read(int& i, int& j, int A[N][N_1]);

	//проверка чисел на условие
	int Uslovie(int i, int j, int A[N][N_1]);

	//выполняется ли условие
	bool Diagonal(int i, int j, int A[N][N_1]);

	void Resh(int i, int j, int A[N][N_1]);

	//вывод
	void Write(int i, int j, int A[N][N_1]);
}