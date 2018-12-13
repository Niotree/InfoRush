#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

//Class Obstacle
class Obstacle : public sf::Drawable
{
public:
	//Méthode pour récuperer la forme de l'obstacle
	sf::Shape& getShape();
protected:
	//Dessine l'obstacle
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//La forme
	std::unique_ptr<sf::Shape> m_shape;
	
};
#endif // OBSTACLE_H
