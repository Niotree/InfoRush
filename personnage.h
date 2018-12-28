#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>

class Personnage : public sf::Drawable
{
public:
	//Enumeration pour recupererle numero de la colonne
	enum Lane { Left = -1, Center=1, Right = 3 };
	//inisialisation de la voiture
	Personnage(const sf::Color& color, const sf::Vector2f& pos);
	//inisialisation du bouton de gauche
	void setKeyLeft(sf::Keyboard::Key key);
	//inisialisation du bouton de droite
	void setKeyRigth(sf::Keyboard::Key key);
	//Méthode pour modifier la collone quand on appuie sur gauche
	void handleInputLeft(const sf::Event& event);
	//Méthode pour modifier la collone quand on appuie sur droite
	void handleInputRight(const sf::Event& event);
	//Méthode qui renvoie la colonne ou si situe la voiture
	Lane getLane();
	void applyTexture();
	static sf::Texture m_carTexture;
	void update(float dt);
	void reset(Lane lane);
protected:
	//Méthode pour déssiner
	void draw(sf::RenderTarget& target, const sf::RenderStates states) const;
private:
	//Méthode pour changer la colonne 
	void setLane(Lane lane);

	//variable
	int m_transition;	//transition
	int m_targetX;
	Lane m_lane;	//colonne courant
	sf::RectangleShape m_shape;
	sf::Keyboard::Key m_key;
	sf::Keyboard::Key m_keyLeft;
	sf::Keyboard::Key m_keyRight;
	sf::Vector2f m_center;
};

#endif // CAR_H