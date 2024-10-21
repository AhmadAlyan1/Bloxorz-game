#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <sstream>


using std::ifstream;
using std::string;
using std::vector;
using std::cerr;


class Information
{

public:
	Information(int level);
	void drawInformation(sf::RenderWindow& window, int level, int moves);
	void Level(sf::RenderWindow& window, int level);

private:
	sf::Font m_font;
	sf::Text m_text;
	sf::Clock m_clock;
	sf::Time m_time;
	int m_level;
	int m_sec;
	int m_min;
};