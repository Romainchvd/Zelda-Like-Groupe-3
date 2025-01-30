#include "renderer.h"

Renderer::Renderer() : event(), window(sf::VideoMode(1920, 1080), "Zelda Like") {
	window.setFramerateLimit(144);
}

void Renderer::Draw(Player& player) {
	player.draw(window);
	window.clear();
	window.display();
}

void Renderer::run(Game& game) {
	while (window.isOpen()) {
		Draw(game.player);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}
}