#define SFML_NO_DEPRECATED_WARNINGS
#include "Game.h"
#include <cstdlib>
#include <iterator>
#include <deque>

//Essai sprite animé

Game::Game() :

	//Initilisation
	m_window(sf::VideoMode(LANE_WIDTH * 3, WINDOW_HEIGHT), "InfoRush", sf::Style::Close | sf::Style::Titlebar),
	m_dividers(sf::Lines, 6),
	m_leftCar(CAR_COLOR, sf::Vector2f{ (int)LANE_WIDTH, (int)WINDOW_HEIGHT }),
	m_overlayBg({ (int)LANE_WIDTH * 3, (int)WINDOW_HEIGHT }),
	m_playing(false)
{
	m_window.setVerticalSyncEnabled(true);

	m_dividers[0] = sf::Vertex({ (int)LANE_WIDTH, 0 }, sf::Color(180, 180, 180));
	m_dividers[1] = sf::Vertex({ (int)LANE_WIDTH, (int)WINDOW_HEIGHT }, sf::Color(180, 180, 180));
	m_dividers[2] = sf::Vertex({ (int)LANE_WIDTH * 3, 0 }, sf::Color(180, 180, 180));
	m_dividers[3] = sf::Vertex({ (int)LANE_WIDTH * 3, (int)WINDOW_HEIGHT }, sf::Color(180, 180, 180));
	m_dividers[4] = sf::Vertex({ (int)LANE_WIDTH * 2, 0 }, sf::Color(180, 180, 180));
	m_dividers[5] = sf::Vertex({ (int)LANE_WIDTH * 2, (int)WINDOW_HEIGHT }, sf::Color(180, 180, 180));
	
	//Initilisation des touches pour se déplacer
	m_leftCar.setKeyRigth(sf::Keyboard::D);
	m_leftCar.setKeyLeft(sf::Keyboard::Q);

	//affichage du début du jeu
	m_font.loadFromFile("assets/font.ttf");
	m_prompt.setFont(m_font);
	m_prompt.setColor(sf::Color(180, 180, 180));
	m_prompt.setCharacterSize(15);
	m_prompt.setString("   Evite les bus, mange les donuts.\n"
		"  Q pour aller à gauche et D à droite.\n"
		"  Appuie sur Espace pour commencer.");
	m_prompt.setPosition((m_window.getSize().x - m_prompt.getLocalBounds().width) / 2.f,
		(m_window.getSize().y - m_prompt.getLocalBounds().height) / 2.f);

	m_overlayBg.setFillColor(sf::Color(0, 0, 0, 100));

	//Ce qui s'affiche si le chargement de images échou
	Circle::m_circleTexture.loadFromFile("assets/beignet.png");
	Triangle::m_triangleTexture.loadFromFile("assets/bus.png");
	Car::m_carTexture.loadFromFile("assets/sprite2.png");
	//sf::Sprite sprite(Car::m_carTexture, sf::IntRect(0, 0, 300,400));
	m_leftCar.applyTexture();
	m_leftCar.reset(Car::Center);
	m_bgMusic.openFromFile("assets/bgm.ogg");
	m_bgMusic.setLoop(true);
}

void Game::newGame()
{
	if (m_bgMusic.getStatus() != sf::SoundSource::Playing)
		m_bgMusic.play();
	m_obstacles.clear();
	m_score = 1 - OBJS_ON_SCREEN / 2;
	m_velocity = INITIAL_VELOCITY;
	m_distance = SPAWN_DIST;
	m_playing = true;
	m_leftCar.reset(Car::Center);
}

