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

void QUICKSORT(int a, int b, int mas[N])
{
	if (a >= b)
		return;
	int m = (a + b) / 2 + 1;
	int k = mas[m];
	int l = a - 1;
	int r = b + 1;
	while(1)
	{
		do
		{
			l++;
		} while (mas[l] < k);
		do
		{
			r--;
		} while (mas[r] > k);
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
	bool swapped = false;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				std::swap(mas[j], mas[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

int main()
{
	int mas[N];
	int a = 0;
	int b = N-1;

	for (int i = 0; i < N; i++)
		mas[i] = rand();

	Timer t;

	BUBBLESORT(mas, N);
	//QUICKSORT(a, b, mas);

	std::cout << "Time: " << t.elapsed() << std::endl;

	//for (int i = 0; i < N; i++)
		//std::cout << mas[i] << std::endl;

	return 0;
}