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

/**
  * Class Game permettant d'intialiser le jeu et de le mettre � jour au fur et � mesure
  *
  *@author EHANNO Aur�lie & LE FALHER Antoine
  */
class Game
{
public:
	/**
	  * Constructeur
	  */
	Game();

	/**
	  * M�thode run pour lancer le jeu
	  */
	void run();
private:
	/**
	  * M�thode pour rejouer
	  * Elle r�initialise le jeu au d�part
	  */
	void newGame();

	/**
	  *M�thode affichant la fin du jeu
	  */
	void gameOver();

	/**
	  *M�thode pour savoir si la partie est perdu ou non 
	  *
	  *@param carLane colonne ou se situe le personnage
	  *@param objLane colonne ou se situe l'obstacle
	  *@param *o pointeur sur l'obstacle
	  */
	static bool isGameOver(Personnage::Lane carLane, Personnage::Lane objLane,Obstacle *o);

	/**
	  * M�thode pour l'exception si il y a un pointeur null dans notre deque d'obstacle
	  */
	struct MyException : public exception {
		const char * what() const throw () {
			return "valeur null dans la queue";
		}
	};

	/**
	  * Redifinition de la m�thode +
	  */
	void operator+(Obstacle* O);

	/**
	  * Variable de la fenetre de jeu
	  */
	sf::RenderWindow m_window;

	sf::VertexArray m_dividers;
	/**
	  * deque contenant les pointeurs sur les obstacles
	  */
	deque<Obstacle *> m_obstacles;

	/**
	  * Le personnage du jeu
	  */
	Personnage m_player;

	/**
	  *Variable pour le style de l'�criture des textes
	  */
	sf::Font m_font;
	/**
	  * Text de debut et fin de partie
	  */
	sf::Text m_prompt;
	/**
	  * Texte de score
	  */
	sf::Text m_prompt_score;
	/**
	  * fond pour le texte
	  */
	sf::RectangleShape m_overlayBg;

	/**
	  * La musique de fond
	  */
	sf::Music m_bgMusic;

	/**
	  * Timer
	  */
	sf::Clock m_timer;
	/**
	  * Score du joueur
	  */
	int m_score;
	/**
	  * Boolean pour savoir si on joue ou non
	  */
	bool m_playing;
	/**
	  * La distance
	  */
	float m_distance,
		m_velocity;
};

#endif // GAME_H
