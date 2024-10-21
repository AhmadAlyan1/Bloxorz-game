#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "iostream"
#include "Menu.h"

#define MENU_BUTTON 3
#define FONT_SIZE 50

class Menu
{
public:
	Menu();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void help(sf::RenderWindow& window);
	void exitGame();
	void doEvent(sf::Event event, sf::RenderWindow& window, bool& out);

private:
	sf::Text m_menuText[MENU_BUTTON];
	sf::Font m_font;
	int m_selectedItem;
	sf::Sprite m_help;
	sf::Texture m_helpText;
	sf::Sprite m_back;
	sf::Texture m_backText;
};