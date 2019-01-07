#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

/**
  * Class Obstacle repr�sentant les Obstacle qui l'on peut rencontrer durant le jeu
  *
  *@author EHANNO Aur�lie & LE FALHER Antoine
  */
class Obstacle : public sf::Drawable
{
public:
	/**
	  * M�thode pour renvoyer la forme de l'Obstacle
	  */
	sf::Shape& getShape();
protected:
	/**
	  * M�thode qui dessine l'obstacle
	  * @param target la cible qui l'on dessine
	  * @param states l'etat de la cible
	  */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/**
	  * La forme de l'obstacle
	  */
	std::unique_ptr<sf::Shape> m_shape;
	
};
#endif // OBSTACLE_H
