#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	class Circle
	{
	public:
		Circle(int x, int y, float r, float velocity);

		~Circle();

		sf::CircleShape* Get();

		void Move();

		void SetX(int x);

		int GetX();

		void SetVelocity(int velocity);
	private:

		int m_x, m_y;
		float m_r, m_velocity;
		sf::CircleShape* m_shape;
	};

}