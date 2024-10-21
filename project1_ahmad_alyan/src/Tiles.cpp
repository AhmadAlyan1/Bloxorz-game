#include "Tiles.h"
#include "Player.h"


Tiles::Tiles()
{
	t.loadFromFile("Tile.jpg");
	m_sprite.setTexture(t);
	m_sprite.setScale(sf::Vector2f(((float)70 / m_sprite.getGlobalBounds().height),
		((float)70 / m_sprite.getGlobalBounds().height)));
	//std::cout << m_sprite.getScale().x << "," << m_sprite.getScale().y << "\n";
}


void Tiles::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	window.draw(m_sprite);
}

Tiles::~Tiles()
{
}

void Tiles::collide(Player* object, Level& m_level)
{	
	//std::cout << "Tile\n";
	object->collide(this, m_level);
}

