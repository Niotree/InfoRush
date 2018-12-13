#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

//Classe cercle h�ritant d'Obstacle
class Circle : public Obstacle
{
public:
	//M�thode d'initialisation
	Circle(const sf::Color& color, const sf::Vector2f& pos);
	//Texture
	static sf::Texture m_circleTexture;
};

#endif //CRICLE_H

