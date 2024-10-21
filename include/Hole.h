#pragma once
#include "StaticChar.h"

class Player;

class Hole: public StaticChar {
public:
	Hole();
	void draw(sf::RenderWindow& window, sf::Vector2f pos);
	~Hole();
	virtual void collide(Player* object, Level& m_level);
	virtual void collide(Hole* object, Level& m_level) {};

private:
	sf::Texture t;
};