#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy1.h"
#include "Map.h"
#include "testPlayer2.h"

using namespace std;
using namespace sf;

class Renderer {
private:
	
public:
	Event event;
	RenderWindow window;
	Renderer();
	void run(Player& player, PropManager& propManager);
	void Draw(Player& player, PropManager& manager);
};
