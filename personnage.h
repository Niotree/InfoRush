#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>

/**
  * Class personnage repr�sentant le personnage du jeu
  *
  *@author EHANNO Aur�lie & LE FALHER Antoine
  */
class Personnage : public sf::Drawable
{
public:
	/**
	 * Enumeration pour recuperer le numero de la colonne
	 * Repr�sente les lignes de jeu
	 */
	enum Lane { Left = -1, Center=1, Right = 3 };
	/**
	  * Constructeur
	  * @param color couleur du personnage
	  * @param pos position du personnage
	  */
	Personnage(const sf::Color& color, const sf::Vector2f& pos);
	/**
	  * M�thode d'inisialisation du bouton representant le deplace�ent � gauche
	  * @param key le nom de la touche
	  */
	void setKeyLeft(sf::Keyboard::Key key);
	/**
	  * M�thode d'inisialisation du bouton representant le deplace�ent � droite
	  * @param key le nom de la touche
	  */
	void setKeyRigth(sf::Keyboard::Key key);
	/**
	  * M�thode pour modifier la colonne quand on appuie sur gauche
	  * @param event l'�v�nement par rapport � la touche
	  */
	void handleInputLeft(const sf::Event& event);
	/**
	  * M�thode pour modifier la colonne quand on appuie sur droite
	  * @param event l'�v�nement par rapport � la touche
	  */
	void handleInputRight(const sf::Event& event);
	/**
	  * M�thode pour r�cuperer la colonne courante
	  */
	Lane getLane();
	/**
	  * M�thode qui applique la texture choisi
	  */
	void applyTexture();
	/**
	  * Variable de la texture du personnage
	  */
	static sf::Texture m_carTexture;
	/**
	  * M�thode qui met � jour le jeu
	  * @param dt vitesse
	  */
	void update(float dt);
	/**
	  * M�thode qui efface le personnage de la colonne mis en param�tre
	  * @param lane la colonne o� l'on efface
	  */
	void reset(Lane lane);
protected:
	/**
	  * M�thode qui dessine le personnage
	  * @param target la cible du rendu (m_shape)
	  * @param states etat d'utilisation
	  */
	void draw(sf::RenderTarget& target, const sf::RenderStates states) const;
private:
	/**
	  * M�thode qui remet � jour la colonne courante
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
	  * variable repr�sentant le personnage
	  */
	sf::RectangleShape m_shape;
	/**
	  * variable repr�sentant la touche de d�marrage de la partie
	  */
	sf::Keyboard::Key m_key;
	/**
	  * variable r�preeantant la touche de gauche
	  */
	sf::Keyboard::Key m_keyLeft;
	/**
	  * variable r�presentant la touche de droite
	  */
	sf::Keyboard::Key m_keyRight;
	sf::Vector2f m_center;
};

#endif // CAR_H