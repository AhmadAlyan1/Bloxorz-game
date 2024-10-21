#include "Win.h"
#include "Player.h"

Win::Win()
{
	t.loadFromFile("Win.png");
	m_sprite.setTexture(t);
	m_sprite.setScale(sf::Vector2f(((float)70 / m_sprite.getGlobalBounds().height),
		((float)70 / m_sprite.getGlobalBounds().height)));
}


void Win::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

Win::~Win()
{
}

void Win::collide(Player* object, Level& m_level)
{
	object->collide(this, m_level);
}