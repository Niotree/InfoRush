#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

/**
  * Class Circle heritant d'Obstacle
  * Représenté par un donut dans le jeu
  *
  *@author EHANNO Aurélie & LE FALHER Antoine
  */
class Circle : public Obstacle
{
public:
	/**
	  *Constructeur
	  @param color couleur de l'objet
	  @param pos position de l'objet
	*/
	Circle(const sf::Color& color, const sf::Vector2f& pos);
	/**
	  * Image du donut
	  */
	static sf::Texture m_circleTexture;
};

#endif //CRICLE_H

