#include <iostream>

class Matrix
{
	// Абстракция
	// Инкапсуляция
	// Использование вне класса
public:
	// Конструктор
	Matrix(int n, int m)
	{
		std::cout << "Constructor" << std::endl;
		m_n = n;
		m_m = m;
		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];
	}

	// Конструктор копирования
	Matrix(const Matrix& mat)
	{
		std::cout << "Copy constructor" << std::endl;

		m_n = mat.m_n;
		m_m = mat.m_m;

		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];
	}

	// Присваивание
	Matrix& operator=(const Matrix& mat)
	{
		if ((m_n == mat.m_n) && (m_m == mat.m_m))
		{
			std::cout << "Operator =" << std::endl;

			m_n = mat.m_n;
			m_m = mat.m_m;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.m_mat[i][j];

			return *this;
		}
		else
			std::cout << "Некорректная матрица!" << std::endl;
	}

	// Оператор сложения
	Matrix operator+(const Matrix& mat)
	{
		if ((m_n == mat.m_n) && (m_m == mat.m_m))
		{
			std::cout << "operator+" << std::endl;
			Matrix tmp(m_n, m_m);
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
			return tmp;
		}
		else
			std::cout << "Некорректная матрица!" << std::endl;
	}

	// Оператор вычитания
	Matrix operator-(const Matrix& mat) 
	{
		if ((m_n == mat.m_n) && (m_m == mat.m_m))
		{
			std::cout << "operator-" << std::endl;
			Matrix tmp(m_n, m_m);
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
			return tmp;
		}
		else
			std::cout << "Некорректная матрица!" << std::endl;
	}

	// Оператор умножения
	Matrix operator*(const Matrix& mat) 
	{
		if (m_m == mat.m_n)
		{
			std::cout << "operator*" << std::endl;
			Matrix tmp(m_n, mat.m_m);
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < mat.m_m; j++)
				{
					tmp.m_mat[i][j] = 0;
					for (int t = 0; t < mat.m_n; t++)
					{
						tmp.m_mat[i][j] += m_mat[i][t] * mat.m_mat[t][j];
					}
				}
			return tmp;
		}
		else
			std::cout << "Некорректная матрица!" << std::endl;
	}

	//Метод для поиска определителя
	int Det()
	{
		if (m_n != m_m)
		{
			std::cout << "Операция не поддерживается!" << std::endl;
		}

		else if (m_n == m_m)
		{

			if (m_n == 2)
			{
				int d = 0;
				d = m_mat[0][0]*m_mat[1][1] - m_mat[0][1]*m_mat[1][0];
				return d;
			}
			else if (m_n == 3)
			{
				int d = 0;
				d = m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[1][0] * m_mat[2][1] * m_mat[0][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0] - m_mat[0][2] * m_mat[1][1] * m_mat[2][0] - m_mat[1][2] * m_mat[2][1] * m_mat[0][0] - m_mat[0][1] * m_mat[1][0] * m_mat[2][2];
				return d;
			}

		}
	}

	Matrix Reverse()
	{
		int det = Det();
		Matrix tmp(m_n, m_m);
		if (det == 0)
		{
			std::cout << "Обратной матрицы не существует!" << std::endl;
		}
		else if (m_n == m_m)
		{
			if (m_n == 2)
			{
				tmp.m_mat[0][0] = m_mat[1][1] / det;
				tmp.m_mat[1][1] = m_mat[0][0] / det;
				tmp.m_mat[1][0] = -(m_mat[1][0] / det);
				tmp.m_mat[0][1] = -(m_mat[0][1] / det);
				return tmp;
			}
			else if (m_n == 3)
			{
				tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / det;
				tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / det;
				tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / det;
				tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / det;
				tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / det;
				tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / det;
				tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / det;
				tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / det;
				tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / det;
				return tmp;
			}
		}
	}
	
	Matrix Transp()
	{
		Matrix tmp(m_m, m_n);
		for(int i = 0; i < m_m; i++)
			for (int j = 0; j < m_n; j++)
			{
				tmp.m_mat[i][j] = m_mat[j][i];
			}
		return tmp;
	}

	// Деструктор
	~Matrix()
	{
		std::cout << "Destructor" << std::endl;
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete m_mat;
	}

	// friend - позволяет функции иметь доступ к private полям/методам класса
	friend std::istream& operator>>(std::istream& os, Matrix& mat);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

	// Использование внутри класса
private:
	int m_n, m_m;		// Поле
	int n;
	int** m_mat;
};

// Перегрузка оператора ввода
// 
std::istream& operator>>(std::istream& in, Matrix& mat)
{
	for (int i = 0; i < mat.m_n; i++)
		for (int j = 0; j < mat.m_m; j++)
			in >> mat.m_mat[i][j];
	return in;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
	out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
	for (int i = 0; i < mat.m_n; i++) {
		for (int j = 0; j < mat.m_m; j++)
			out << mat.m_mat[i][j] << " ";
		out << std::endl;
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "rus");
	
	Matrix A(2, 3);

	std::cin >> A;
	//std::cout << A << std::endl; // std::cout << "Matrix " << mat.m_n << "x" << mat.m_m << mat.m_mat[0][0] << mat.m_mat[0][1] << ....

	Matrix B(3, 1);
	std::cin >> B;
	//std::cout << B << std::endl;

	Matrix C(2, 1);

	//C = A + B;

	//C = A - B;

	C = A * B;
	std::cout << C << std::endl;

	//std::cout << "Det" << std::endl;
	//std::cout << C.Det() << std::endl;

	//std::cout << "Reverse" << std::endl;
	//std::cout << C.Reverse() << std::endl;
	
	std::cout << "Transp" << std::endl;
	std::cout << C.Transp() << std::endl;


	return 0;
}
