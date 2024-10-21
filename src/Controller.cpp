#include "Controller.h"

Controller::Controller()
    :m_level(m_player, m_levelNumber + 1)
    ,m_information(m_levelNumber), menu(true)
{  
    if (!m_music.openFromFile("BackgroundSound.wav"))
        std::cout << "error";
    run();
}

void Controller::run()
{
    try
    {
        static sf::Clock clock;
        sf::RenderWindow window(sf::VideoMode(1200, 900), "Bloxorz");

        setBackgrounds();

        while (window.isOpen())
        {
            sf::Event event{};
            if (menu)
            {
                m_menu.doEvent(event, window, menu);
            }
            else
            {
                if (m_levelNumber == 0)
                {
                    ++m_levelNumber;
                    m_information.Level(window, m_levelNumber);
                    window.display();
                    Sleep(1000);
                }
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();

                    if (event.type == sf::Event::MouseButtonReleased)
                    {
                        std::cout << event.mouseButton.x << "," << event.mouseButton.y << std::endl;
                    }
                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::Escape)
                        {
                            m_puase = !m_puase;
                        }
                    }
                }
                if (!m_puase)
                {
                    window.clear();
                    window.draw(m_backgroundS);
                    checkCollision(window, &m_player);

                    if (m_player.isLose())
                    {
                        drawPlayer(window);
                        lose(window);
                        continue;
                    }

                    if (m_player.isWin())
                    {
                        drawPlayer(window);
                        window.display();
                        Sleep(500);
                        win(window);
                        window.clear();
                        if (m_end)
                            break;
                    }
                    m_information.drawInformation(window, m_levelNumber, m_player.getMoves());
                    drawPlayer(window);
                    window.display();
                }
            }
        }
    }
    catch (...)
    {
        std::cout << "Something went wrong! try again\n";
        exit(EXIT_FAILURE);
    }
}

void Controller::drawPlayer(sf::RenderWindow& window)
{
    m_level.drawStatic(window);
    m_player.draw(window);   
}

void Controller::checkCollision(sf::RenderWindow& window, Player* player)
{
    Characters* character = m_level.getIcon(player->getNextDirection(window)); 
    if (character != nullptr)
    {
        m_player.move(m_level.getBoardSize());
        character->collide(player, m_level);   
    }
}

void Controller::setBackgrounds()
{
    m_backgroundT.loadFromFile("Background.jpg");
    m_backgroundS.setTexture(m_backgroundT);

    m_music.play();
    m_music.setLoop(true);
    m_music.setVolume(50);
}

void Controller::win(sf::RenderWindow& window)
{
    ++m_levelNumber;
    if (m_levelNumber <= m_level.levelsNum())
    {   
        window.clear();
        m_information.Level(window, m_levelNumber);  
        window.display();
        m_player.newLevel();
        m_level.read_level(m_player, m_levelNumber);    
    }
    else
    {
        window.clear();
        m_backgroundT.loadFromFile("End.png");
        m_backgroundS.setTexture(m_backgroundT);
        window.draw(m_backgroundS);
        window.display();
        Sleep(2000);
        m_end = true;
    }
}

void Controller::lose(sf::RenderWindow& window)
{
    window.display();
    m_backgroundT.loadFromFile("GameOver.png");
    m_backgroundS.setTexture(m_backgroundT);
    window.draw(m_backgroundS);
    window.display();
    Sleep(1000);
    window.clear();
    setBackgrounds();
    m_player.newLevel();
    m_level.read_level(m_player, m_levelNumber);
}