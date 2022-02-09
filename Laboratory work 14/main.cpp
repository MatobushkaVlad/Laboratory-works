#include <iostream>
#include <chrono>
#define N 5000

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
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

	for (int i = 0; i < n; i++)
	{
		unsigned long long int fac_i = 1;

		if (mas[i] == 0)
			fac_i = 0;

		for (int j = 1; j <= mas[i]; j++)
			fac_i = fac_i * j;
	}

}

int main()
{
	unsigned long long int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand();

	Timer t;

	Factorial(mas, N);

	std::cout << "Time: " << t.elapsed() << std::endl;

	return 0;
}