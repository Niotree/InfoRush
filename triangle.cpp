#include "Triangle.h"
#include "Constants.h"

/*Triangle::Type Triangle::getType()
{
	return m_type;
}*/

Triangle::Triangle(const sf::Color& color, const sf::Vector2f& pos)
{
	m_shape = std::unique_ptr<sf::Shape>(new sf::CircleShape(OBJECT_SIZE / 2));
	m_shape->setTexture(&m_triangleTexture);

	m_shape->setPosition(pos);
	m_shape->setFillColor(color);
	m_shape->setOrigin(m_shape->getLocalBounds().width / 2, 0);
}