#include "renderer.h"

Renderer::Renderer() : window(sf::VideoMode(1920, 1080), "Zelda Like") {
	window.setFramerateLimit(144);
}

void Renderer::run() {
	while (window.isOpen()) {
		draw();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}
}

void Renderer::draw() {
	window.clear();
	window.display();
}