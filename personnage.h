#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>

/**
  * Class personnage représentant le personnage du jeu
  *
  *@author EHANNO Aurélie & LE FALHER Antoine
  */
class Personnage : public sf::Drawable
{
public:
	/**
	 * Enumeration pour recuperer le numero de la colonne
	 * Représente les lignes de jeu
	 */
	enum Lane { Left = -1, Center=1, Right = 3 };
	/**
	  * Constructeur
	  * @param color couleur du personnage
	  * @param pos position du personnage
	  */
	Personnage(const sf::Color& color, const sf::Vector2f& pos);
	/**
	  * Méthode d'inisialisation du bouton representant le deplaceùent à gauche
	  * @param key le nom de la touche
	  */
	void setKeyLeft(sf::Keyboard::Key key);
	/**
	  * Méthode d'inisialisation du bouton representant le deplaceùent à droite
	  * @param key le nom de la touche
	  */
	void setKeyRigth(sf::Keyboard::Key key);
	/**
	  * Méthode pour modifier la colonne quand on appuie sur gauche
	  * @param event l'événement par rapport à la touche
	  */
	void handleInputLeft(const sf::Event& event);
	/**
	  * Méthode pour modifier la colonne quand on appuie sur droite
	  * @param event l'événement par rapport à la touche
	  */
	void handleInputRight(const sf::Event& event);
	/**
	  * Méthode pour récuperer la colonne courante
	  */
	Lane getLane();
	/**
	  * Méthode qui applique la texture choisi
	  */
	void applyTexture();
	/**
	  * Variable de la texture du personnage
	  */
	static sf::Texture m_carTexture;
	/**
	  * Méthode qui met à jour le jeu
	  * @param dt vitesse
	  */
	void update(float dt);
	/**
	  * Méthode qui efface le personnage de la colonne mis en paramètre
	  * @param lane la colonne où l'on efface
	  */
	void reset(Lane lane);
protected:
	/**
	  * Méthode qui dessine le personnage
	  * @param target la cible du rendu (m_shape)
	  * @param states etat d'utilisation
	  */
	void draw(sf::RenderTarget& target, const sf::RenderStates states) const;
private:
	/**
	  * Méthode qui remet à jour la colonne courante
	  * @param lane la colonne
	  */
	void setLane(Lane lane);

	/**
	  * variable de la transition entre les lignes
	  */
	int m_transition;
	/**
	  * variable de la cible
	  */
	int m_targetX;
	/**
	  * variable representant le colonne courante
	  */
	Lane m_lane;
	/**
	  * variable représentant le personnage
	  */
	sf::RectangleShape m_shape;
	/**
	  * variable représentant la touche de démarrage de la partie
	  */
	sf::Keyboard::Key m_key;
	/**
	  * variable répreeantant la touche de gauche
	  */
	sf::Keyboard::Key m_keyLeft;
	/**
	  * variable répresentant la touche de droite
	  */
	sf::Keyboard::Key m_keyRight;
	sf::Vector2f m_center;
};

#endif // CAR_H