#include "Game.h"

Game::Game() : window(sf::VideoMode(1920, 1080), "Zelda Like") {
	window.setFramerateLimit(60);
 }