#include <iostream>
#include <chrono>
#define N 5000

class Timer
{
private:
	// ѕсевдонимы типов используютс€ дл€ удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void Factorial(unsigned long long int mas[N], int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		unsigned long long int fac_i = 1;

		if (mas[i] == 0)
			fac_i = 0;
		else 
		{
			for (int j = mas[i]; j > 0; j--)
			{
				fac_i = fac_i * j;
			}
		} 
		//mas[i] = fac_i; //при необходимости вывода массива раскомментировать
	}
}

int main()
{
	unsigned long long int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand() % 30;

	Timer t;

	Factorial(mas, N);

	std::cout << "Time: " << t.elapsed() << std::endl;

	/*for (int i = 0; i < N; i++)
		std::cout << mas[i] << std::endl; */ //при необходимости вывода массива раскомментировать

	return 0;
}