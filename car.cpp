#include "Car.h"
#include "Constants.h"
#include <iostream>

sf::Texture Car::m_carTexture;

//Méthode pour initialiser
Car::Car(const sf::Color& color, const sf::Vector2f& pos) :
	m_transition(0),
	m_lane(Left),
	m_shape({ (int)OBJECT_SIZE, (int)CAR_HEIGHT }),
	m_key(sf::Keyboard::Space),
	m_center(pos)
{
	m_shape.setFillColor(color);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height);
	m_shape.setPosition(m_center + sf::Vector2f{ LANE_WIDTH / 2.f * m_lane, 0 });
}

//Méthode pour mettre la texture
void Car::applyTexture()
{
	m_shape.setTexture(&m_carTexture);
}

//initialisation de la touche pour aller à gauche
void Car::setKeyLeft(sf::Keyboard::Key key)
{
	m_keyLeft = key;
}

//Initialisation de la touche pour aller à droite
void Car::setKeyRigth(sf::Keyboard::Key key)
{
	m_keyRight = key;
}


//Méthode pour modifier la collone quand on appuie sur gauche
void Car::handleInputLeft(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == m_keyLeft && m_lane > -1)
	{
		setLane(static_cast<Lane>(m_lane - 2));
	}
}

//Méthode pour modifier la collone quand on appuie sur droite
void Car::handleInputRight(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == m_keyRight && m_lane < 3)
	{
		setLane(static_cast<Lane>(m_lane + 2));
	}
}

//Méthode pour reucperer la colonne ou est situer le personnage
Car::Lane Car::getLane()
{
	if (m_transition != 0) {
		if ((static_cast<int>(m_shape.getPosition().x / LANE_WIDTH) % 3) == 2)
		{
		return Car::Right;
		}
		else if ((static_cast<int>(m_shape.getPosition().x / LANE_WIDTH) % 3) == 0)
		{
			return Car::Left;
		}
		else return Car::Center;
	}
	return m_lane;
}

//Méthode pour reinialiser
void Car::reset(Lane lane)
{
	m_transition = 0;
	m_lane = lane;
	m_shape.setPosition(m_center + sf::Vector2f{ LANE_WIDTH / 2.f * m_lane, 0 });
}

//Méthode pour méttre a jour la position
void Car::update(float dt)
{
	if (m_transition > 0)
	{
		m_shape.move(CAR_TRANSITION_SPEED * dt, 0);
		if (m_shape.getPosition().x >= m_targetX)
		{
			m_transition = 0;
			m_shape.setPosition(m_targetX, m_shape.getPosition().y);
		}
	}
	else if (m_transition < 0)
	{
		m_shape.move(-CAR_TRANSITION_SPEED * dt, 0);
		if (m_shape.getPosition().x <= m_targetX)
		{
			m_transition = 0;
			m_shape.setPosition(m_targetX, m_shape.getPosition().y);
		}
	}
}

//Méthode pour dessiner le personnage
void Car::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	target.draw(m_shape, states);
}

//Méthode pour modifier la colonne 
void Car::setLane(Car::Lane lane)
{
	m_targetX = m_center.x + LANE_WIDTH / 2.f * lane;
	m_transition = lane - m_lane;
	m_lane = lane;
}
