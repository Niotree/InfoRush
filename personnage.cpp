#include "Personnage.h"
#include "Constants.h"
#include <iostream>

sf::Texture Personnage::m_carTexture;

//M�thode pour initialiser
Personnage::Personnage(const sf::Color& color, const sf::Vector2f& pos) :
	m_transition(0),
	m_lane(Left),
	m_shape({ (int)PLAYER_SIZE, (int)PLAYER_HEIGHT }),
	m_key(sf::Keyboard::Space),
	m_center(pos)
{
	//m_shape.setFillColor(color);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height);
	m_shape.setPosition(m_center + sf::Vector2f{ LANE_WIDTH / 2.f * m_lane, 0 });
}

//M�thode pour mettre la texture
void Personnage::applyTexture()
{
	m_shape.setTexture(& m_carTexture);
}

//initialisation de la touche pour aller � gauche
void Personnage::setKeyLeft(sf::Keyboard::Key key)
{
	m_keyLeft = key;
}

//Initialisation de la touche pour aller � droite
void Personnage::setKeyRigth(sf::Keyboard::Key key)
{
	m_keyRight = key;
}


//M�thode pour modifier la colonne quand on appuie sur gauche
void Personnage::handleInputLeft(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == m_keyLeft && m_lane > -1)
	{
		setLane(static_cast<Lane>(m_lane - 2));
	}
}

//M�thode pour modifier la collone quand on appuie sur droite
void Personnage::handleInputRight(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == m_keyRight && m_lane < 3)
	{
		setLane(static_cast<Lane>(m_lane + 2));
	}
}

//M�thode pour reucperer la colonne ou est situer le personnage
Personnage::Lane Personnage::getLane()
{
	if (m_transition != 0) {
		if ((static_cast<int>(m_shape.getPosition().x / LANE_WIDTH) % 3) == 2)
		{
		return Personnage::Right;
		}
		else if ((static_cast<int>(m_shape.getPosition().x / LANE_WIDTH) % 3) == 0)
		{
			return Personnage::Left;
		}
		else return Personnage::Center;
	}
	return m_lane;
}

//M�thode pour reinialiser
void Personnage::reset(Lane lane)
{
	m_transition = 0;
	m_lane = lane;
	m_shape.setPosition(m_center + sf::Vector2f{ LANE_WIDTH / 2.f * m_lane, 0 });
}

//M�thode pour m�ttre a jour la position
void Personnage::update(float dt)
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

//M�thode pour dessiner le personnage
void Personnage::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	target.draw(m_shape, states);
}

//M�thode pour modifier la colonne 
void Personnage::setLane(Personnage::Lane lane)
{
	m_targetX = m_center.x + LANE_WIDTH / 2.f * lane;
	m_transition = lane - m_lane;
	m_lane = lane;
}
