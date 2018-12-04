#include "Obstacle.h"
#include "Constants.h"

//sf::Texture Obstacle::m_circleTexture;
//sf::Texture Obstacle::m_triangleTexture;

/*Obstacle::Obstacle() :
	m_type(type)
{
	if (type == Circle)
	{
		m_shape = std::unique_ptr<sf::Shape>(new sf::CircleShape(OBJECT_SIZE / 2));
		m_shape->setTexture(&m_circleTexture);
	}
	else
	{
		m_shape = std::unique_ptr<sf::Shape>(new sf::RectangleShape({ (int)OBJECT_SIZE, (int)OBJECT_SIZE }));
		m_shape->setTexture(&m_triangleTexture);
	}

	m_shape->setPosition(pos);
	m_shape->setFillColor(color);
	m_shape->setOrigin(m_shape->getLocalBounds().width / 2, 0);
}*/

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_shape, states);
}

sf::Shape& Obstacle::getShape()
{
	return *m_shape;
}