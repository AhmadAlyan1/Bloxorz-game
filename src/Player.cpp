#include "Player.h"

Player::Player() 
	:lose(false), win(false)
{
	m_cube.loadFromFile("Box.png");
	m_sprite.setTexture(m_cube);
	SetPosition(m_sprite.getOrigin());
	m_sprite.setScale(sf::Vector2f(0.07, 0.07));
	m_shape = CUBE;
	m_pos = m_sprite.getPosition();

	if (!m_Pbuff.loadFromFile("move.wav"))
		std::cout << "error";
	m_Psound.setBuffer(m_Pbuff);

	if (!m_Hbuff.loadFromFile("Lose.wav"))
		std::cout << "error";
	m_Hsound.setBuffer(m_Hbuff);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

int Player::getMoves()
{
	return m_moves;
}

void Player::move( sf::Vector2f boardSize)
{
	if (m_direction != SAME)
	{
		++m_moves;
		m_Psound.play();
	}
	if (m_direction == UP)
	{
		switch (m_shape)
		{
		case 0:
			m_sprite.setScale(sf::Vector2f(0.07, 0.14));
			m_sprite.move(0, -140);
			m_shape = V_REC;
			break;
		case 1:
			m_sprite.setTexture(m_cube);
			m_sprite.setScale(sf::Vector2f(0.07, 0.07));
			m_sprite.move(0, -70);
			m_shape = CUBE;
			break;
		case 2:
			m_sprite.setScale(sf::Vector2f(0.14, 0.07));
			m_sprite.move(0, -70);
			m_shape = H_REC;
			break;
		default:
			break;
		}
	} 

	else if (m_direction == DOWN)
	{
		switch (m_shape)
		{
		case 0:
			m_sprite.setScale(sf::Vector2f(0.07, 0.14));
			m_sprite.move(0, 70);
			m_shape = V_REC;
			break;
		case 1:
			m_sprite.setScale(sf::Vector2f(0.07, 0.07));
			m_sprite.move(0, 140);
			m_shape = CUBE;
			break;
		case 2:
			m_sprite.setScale(sf::Vector2f(0.14, 0.07));
			m_sprite.move(0, 70);
			m_shape = H_REC;
			break;
		default:
			break;
		}
	}

	else if (m_direction == RIGHT)
	{
		switch (m_shape)
		{
		case 0:
			m_sprite.setScale(sf::Vector2f(0.14, 0.07));
			m_sprite.move(70, 0);
			m_shape = H_REC;
			break;
		case 1:
			m_sprite.setScale(sf::Vector2f(0.07, 0.14));
			m_sprite.move(70, 0);
			m_shape = V_REC;
			break;
		case 2:
			m_sprite.setScale(sf::Vector2f(0.07, 0.07));
			m_sprite.move(140, 0);
			m_shape = CUBE;
			break;
		default:
			break;
		}
	}

	else if (m_direction == LEFT)
	{
		switch (m_shape)
		{
		case 0:
			m_sprite.setScale(sf::Vector2f(0.14, 0.07));
			m_sprite.move(-140, 0);
			m_shape = H_REC;
			break;
		case 1:
			m_sprite.setScale(sf::Vector2f(0.07, 0.14));
			m_sprite.move(-70, 0);
			m_shape = V_REC;
			break;
		case 2:
			m_sprite.setScale(sf::Vector2f(0.07, 0.07));
			m_sprite.move(-70, 0);
			m_shape = CUBE;
			break;
		default:
			break;
		}
	}
	m_direction = SAME;
	m_pos = m_sprite.getPosition();
	
}

void Player::SetPosition(sf::Vector2f new_pos)
{
	m_sprite.setPosition(new_pos);
}

sf::Vector2f Player::getCenter(sf::Vector2f pos)
{
	sf::Vector2f newPos;
	newPos.x = (pos.x +35);
	newPos.y = (pos.y +35);
	return newPos;
}

void Player::collide(Tiles* object, Level& m_level)
{

}


void Player::collide(SpecialTiles* object, Level& m_level)
{
	if (m_shape == CUBE)
	{
		m_level.setIcon(m_sprite.getPosition());
	}

}

void Player::collide(Hole* object, Level& m_level)
{
	m_Hsound.play();
	lose = true;
}

void Player::collide(Win* object, Level& m_level)
{
	if (m_shape == CUBE)
	{
		win = true;
		m_shape = CUBE;
	}
}

bool Player::isLose()
{
	return lose;
}


bool Player::isWin()
{
	return win;
}

void Player::newLevel()
{
	win = false;
	lose = false;
	m_shape = CUBE;
	m_sprite.setScale(sf::Vector2f(0.07, 0.07));
}

void Player::setStartingPosition(sf::Vector2f pos)
{
	m_startingPosition = pos;
}

sf::Vector2f Player::getNextDirection(sf::RenderWindow& window)
{
	sf::Vector2f nextPos = m_sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = RIGHT;
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			continue;

		switch (m_shape)
		{
		case 0:
			return sf::Vector2f(nextPos.x + 140, nextPos.y + 35);
			break;
		case 1:
			return sf::Vector2f(nextPos.x + 105, nextPos.y + 70);
			break;
		case 2:
			return sf::Vector2f(nextPos.x + 175, nextPos.y + 35);
			break;
		default:
			break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = LEFT;
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			continue;
		switch (m_shape)
		{
		case 0:
			return sf::Vector2f(nextPos.x - 70, nextPos.y + 35);
			break;
		case 1:
			return sf::Vector2f(nextPos.x - 35, nextPos.y + 70);
			break;
		case 2:
			return sf::Vector2f(nextPos.x - 35, nextPos.y + 35);
			break;
		default:
			break;
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_direction = UP;
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			continue;
		switch (m_shape)
		{
		case 0:
			return sf::Vector2f(nextPos.x + 35, nextPos.y - 70);
			break;
		case 1:
			return sf::Vector2f(nextPos.x + 35, nextPos.y - 35);
			break;
		case 2:
			return sf::Vector2f(nextPos.x + 70, nextPos.y - 35);
			break;
		default:
			break;
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_direction = DOWN;	
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			continue;
		switch (m_shape)
		{
		case 0:
			return sf::Vector2f(nextPos.x + 35, nextPos.y + 140);
			break;
		case 1:
			return sf::Vector2f(nextPos.x + 35 , nextPos.y + 175);
			break;
		case 2:
			return sf::Vector2f(nextPos.x + 70, nextPos.y + 105);
			break;
		default:
			break;
		}
	}
	else
	{
		m_direction = SAME;
		return sf::Vector2f(nextPos.x, nextPos.y);
	}
}
