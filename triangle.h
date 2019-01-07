#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

/**
  * Class triangle heritant d'Obstacle
  * Représenté par un bus dans le jeu
  *
  *@author EHANNO Aurélie & LE FALHER Antoine
  */

class Triangle : public Obstacle
{
public:
	/**
	  *Constructeur
	  @param color couleur de l'objet
	  @param pos position de l'objet
	*/
	Triangle(const sf::Color& color, const sf::Vector2f& pos);
	/**
	  * Image du bus
	  */
	static sf::Texture m_triangleTexture;
};

#endif //TRIANGLE_H

