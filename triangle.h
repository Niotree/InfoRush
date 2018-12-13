#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Obstacle.h"
#include <SFML/Graphics.hpp>
//Class triangle heritant d'Obstacle

class Triangle : public Obstacle
{
public:
	//Méthode d'inisialisation
	Triangle(const sf::Color& color, const sf::Vector2f& pos);
	//texture
	static sf::Texture m_triangleTexture;
};

#endif //TRIANGLE_H

