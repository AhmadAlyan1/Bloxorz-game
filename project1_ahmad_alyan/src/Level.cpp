#include "Level.h"

Level::Level()
{}

Level::Level(Player& m_player, int levelNumber)
{
	read_level(m_player, levelNumber);
}

void Level::read_level(Player& m_player, int levelNumber)
{
	ifstream input;
	open_file(input, levelNumber);

	int rows, cols;
	char c;	
	input >> rows >> cols;
	if (levelNumber == 1)
		input >> m_levels;

	setBoardSize(rows + 4, cols + 4);

	for (size_t i = 0; i < rows + 4; i++)
	{
		for (size_t j = 0; j < cols + 4; j++)
		{
			if (i == 0 || i == 1 || i == rows + 2 || i == rows + 3 ||
				j == 0 || j == 1 || j == cols + 2 || j == cols + 3)
				c = ' ';
			else
			{
				c = input.get();
				if (c == '\n')
					c = input.get();
			}
				add_to_board(c, i, j, m_player);
		}
	}
	input.close();
}

void Level::setBoardSize(int rows, int cols)
{
	m_board.resize(rows);
	for (size_t i = 0; i < rows; i++)
		m_board[i].resize(cols);
}

int Level::levelsNum()
{
	return m_levels;
}

void Level::open_file(ifstream& input, int levelNumber)
{
	string file = "level" + std::to_string(levelNumber) + ".txt";
	input.open(file);
	if (!input.is_open())
	{
		std::cerr << "could not open file\n";
		exit(EXIT_FAILURE);
	}
}

void Level::add_to_board(const char c,
	const size_t i,
	const size_t j,
	Player& m_player)
{	
	switch (c)
	{
	case '=':
		m_board[i][j] = std::make_unique < Tiles >();
		break;
	case '*':
		m_board[i][j] = std::make_unique < Tiles >();
		setPlayer(m_player, sf::Vector2f(j * 70 - 70, i * 70));
		break;
	case '+':
		m_board[i][j] = std::make_unique < SpecialTiles >();
		break;
	case 'x':
		m_board[i][j] = std::make_unique < Win >();
		break;
	
	case ' ':
		m_board[i][j] = std::make_unique < Hole >();
		break;
	
	default:
		break;
	}
}

void Level::setPlayer(Player& player, sf::Vector2f pos)
{
	player.SetPosition(pos);
	player.setStartingPosition(pos);
}

sf::Vector2f Level::getBoardSize()
{
	sf::Vector2f boardSize;
	boardSize.x = m_board.size() ;
	boardSize.y = m_board[0].size() ;
	return boardSize;
}


void Level::drawStatic(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_board.size(); i++)
	{
		for (size_t j = 0; j < m_board[i].size(); j++)
		{
			if (m_board[i][j] != nullptr )
				m_board[i][j]->draw(window, sf::Vector2f(j *70 - 70 , i* 70));
		}
	}
}

StaticChar* Level::getIcon(sf::Vector2f pos)
{
	int i = ((pos.y)/ 70) ;
	int j = ((pos.x + 70)/ 70) ;
	return m_board[i][j].get();
}

void Level::setIcon(sf::Vector2f pos)
{
	int i = ((pos.y) / 70);
	int j = ((pos.x + 70) / 70);
	m_board[i][j] = std::make_unique < Hole >();
}