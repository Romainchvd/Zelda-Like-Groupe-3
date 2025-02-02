#pragma once
#include <SFML/Audio.hpp>
#include "Renderer.h"
#include "Player.h"
#include "Enemy1.h"


class Game {
private:
public:
	//vector<unique_ptr<Enemy1>> enemy1;
	PropManager propManager;
	Game();
};
