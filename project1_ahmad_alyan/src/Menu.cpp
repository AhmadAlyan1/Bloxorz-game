#include "Menu.h"

Menu::Menu()
{
    int hight = 900;
    int width = 1200;

    if (!m_helpText.loadFromFile("Help.png") ||
        !m_font.loadFromFile("Font.TTF") ||
        !m_backText.loadFromFile("Background.jpg")
        )
    {
        std::cout << "error opnening BERNHC.TTF";
        exit(EXIT_FAILURE);
    }

    m_back.setTexture(m_backText);
    m_help.setTexture(m_helpText);

    m_menuText[0].setFont(m_font);
    m_menuText[0].setColor(sf::Color::Red);
    m_menuText[0].setString("PLAY");
    m_menuText[0].setOrigin(25, 0);
    m_menuText[0].setPosition((width / 2) - 20, 200);
    m_menuText[0].setCharacterSize(FONT_SIZE);

    m_menuText[1].setFont(m_font);
    m_menuText[1].setColor(sf::Color::White);
    m_menuText[1].setString("HELP");
    m_menuText[1].setOrigin(25, 0);
    m_menuText[1].setPosition((width / 2) - 20, 450);
    m_menuText[1].setCharacterSize(FONT_SIZE);

    m_menuText[2].setFont(m_font);
    m_menuText[2].setColor(sf::Color::White);
    m_menuText[2].setString("EXIT");
    m_menuText[2].setOrigin(25, 0);
    m_menuText[2].setPosition((width / 2) - 20, 700);
    m_menuText[2].setCharacterSize(FONT_SIZE);

    m_selectedItem = 0;
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(m_back);
    for (int i = 0; i < MENU_BUTTON; i++)
        window.draw(m_menuText[i]);
}

void Menu::moveUp()
{
    if (m_selectedItem - 1 >= 0)
    {
        m_menuText[m_selectedItem].setColor(sf::Color::White);
        m_selectedItem--;
        m_menuText[m_selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (m_selectedItem + 1 < MENU_BUTTON)
    {
        m_menuText[m_selectedItem].setColor(sf::Color::White);


        m_selectedItem++;
        m_menuText[m_selectedItem].setColor(sf::Color::Red);

    }
}

void Menu::help(sf::RenderWindow& window)
{
    bool out = true;
    while (out)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            out = false;

        window.clear();
        window.draw(m_help);
        window.display();
    }
}

void Menu::exitGame()
{
    exit(EXIT_SUCCESS);
}

void  Menu::doEvent(sf::Event event, sf::RenderWindow& window, bool& out)
{
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                moveUp();
                break;
            case  sf::Keyboard::Down:
                moveDown();
                break;
            case sf::Keyboard::Return:
                switch (m_selectedItem)
                {
                case 0:
                    out = false;
                    break;
                case 1:
                    help(window);
                    break;
                case 2:
                    exitGame();
                    break;
                }
            }
            break;

        case sf::Event::Closed:
            window.close();
            break;
        }

        window.clear();
        draw(window);
        window.display();
    }
}