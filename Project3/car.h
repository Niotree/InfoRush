#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>

class Car : public sf::Drawable
{
public:
	enum Lane { Left = -2, Center=1, Right = 2 };
	Car(const sf::Color& color, const sf::Vector2f& pos);
	void setKeyLeft(sf::Keyboard::Key key);
	void setKeyRigth(sf::Keyboard::Key key);
	void handleInputLeft(const sf::Event& event);
	void handleInputRight(const sf::Event& event);
	Lane getLane();
	void applyTexture();
	static sf::Texture m_carTexture;
	void update(float dt);
	void reset(Lane lane);
protected:
	void draw(sf::RenderTarget& target, const sf::RenderStates states) const;
private:
	void setLane(Lane lane);

	int m_transition;
	int m_targetX;
	Lane m_lane;
	sf::RectangleShape m_shape;
	sf::Keyboard::Key m_key;
	sf::Keyboard::Key m_keyLeft;
	sf::Keyboard::Key m_keyRight;
	sf::Vector2f m_center;
};

#endif // CAR_H
