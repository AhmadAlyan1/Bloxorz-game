#pragma once
#include "Characters.h"
#include "Level.h"
#include <windows.h>

enum Direction_t { RIGHT, DOWN, LEFT, UP, SAME};
enum Shape_t {CUBE, V_REC, H_REC}; 

class Player : public Characters {
public:
	Player();
	void draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f new_pos);
	virtual void collide(Player* object, Level& m_level) {};
	virtual void collide(Tiles* object, Level& m_level) ;
	virtual void collide(Hole* object, Level& m_level);
	virtual void collide(Win* object, Level& m_level);
	virtual void collide(SpecialTiles* object, Level& m_level);

	void setStartingPosition(sf::Vector2f pos);
	void move(sf::Vector2f boardSize);
	sf::Vector2f getNextDirection(sf::RenderWindow& window);
	sf::Vector2f getCenter(sf::Vector2f pos);
	bool isLose();
	bool isWin();
	void newLevel();
	int getMoves();
private:
	sf::Texture m_cube;	
	Direction_t m_direction;
	sf::Event m_event;
	Shape_t m_shape;
	bool lose, win;
	int m_moves = 0;
	bool m_change = false;
	sf::Sound m_Psound;
	sf::SoundBuffer m_Pbuff;
	sf::Sound m_Hsound;
	sf::SoundBuffer m_Hbuff;
protected:
	sf::Vector2f m_startingPosition;
	sf::Vector2f m_pos;
};