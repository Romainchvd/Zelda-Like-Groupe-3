#pragma once
#include <SFML/Audio.hpp>
#include "Renderer.h"
#include "Player.h"
#include "MusicPlayer.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Garde.h"
#include "Boss.h"


enum GAME_STATE { MENU, PLAYING, WIN, LOSE, EDITOR };
class Game {
private:
public:
	Game(float x, float y);
	Font victoryFont;
	Text victoryText;
	sf::RectangleShape shape;
	GAME_STATE state = MENU;
	void endGame(RenderWindow& window);
	PropManager propManager;
	MusicPlayer musicManager;
	//vector<unique_ptr<Enemy1>> enemy1;
	//vector<unique_ptr<Enemy2>> enemy2;
	Sprite TitleScreenS;
	Sprite wonS;
	Sprite lostS;
	Sprite playS;
	Sprite editorS;
	Sprite exitS;
	Texture TitleScreenT;
	Texture WonT;
	Texture LostT;
	Texture playT;
	Texture editorT;
	Texture exitT;
	Vector2i mousePosition;
	bool doInitialiaze = true;

	vector<unique_ptr<Garde>> garde;
	vector<unique_ptr<Boss>> boss;
	};
	
