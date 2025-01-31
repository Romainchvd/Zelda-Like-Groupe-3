#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;
using namespace sf;

class Renderer {
private:
	
public:
	Event event;
	RenderWindow window;
	Renderer();
	void run(Player& player);
	void Draw(Player& player);
};
