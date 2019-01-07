#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SFML/Graphics/Color.hpp>

/**
  *Classe Header qui regroupe toutes les constantes du jeu
  *
  *@author EHANNO Aurélie & LE FALHER Antoine
  */

/** 
  * Largeur d'une colonne */
  */
const int LANE_WIDTH = 80; 
 /** 
   * Taille des obstacles
   */
const int OBJECT_SIZE = LANE_WIDTH/1.25;
/** 
  * Largeur du personnage
  */
const int PLAYER_SIZE = LANE_WIDTH/1.5; 
 /**
   * Hauteur du personnage
   */
const int PLAYER_HEIGHT = LANE_WIDTH;
/** 
  * Hauteur de la fenetre 
  */
const int WINDOW_HEIGHT = 600; 
/**
  * Distance entre les objets
  */
const int SPAWN_DIST = 250; 
/** 
  * Vitesse initialie 
  */
const int INITIAL_VELOCITY = 220; 
/**
  * Acceleration 
  */
const int ACCELERATION = 5;
/** 
  * Objet sur l'ecran 
  */
const int OBJS_ON_SCREEN = 2 * (1 + WINDOW_HEIGHT / (SPAWN_DIST + OBJECT_SIZE)); 
/** 
  * Transition de la vitesse pour le personnage
  */
const int CAR_TRANSITION_SPEED = 300; 

/**
  * Couleur des obstacles
  */
const sf::Color COLOR = sf::Color(0xFFFFFFFF); 
/**
  * Couleur de fond
  */
const sf::Color BACKGROUND_COLOR = sf::Color(0x211357FF); 
/**
  * Couleur du joueur 
  */
const sf::Color PLAYER_COLOR = sf::Color(0xFFFFFFFF);
#endif //CONSTANTS_H