#pragma once
#include "StaticChar.h"

class Player;

class Win : public StaticChar {
public:
	Win();
	void draw(sf::RenderWindow& window, sf::Vector2f pos);
	~Win();
	virtual void collide(Player* object, Level& m_level);
	virtual void collide(Win* object, Level& m_level) {};

private:
	sf::Texture t;
};