#pragma once
#include <SFML/Audio.hpp>
#include "Renderer.h"
#include "Player.h"
#include "Enemy1.h"

enum GAME_STATE { MENU, PLAYING, WIN, LOSE };
class Game {
private:
public:
	int x;
	int y;
	Game(int x, int y);
	
	sf::RectangleShape shape(x ,y );
	GAME_STATE state = PLAYING;
	void win();
	void lose();
	void draw(sf::RenderWindow& window);
	PropManager propManager;
	vector<unique_ptr<Enemy1>> enemy1;
	};
	
