#include <iostream>
#include <chrono>
#define N 10

class Timer
{
private:
	// ���������� ����� ������������ ��� �������� ������� � ��������� �����
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

void QUICKSORT(int a, int b, int mas[N])
{
	if (a >= b)
		return;
	int m = rand() % (b - a + 1) + a;
	int k = mas[m];
	int l = a - 1;
	int r = b + 1;
	while (1)
	{
		while (mas[l] < k)
			l = l + 1;
		while (mas[r] > k)
			r = r - 1;
		if (l >= r)
			break;
		std::swap(mas[l], mas[r]);
	}
	r = l;
	l = l - 1;
	QUICKSORT(a, l, mas);
	QUICKSORT(r, b, mas);
}

void BUBBLESORT(int mas[N], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (mas[i] > mas[i+1])
			std::swap(mas[i], mas[i + 1]);
	}
}

int main()
{
	int mas[N];
	int a = 0;
	int b = sizeof(mas);

	for (int i = 0; i < N; i++)
		mas[i] = rand();

	Timer t;

	QUICKSORT(a, b, mas);

	std::cout << "Time: " << t.elapsed() << std::endl;

	return 0;
}