/*
	Méthode pour run le jeu
*/
void Game::run()
{
	srand(time(nullptr));
	sf::Event event;
	//boucle qui recupère le evenement durant le jeu
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			//le jeu est fini
			if (event.type == sf::Event::Closed)
				m_window.close();
			//recupère les otuche pour le déplacement
			if (m_playing)
			{
				m_leftCar.handleInputRight(event);
				m_leftCar.handleInputLeft(event);
			}
			//pour le debut du jeu
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				m_playing = true;
				newGame();
			}
		}

		auto dt = m_timer.restart().asSeconds();

		if (m_playing)
		{
			m_velocity += ACCELERATION * dt;
			m_distance += m_velocity * dt;
			//création des obstace
			if (m_distance > SPAWN_DIST)
			{
				++m_score;
				srand (time(NULL));
				int rand = std::rand() % 2;
				Obstacle *obs=NULL;
				//ajout d'un cercle
				if (rand == 1) {
					try {
						Circle *circle = new Circle(COLOR, sf::Vector2f{ LANE_WIDTH / 2.f + LANE_WIDTH * (std::rand() % 3), 0 });
						if (circle == NULL) { throw MyException(); }
						else obs = circle;
					}
					catch (MyException& e) {
						std::cout << e.what() << std::endl;
					}
				}
				//ajout d'un triangle
				else {
					 try {
						Triangle *triangle = new Triangle(COLOR, sf::Vector2f{ LANE_WIDTH / 2.f + LANE_WIDTH * (std::rand() % 3), 0 });
						if (triangle == NULL) { throw MyException(); }
						else obs = triangle;
					}
					catch (MyException& e) {
						std::cout << e.what() << std::endl;
					}
				}
				//Surdéfinition Opérateur + (Ajout d'un obstacle dans la queue)
				(*this) + obs;
				m_distance -= SPAWN_DIST;
			}

			for (auto it = m_obstacles.begin(); it != m_obstacles.end(); ++it)
			{
				(*it)->getShape().move(0, m_velocity * dt);
				if ((*it)->getShape().getGlobalBounds().top > WINDOW_HEIGHT - CAR_HEIGHT - OBJECT_SIZE
					&& (*it)->getShape().getGlobalBounds().top < WINDOW_HEIGHT - OBJECT_SIZE)
				{
					//déplacement du personnage
					auto& car = m_leftCar;
					Car::Lane lane;
					if (static_cast<int>((*it)->getShape().getGlobalBounds().left / LANE_WIDTH) % 3 == 2) {
						lane = Car::Right;
					}
					else if (static_cast<int>((*it)->getShape().getGlobalBounds().left / LANE_WIDTH) % 3 == 0) {
						lane = Car::Left;
					}
					else lane = Car::Center;
					//verification s'il a pris un obstacle
					if (lane == car.getLane())
					{
						//Rentre dans le if s'il a pris un triangle
						Circle *c = dynamic_cast<Circle *>(*it);
						if (c == NULL)
						{
							gameOver();
							break;
						}
					it = std::prev(m_obstacles.erase(it));
					}
				}
				else if ((*it)->getShape().getGlobalBounds().top > WINDOW_HEIGHT)
				{
					//Rentre dans le if s'il a oublié le cercle
					Circle *c = dynamic_cast<Circle *>(*it);
					if (c != NULL)
					{
						gameOver();
						break;
					}
				it = std::prev(m_obstacles.erase(it));
				}
			}

			

			m_leftCar.update(dt);
		}

		//affichage
		m_window.clear(BACKGROUND_COLOR);
		m_window.draw(m_dividers);
		int i = 0;
		//affichage obstacle
		for (auto *o : m_obstacles) 
			m_window.draw(*o);

		m_window.draw(m_leftCar);
		if (!m_playing)
		{
			m_window.draw(m_overlayBg);
			m_window.draw(m_prompt);
		}
		m_prompt_score.setFont(m_font);
		m_prompt_score.setColor(sf::Color(180, 180, 180));
		m_prompt_score.setCharacterSize(15);
		m_prompt_score.setString("  Score :"+ std::to_string(m_score));
		m_prompt_score.setPosition(10,
			10);
		m_window.draw(m_prompt_score);
		m_window.display();
	}
}

/*
	Méthode qui vérifie si le jeu est fini ou pas 
	Il renvoie oui si le personnage prend un triangle ou s'il loupe un cercle
	sinon renvoie faux
*/
bool Game::isGameOver(Car::Lane carLane, Car::Lane objLane, Obstacle *o)
{
	if ((carLane == objLane && dynamic_cast<Circle *>(o) == NULL)
		|| (carLane != objLane && dynamic_cast<Triangle *>(o) == NULL))
		return false;
	return true;
}
/*
	Méthode qui renvoie le text de fin du jeu avec le score
*/
void Game::gameOver()
{
	m_playing = false;
	m_prompt.setString(" Votre score : " + std::to_string(m_score) + ".\n"
		" Espce pour rejouer.");
	m_prompt.setPosition(0,
		(m_window.getSize().y - m_prompt.getLocalBounds().height) / 2.f);
}

void Game::operator+ ( Obstacle* o)
{
	m_obstacles.emplace_front(o);
}

