#ifndef GAME_H
#define GAME_H
#include "Includes.h"
#include "Character.h"
#include "Monster.h"
#include "Tile.h"
//#include "Wall.h"

class Game
{
private:
	Character character;
	Monster monster;
	Tile * list[120];
	int amountOfWalls;
	Tile * walls[120];
	

public:
	Game();
	Game(sf::Texture * texture);
	~Game();

	void update(float sec);
	void draw(sf::RenderWindow& window);
	void checkCollision();
};

#endif // !