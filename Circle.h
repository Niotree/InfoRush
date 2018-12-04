#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Obstacle.h"

class Circle : public Obstacle
{
public:
	/*enum Type
	{
		Cercle
	};*/
	Circle(const sf::Color& color, const sf::Vector2f& pos);
	static sf::Texture m_circleTexture;
	//Type getType();
protected:
	//Type m_type;
};

#endif //CRICLE_H

