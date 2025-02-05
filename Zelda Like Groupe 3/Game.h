#pragma once
#include <SFML/Audio.hpp>
#include "Renderer.h"
#include "Player.h"
#include "MusicPlayer.h"
#include "Enemy1.h"

enum GAME_STATE { MENU, PLAYING, WIN, LOSE };
class Game {
private:
public:
	Game(float x, float y);
	Font victoryFont;
	Text victoryText;
	sf::RectangleShape shape;
	GAME_STATE state = PLAYING;
	void endGame(RenderWindow& window);
	PropManager propManager;
	MusicPlayer musicManager;
	vector<unique_ptr<Enemy1>> enemy1;
	};
	
