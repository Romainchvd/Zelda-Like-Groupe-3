#include "Game.h"
Renderer::Renderer() : event(), window(sf::VideoMode(1920, 1080), "Zelda Like") {
	window.setFramerateLimit(144);
}

void Renderer::Draw(Player& player, PropManager& propManager) {
	window.clear();
	for (int i = 0; i < propManager.getFirstLayer().size(); i++)
		window.draw(propManager.getFirstLayer()[i]->sprite);
	for (int i = 0; i < propManager.getSecondLayer().size(); i++)
		window.draw(propManager.getSecondLayer()[i]->sprite);
	player.draw(window);
	window.display();
}

void Renderer::run(Player& player, PropManager& propManager) {
	player.loadTexture();
	while (window.isOpen()) {
		player.Mouvement();
		Draw(player, propManager);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}
}