#pragma once
#include <iostream>

namespace mt::math
{
	//#define DEBUG

	template<typename T, int N, int M>
	class Matrix
	{
	public:

		int getN() const { return m_n; }
		int getM() const { return m_m; }
		T get(int i, int j) const { return m_mat[i][j]; }
		void set(int i, int j, T data) { m_mat[i][j] = data; }

		// Конструктор
		Matrix()
		{
#ifdef DEBUG
			std::cout << "Constructor" << std::endl;
#endif
			m_n = N;
			m_m = M;
			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = 0;
		}

		//Copy constructor
		Matrix(const Matrix<T, N, M>& mat)
		{
#ifdef DEBUG
			std::cout << "Copy constructor" << std::endl;
#endif

			m_n = mat.m_n;
			m_m = mat.m_m;

			for (int i = 0; i < m_n; i++)
				for (int j = 0; j < m_m; j++)
					m_mat[i][j] = mat.get(i, j);
		}

		// Assignment
		template<typename T, int N, int M>
		Matrix<T, N, M>& operator=(const Matrix<T, N, M>& mat)
		{
			if ((m_n == mat.getN()) && (m_m == mat.getM())
			{
#ifdef DEBUG
				std::cout << "Operator =" << std::endl;
#endif
					m_n = mat.getN();
					m_m = mat.getM();

					for (int i = 0; i < m_n; i++)
						for (int j = 0; j < m_m; j++)
							m_mat[i][j] = mat.get(i, j);

					return *this;
			}
			else
				std::cout << "Incorrect matrix!" << std::endl;
		}

		// Addition operator
		template<typename T, int N, int M>
		Matrix<T, N, M> operator+(const Matrix<T, N, M>& mat)
		{
			if ((m_n == mat.getN()) && (m_m == mat.getM())
			{
#ifdef DEBUG
				std::cout << "operator+" << std::endl;
#endif
				Matrix<T, N, M> tmp;
				for (int i = 0; i < m_n; i++)
					for (int j = 0; j < m_m; j++)
						tmp.m_mat[i][j] = m_mat[i][j] + mat.get(i, j);
				return tmp;
			}
			else
				std::cout << "Incorrect matrix!" << std::endl;
		}

		//Subtraction operator
		template<typename T, int N, int M>
		Matrix<T, N, M> operator-(const Matrix<T, N, M>& mat)
		{
			if ((m_n == mat.getN()) && (m_m == mat.getM())
			{
#ifdef DEBUG
				std::cout << "operator-" << std::endl;
#endif
				Matrix<T, N, M> tmp;
				for (int i = 0; i < m_n; i++)
					for (int j = 0; j < m_m; j++)
						tmp.m_mat[i][j] = m_mat[i][j] - mat.get(i, j);
				return tmp;
			}
			else
				std::cout << "Incorrect matrix!" << std::endl;
		}

		//Multiplication operator
		template<typename T, int N, int M>
		Matrix<T, N, M> operator*(const Matrix<T, N, M>& mat)
		{
			if (m_m == mat.m_n)
			{
#ifdef DEBUG
				std::cout << "operator*" << std::endl;
#endif
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
			else
				std::cout << "Incorrect matrix!" << std::endl;
		}

		//Determinant
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
					d = (m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0]);
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

		//Reverse
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

		//Transposition
		Matrix<T, N, M> Transp()
		{
			Matrix<T, M, N> tmp;
			for (int i = 0; i < m_m; i++)
				for (int j = 0; j < m_n; j++)
				{
					tmp.m_mat[i][j] = m_mat[j][i];
				}
			return tmp;
		}

		// Деструктор
		~Matrix()
		{
#ifdef DEBUG
			std::cout << "Destructor" << std::endl;
#endif
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
		for (int i = 0; i < mat.getN(); i++) 
		{
			for (int j = 0; j < mat.getM(); j++)
				out << mat.get(i, j) << " ";
			out << std::endl;
		}
		return out;
	}

	using Vec2i = Matrix<int, 2, 1>;
	using Vec3i = Matrix<int, 3, 1>;
	using Mat22i = Matrix<int, 2, 2>;
	using Mat23i = Matrix<int, 2, 3>;

}