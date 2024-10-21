#include "SpecialTiles.h"
#include "Player.h"


SpecialTiles::SpecialTiles()
{
	t.loadFromFile("SpecialTile.jpg");
	m_sprite.setTexture(t);
	m_sprite.setScale(0.07,0.07);
}

void SpecialTiles::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

SpecialTiles::~SpecialTiles()
{
}

void SpecialTiles::collide(Player* object, Level& m_level)
{
	object->collide(this, m_level);
}