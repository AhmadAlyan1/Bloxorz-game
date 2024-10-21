#include "Information.h"

Information::Information(int level)
    :m_level(level)
{
    if (m_font.loadFromFile("Font.TTF") == NULL)
    {
        std::cout << "error opnening BERNHC.TTF";
        exit(EXIT_FAILURE);
    }
}

void Information::drawInformation(sf::RenderWindow& window,int level,int moves)
{
    if(m_level != level)
    {
        m_level = level;
        m_clock.restart();
    }
    m_time = m_clock.getElapsedTime();
    int x = m_time.asSeconds();
    m_text.setFont(m_font);
    m_text.setPosition(sf::Vector2f(0, 0));
    m_text.setColor(sf::Color::White);
    m_text.setCharacterSize(40);
    string s = "Passed Time: ";
    string w =  std::to_string(x);
    m_text.setString(s+w);
    window.draw(m_text);

    m_text.setFont(m_font);
    m_text.setPosition(sf::Vector2f(300, 0));
    m_text.setColor(sf::Color::White);
    m_text.setCharacterSize(40);
    s = "Moves: ";
    w = std::to_string(moves);
    m_text.setString(s + w);
    window.draw(m_text);
}

void Information::Level(sf::RenderWindow& window, int level)
{
    window.clear();
    m_text.setFont(m_font);
    m_text.setPosition(sf::Vector2f(500, 450));
    m_text.setColor(sf::Color::White);
    m_text.setCharacterSize(75);
    string  s = "Stage: ";
    string w = std::to_string(level);
    m_text.setString(s + w);
    window.draw(m_text);
}