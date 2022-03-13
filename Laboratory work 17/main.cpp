#include <iostream>
#include <chrono>
const int N = 100000;

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

int Binary_Search(int mas[], int left, int right, int k)
{
	if (k == mas[left])
		return mas[left];
	if (k < mas[left])
		return 0;
	if (k == mas[right])
		return mas[right];
	if (k > mas[right])
		return 0;
	while (left + 1 < right)
	{
		int c = (left + right) / 2;
		if (k > mas[c])
			left = c;
		else
			right = c;
	}
	if (k == mas[right])
		return right;
	else
		return 0;
}

double Function(double x)
{
	return sin(2*x + 3);
}

double Bisection(double left, double right)
{
	double eps = 1e-4;
	while (1)
	{
		double x = (left + right) / 2;
		if ((abs(x - left) < eps) & (abs(x - right) < eps))
			return x;
		else if (Function(x) * Function(left) > 0)
			left = x;
		else
			right = x;
	}
}

int main()
{
	int mas[N];
	int a = 0;
	int b = N-1;
	int k = 0;
	double left = 0;
	double right = 1;

	for (int i = 0; i < N; i++)
		mas[i] = i;

	std::cout << "Enter " << mas[0] << " <= k < " << mas[N-1] << std::endl;
	std::cin >> k;

	Timer t;

	std::cout << Binary_Search(mas, a, b, k) << std::endl;

	std::cout << "x = " << Bisection(left, right) << std::endl;

	std::cout << "Time: " << t.elapsed() << std::endl;

	return 0;
}