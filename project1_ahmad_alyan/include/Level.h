#pragma once

#include "Player.h"
#include "Tiles.h"
#include "SpecialTiles.h"
#include "Hole.h"
#include "Win.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class Level
{
public:
	Level();
	Level(Player& m_player, int levelNumber);

	sf::Vector2f getBoardSize();
	void read_level(Player& m_player,int levelNumber);
	void setPlayer(Player& m_player, sf::Vector2f pos);
	StaticChar* getIcon(sf::Vector2f pos);
	void setIcon(sf::Vector2f pos);
	void drawStatic(sf::RenderWindow& window);
	int levelsNum();

private:
	void open_file(ifstream& input, int levelNumber);
	void add_to_board(char c, size_t i, size_t j, Player& m_player);
	void setBoardSize(int rows, int cols);
	vector <vector<std::unique_ptr<StaticChar>>> m_board;
	int m_levels;
};


