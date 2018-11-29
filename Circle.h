#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Obstacle.h"

class Circle : public Obstacle
{
public:
	Obstacle(const sf::Color& color, const sf::Vector2f& pos);
	Circle();
	~Circle();
};

#endif //CRICLE_H

