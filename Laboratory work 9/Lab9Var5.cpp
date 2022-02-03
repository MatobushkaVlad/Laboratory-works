#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

/*�������� 3 ������������ ������ ������ �����, ����� � �������.
�������� ���, ����� ��� �� ����� �������� ������� ������������ �����.
��� ���������� ����� ����� ������ ������ ������ ������������. */

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Lab�9 Var5");

	int circle_x = 900;
	int rectangle_x = 800;
	int hexagon_x = 700;

	//����
	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color(249, 0, 0));
	circle.setOrigin(100, 100);
	circle.setPosition(circle_x, 100);

	//�������������
	sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
	rectangle.setFillColor(sf::Color(12, 198, 237));
	rectangle.setOrigin(100, 50);
	rectangle.setPosition(rectangle_x, 250);

	//�������������
	sf::CircleShape hexagon(100.f, 6);
	hexagon.setFillColor(sf::Color(204, 48, 208));
	hexagon.setOrigin(100, 100);
	hexagon.setPosition(hexagon_x, 400);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		} 

		//�������� ����� �����
		if (circle_x > 100)
		{
			circle.setPosition(circle_x, 100);
			circle_x = circle_x - 1;
		}

		//�������� �������������� �����
		if (rectangle_x > 100)
		{
			rectangle.setPosition(rectangle_x, 250);
			rectangle_x = rectangle_x - 1;
		}

		//�������� �������������� �����
		if (hexagon_x > 85)
		{
			hexagon.setPosition(hexagon_x, 400);
			hexagon_x = hexagon_x - 1;
		}

		//������� ����
		window.clear(sf::Color(120, 120, 120, 0));

		//����������� � �����
		window.draw(circle);
		window.draw(rectangle);
		window.draw(hexagon);

		//��������� �����, ��� ���� � ������
		window.display();

		std::this_thread::sleep_for(10ms);
	}

	return 0;
}