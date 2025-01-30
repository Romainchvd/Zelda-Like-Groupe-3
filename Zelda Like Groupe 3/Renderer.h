#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "game.h"

using namespace std;
using namespace sf;

class Renderer {
private:
	
public:
	Event event;
	RenderWindow window;
	Renderer();
	void run(Game& game);
	void Draw(Player& player);
};
