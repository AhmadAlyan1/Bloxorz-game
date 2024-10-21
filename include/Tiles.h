#pragma once
#include "StaticChar.h"

class Player;

class Tiles : public StaticChar {
public:
	Tiles();
	void draw(sf::RenderWindow& window, sf::Vector2f pos);
	~Tiles();
	virtual void collide(Player* object, Level& m_level);
	virtual void collide(Tiles* object, Level& m_level) {};

private:
	sf::Texture t;
};