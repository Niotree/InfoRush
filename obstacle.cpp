#include "Obstacle.h"
#include "Constants.h"

//Méthode pour dessiner l'obstacle
void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_shape, states);
}

/*Méthode pour récuperer la forme
renvoie le pointeur de l'obstacle*/
sf::Shape& Obstacle::getShape()
{
	return *m_shape;
}