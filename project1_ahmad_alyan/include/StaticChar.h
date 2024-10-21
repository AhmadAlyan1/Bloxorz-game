#pragma once
#include "Characters.h"

class StaticChar : public Characters {
public:
	virtual void draw(sf::RenderWindow& window, sf::Vector2f pos) {}
};