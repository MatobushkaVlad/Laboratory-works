#include <iostream>

template<typename T, int N, int M>
class Matrix
{
public:

	int getN() { return m_n; }
	int getM() { return m_m; }
	T get(int i, int j) { return m_mat[i][j]; }
	void set(int i, int j, T data) { m_mat[i][j] = data; }

	// Конструктор
	Matrix()
	{
		std::cout << "Constructor" << std::endl;
		m_n = N;
		m_m = M;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = 0;
	}

	// Конструктор копирования
	Matrix(const Matrix<T, N, M>& mat)
	{
		std::cout << "Copy constructor" << std::endl;

		m_n = mat.getN();
		m_m = mat.getM();

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.get(i, j);
	}

	// Присваивание
	template<typename T, int N, int M>
	Matrix<T, N, M>& operator=(const Matrix<T, N, M>& mat)
	{
		std::cout << "Operator =" << std::endl;

		m_n = mat.getN();
		m_m = mat.getM();

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.get(i, j);

		return *this;
	}

	// Оператор сложения
	template<typename T, int N, int M>
	Matrix<T, N, M> operator+(const Matrix<T, N, M>& mat)
	{
		std::cout << "operator+" << std::endl;
		Matrix<T, N, M> tmp;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] + mat.get(i, j);
		return tmp;
	}

	// Оператор вычитания !Не проверенный!
	template<typename T, int N, int M>
	Matrix<T, N, M> operator-(const Matrix<T, N, M>& mat) 
	{
		std::cout << "operator-" << std::endl;
		Matrix<T, N, M> tmp;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] - mat.get(i, j);
		return tmp;
	}

	// Оператор умножения !Не проверенный!
	template<typename T, int N, int M>
	Matrix<T, N, M> operator*(const Matrix<T, N, M>& mat) 
	{
		std::cout << "operator*" << std::endl;
		Matrix<T, N, M> tmp;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < mat.getM(); j++)
			{
				tmp.m_mat[i][j] = 0;
				for (int t = 0; t < mat.getN(); t++)
				{
					tmp.m_mat[i][j] += m_mat[i][t] * mat.get(t, j);
				}
			}
		return tmp;
	}

	//Метод для поиска определителя
	T Det()
	{
		if (m_n != m_m)
		{
			std::cout << "Операция не поддерживается!" << std::endl;
		}

		else if (m_n == m_m)
		{
			if (m_n == 2)
			{
				T d = 0;
				d = (m_mat[0][0]*m_mat[1][1] - m_mat[0][1]*m_mat[1][0]);
				return d;
			}
			else if (m_n == 3)
			{
				T d = 0;
				d = (m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[1][0] * m_mat[2][1] * m_mat[0][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0] - m_mat[0][2] * m_mat[1][1] * m_mat[2][0] - m_mat[1][2] * m_mat[2][1] * m_mat[0][0] - m_mat[0][1] * m_mat[1][0] * m_mat[2][2]);
				return d;
			}
		}
	}

	Matrix<double, N, M> Reverse()
	{
		T det = Det();
		Matrix<double, N, M> tmp;
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
	
	Matrix<T, N, M> Transp()
	{
		Matrix<T, N, M> tmp;
		for(int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
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
	template<typename T, int N, int M>
	friend std::istream& operator>>(std::istream& os, Matrix<T, N, M>& mat);
	template<typename T, int N, int M>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& mat);

	// Использование внутри класса
private:
	int m_n, m_m;		// Поле
	T m_mat[N][M];
};

// Перегрузка оператора ввода
template<typename T, int N, int M>
std::istream& operator>>(std::istream& in, Matrix<T, N, M>& mat)
{
	for (int i = 0; i < mat.getN(); i++)
		for (int j = 0; j < mat.getM(); j++)
			in >> mat.get(i, j);
	return in;
}

// Перегрузка оператора вывода
template<typename T, int N, int M>
std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& mat)
{
	out << "Matrix " << mat.getN() << "x" << mat.getM() << std::endl;
	for (int i = 0; i < mat.getN(); i++) {
		for (int j = 0; j < mat.getM(); j++)
			out << mat.get(i, j) << " ";
		out << std::endl;
	}
	return out;
}

int main()
{
	
	Matrix<double, 2, 2> A;

	std::cin >> A;
	//std::cout << A << std::endl; // std::cout << "Matrix " << mat.m_n << "x" << mat.m_m << mat.m_mat[0][0] << mat.m_mat[0][1] << ....

	Matrix<double, 2, 2> B;
	std::cin >> B;
	//std::cout << B << std::endl;

	Matrix<double, 2, 2> C;

	C = A + B;
	std::cout << C << std::endl;

	std::cout << "------------------------------------------" << std::endl;

	C = A - B;
	std::cout << C << std::endl;

	std::cout << "-------------------------------------------" << std::endl;

	C = A * B;
	std::cout << C << std::endl;

	std::cout << "Determinant" << std::endl;
	std::cout << C.Det() << std::endl;

	std::cout << "Reverse" << std::endl;
	std::cout << C.Reverse() << std::endl;

	std::cout << "Transp" << std::endl;
	std::cout << C.Transp() << std::endl;


	return 0;
}
