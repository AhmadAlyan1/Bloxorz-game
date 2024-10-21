#pragma once
#include "Tiles.h"
#include "Level.h"

class Player;

class SpecialTiles : public Tiles {
public:
	SpecialTiles();
	void draw(sf::RenderWindow& window, sf::Vector2f pos);
	~SpecialTiles();
	virtual void collide(Player* object, Level& m_level);
	virtual void collide(SpecialTiles* object, Level& m_level) {};

private:
	sf::Texture t;
};