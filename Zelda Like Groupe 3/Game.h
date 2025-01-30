#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

class Game {
private:
	RenderWindow window;
	Event event;
public:
	Game();
	void run();
};
