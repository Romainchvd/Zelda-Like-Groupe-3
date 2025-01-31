#include "renderer.h"

Renderer::Renderer() : event(), window(sf::VideoMode(1920, 1080), "Zelda Like") {
	window.setFramerateLimit(144);
}

void Renderer::Draw(Player& player) {
	window.clear();
	player.draw(window);
	cout << "player est draw" << endl;
	window.display();
}

void Renderer::run(Player& player) {
	player.loadTexture();
	while (window.isOpen()) {
		player.Mouvement();
		Draw(player);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}
}