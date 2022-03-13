#include <iostream>
#include <chrono>
const int N = 5000;
const int M = 1000;

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

struct List
{
	List* next;
	int number;
};

void add(List* head, int number)
{
	List* p = new List;
	p->number = number;

	p->next = head->next;
	head->next = p;
}

void clear(List* head)
{
	List* q;
	List* p = head->next;
	while (p != nullptr)
	{
		q = p;
		p = p->next;
		delete q;
	}

}

void print(List* head)
{
	List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->number << std::endl;
		p = p->next;
	}
}

 
void maxel(List* head)
{
	List* p = head->next;
	List* q = p->next;
	int d;
	while (p->next->next != nullptr)
	{
		if (q > p)
		{
			d = q->number;
			q = q->next;
			p = p->next;
		}
		p = p->next;
	}
	//std::cout << d << std::endl;
}

int main()
{
	List* head = new List;
	head->next = nullptr;

	int d;

	for (int i = 0; i < N; i++)
	{
		d = rand();
		add(head, d);
	}

	//print(head);
	std::cout << "=========================" << std::endl;

	Timer t;

	for(int i = 0; i < M; i++)
		maxel(head);

	std::cout << "Time: " << t.elapsed() << std::endl;

	clear(head);

	delete head;
	return 0;
}