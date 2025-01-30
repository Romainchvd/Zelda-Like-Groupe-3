#include "Game.h"



Game::Game() : window(sf::VideoMode(1920, 1080), "Zelda Like") {
	window.setFramerateLimit(144);
 }

void Game::run() {
	while (window.isOpen()) {
		while (window.pollEvent(event))
		{
		if (event.type == Event::Closed)
		window.close();
		}
	}
}