#pragma once

namespace fc
{
	const int N = 100, N_1 = 100;

	//������
	void Read(int& i, int& j, int A[N][N_1]);

	//�������� ����� �� �������
	int Uslovie(int i, int j, int A[N][N_1]);

	//����������� �� �������
	bool Diagonal(int i, int j, int A[N][N_1]);

	void Resh(int i, int j, int A[N][N_1]);

	//�����
	void Write(int i, int j, int A[N][N_1]);
}