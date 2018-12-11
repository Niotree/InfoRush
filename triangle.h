#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Obstacle.h"
#include <SFML/Graphics.hpp>


class Triangle : public Obstacle
{
public:
	/*enum Type
	{
		Cercle
	};*/
	Triangle(const sf::Color& color, const sf::Vector2f& pos);
	static sf::Texture m_triangleTexture;
	//Type getType();
protected:
	//Type m_type;
};

#endif //TRIANGLE_H

