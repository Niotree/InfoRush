#include "Circle.h"
#include "Constants.h"

sf::Texture Circle::m_circleTexture;

//Initialisation du Cercle
Circle::Circle(const sf::Color& color, const sf::Vector2f& pos)
{
	m_shape = std::unique_ptr<sf::Shape>(new sf::CircleShape(OBJECT_SIZE / 2));
	m_shape->setTexture(&m_circleTexture);

	m_shape->setPosition(pos);
	m_shape->setFillColor(color);
	m_shape->setOrigin(m_shape->getLocalBounds().width / 2, 0);
}