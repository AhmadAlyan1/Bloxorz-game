#include "Hole.h"
#include "Player.h"

Hole::Hole()
{
	t.loadFromFile("Hole.png");
	m_sprite.setTexture(t);
	m_sprite.setScale(sf::Vector2f(((float)70 / m_sprite.getGlobalBounds().height),
		((float)70 / m_sprite.getGlobalBounds().height)));

}


void Hole::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

Hole::~Hole()
{
}

void Hole::collide(Player* object, Level& m_level)
{
	object->collide(this, m_level);
}

