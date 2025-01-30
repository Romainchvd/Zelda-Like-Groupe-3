#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

class Game {
private:
	RenderWindow window;
public:
	Game();
	void run();
};

#endif