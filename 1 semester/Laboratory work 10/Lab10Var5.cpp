#include <SFML/Graphics.hpp>
#include "circle.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

/*—оздайте N(0 < N < 100) кругов.
—делайте так, чтобы они из своих исходных позиций перемещались влево.
ѕри достижении левой части экрана фигуры должны остановитьс€. */

int main()
{

	const int width = 1680;
	const int height = 1050;
	const int N = 20;

	sf::RenderWindow window(sf::VideoMode(width, height), "All works!");

	std::vector<mt::Circle*> circles;
	for (int i = 0; i <= height; i += height / N)
		circles.push_back(new mt::Circle(1680, i, 20, 5));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (const auto& circle : circles)
		{
			circle->Move();
			if (circle->GetX() == 0) { circle->SetX(width); }
		}

		window.clear();

		for (const auto& circle : circles)
			window.draw(*circle->Get());

		window.display();

		std::this_thread::sleep_for(20ms);
	}
	
	for (const auto& circle : circles)
		delete circle;
	circles.clear();

	return 0;
}