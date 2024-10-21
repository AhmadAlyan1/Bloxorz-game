#pragma once
#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "SFML/Audio.hpp"

class Player;
class Tiles;
class Hole;
class Level;
class Win;
class SpecialTiles;

enum Object_t { PLAYER, TILES, HOLE, WIN};

class Characters{
public:
	virtual void collide(Characters* object, Level& m_level) {};
	 virtual void collide(Player* object, Level& m_level) {};
	 virtual void collide(Tiles* object, Level& m_level) {};
	 virtual void collide(Hole* object, Level& m_level) {};
	 virtual void collide(Win* object, Level& m_level) {};
	 virtual void collide(SpecialTiles* object, Level& m_level) {};

protected:
	Object_t m_type;
	sf::Sprite m_sprite;
};