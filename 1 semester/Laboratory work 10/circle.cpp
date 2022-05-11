#include "circle.hpp"

namespace mt
{
	Circle::Circle(int x, int y, float r, float velocity)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_velocity = velocity;
		m_shape = new sf::CircleShape(m_r);
		m_shape->setOrigin(m_r, m_r);
		m_shape->setFillColor(sf::Color::White);
		m_shape->setPosition((m_x - m_r),(m_y + m_r));
	}

	Circle::~Circle()
	{
		delete m_shape;
	}

	sf::CircleShape* Circle::Get() { return m_shape; }

	void Circle::Move()
	{
		m_x -= m_velocity;
		m_shape->setPosition(m_x, m_y);
	}

	void Circle::SetX(int x)
	{
		SetVelocity(0);
		m_x = x - (x - m_r);
		m_shape->setPosition(m_x, m_y);
	}

	int Circle::GetX() { return m_x; }

	void Circle::SetVelocity(int velocity)
	{
		m_velocity = velocity;
	}
}