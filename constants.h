#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SFML/Graphics/Color.hpp>

//Classe Header qui regroupe toutes les contantes du jeu
const int LANE_WIDTH = 80;
const int OBJECT_SIZE = LANE_WIDTH/1.25;
const int CAR_SIZE = LANE_WIDTH/1.5;
const int CAR_HEIGHT = LANE_WIDTH;
const int WINDOW_HEIGHT = 600;
const int SPAWN_DIST = 250;
const int INITIAL_VELOCITY = 220;
const int ACCELERATION = 5;
const int OBJS_ON_SCREEN = 2 * (1 + WINDOW_HEIGHT / (SPAWN_DIST + OBJECT_SIZE));
const int CAR_TRANSITION_SPEED = 300;

const sf::Color COLOR = sf::Color(0xFFFFFFFF);
const sf::Color BACKGROUND_COLOR = sf::Color(0x211357FF);
const sf::Color CAR_COLOR = sf::Color(0xFFFFFFFF);
#endif //CONSTANTS_H