#include "Game.h"
Renderer::Renderer() : event(), window(sf::VideoMode(1920, 1080), "Zelda Like", Style::Fullscreen) {
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
	View camera(View(Vector2f(100, 100), Vector2f(1920.f, 1080.f)));
	camera.setSize(Vector2f(1920.f/2, 1080.f/2));
	while (window.isOpen()) {
		player.Mouvement();
		player.update(1);
		Draw(player, propManager);
		camera.setCenter(player.sprite.getPosition());
		window.setView(camera);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
					window.close();
			}
		}
	}
}