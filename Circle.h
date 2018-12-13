#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

//Classe cercle héritant d'Obstacle
class Circle : public Obstacle
{
public:
	//Méthode d'initialisation
	Circle(const sf::Color& color, const sf::Vector2f& pos);
	//Texture
	static sf::Texture m_circleTexture;
};

#endif //CRICLE_H

