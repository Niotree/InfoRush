#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <deque>
#include <memory>
#include <algorithm>

#include "Obstacle.h"
#include "Constants.h"
#include "Circle.h"
#include "Triangle.h"
#include "personnage.h"

using namespace std;

class Game
{
public:
	//M�thode pour jouer
	Game();
	void run();
private:
	//m�thode pour rejouer
	void newGame();
	//M�thode quand la partie est perdu
	void gameOver();
	//M�thode pour savoir si la partie est perdu ou non 
	static bool isGameOver(Personnage::Lane carLane, Personnage::Lane objLane,Obstacle *o);
	struct MyException : public exception {
		const char * what() const throw () {
			return "valeur null dans la queue";
		}
	};

	void operator+(Obstacle* O);

	//fenetre de jeu
	sf::RenderWindow m_window;

	sf::VertexArray m_dividers;
	deque<Obstacle *> m_obstacles;	//deque comportant les obstacles
	Personnage m_player; //le personnage

	//variable pour le jeu
	sf::Font m_font;
	sf::Sprite sprite;
	sf::Text m_prompt;
	sf::Text m_prompt_score;
	sf::RectangleShape m_overlayBg;

	sf::Music m_bgMusic;

	sf::Clock m_timer;
	int m_score;
	bool m_playing;
	float m_distance,
		m_velocity;
};

#endif // GAME_H
