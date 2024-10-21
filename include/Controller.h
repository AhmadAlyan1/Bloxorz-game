#pragma once
#include "Level.h"
#include "Information.h"
#include "Menu.h"
#include <typeinfo>
#include "SFML/Audio.hpp"
#include <windows.h>

class Controller
{

public:
	Controller();
	void run();
	int m_levelNumber = 0;
	void drawPlayer(sf::RenderWindow& window);
	void checkCollision(sf::RenderWindow& window, Player* player);
	void setBackgrounds();
	void win(sf::RenderWindow& window);
	void lose(sf::RenderWindow& window);
		
private:
	sf::Sprite m_backgroundS;
	sf::Texture m_backgroundT;
	Player m_player;
	Level m_level;
	Information m_information;
	Menu m_menu;
	bool menu;
	sf::Music m_music;
	bool m_puase = false;
	bool m_end = false;
};