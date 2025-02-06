#include "Game.h"

Renderer::Renderer() : event(), window(sf::VideoMode(1920, 1080), "Zelda Like") {
	window.setFramerateLimit(144);
}

void Renderer::musicThreadF(Game& game, Player& player, PropManager& propManager, atomic<bool>& running) {
	while (running.load()) {
		{
			std::lock_guard<mutex> lock(propMutex); 

			for (auto& prop : propManager.getFirstLayer())
				game.musicManager.playMusic(player, prop);

			for (auto& prop : propManager.getSecondLayer())
				game.musicManager.playMusic(player, prop);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Renderer::Draw(Player& player, PropManager& propManager, vector<unique_ptr<Enemy1>>& enemy1, View& view){
	window.clear();
	for (int i = 0; i < propManager.getFirstLayer().size(); i++)
		window.draw(propManager.getFirstLayer()[i]->sprite);
	for (int i = 0; i < propManager.getSecondLayer().size(); i++)
		window.draw(propManager.getSecondLayer()[i]->sprite);
	player.draw(window);
	for (auto i = 0; i < enemy1.size(); i++) {
		if (enemy1[i]->health > 0)
		{
			enemy1[i]->draw(window);
		}
	}
	/*window.draw(player.PressE);*/
	player.drawInterface(view, window);
	window.display();
}

void Renderer::run(Player& player, PropManager& propManager, vector<unique_ptr<Enemy1>>& enemy1, Game& game) {
	player.loadTexture();
	musicThread = thread(&Renderer::musicThreadF, this, std::ref(game), std::ref(player), std::ref(propManager), std::ref(running));
	//player.getPosition() = player.sprite.getPosition();
	for (auto& enemy : enemy1) {
		enemy->loadTexture();
	}
	View camera(View(Vector2f(100, 100), Vector2f(1920.f, 1080.f)));
	camera.setSize(Vector2f(1920.f / 2, 1080.f / 2));
	while (window.isOpen()) {
		if (game.state == MENU)
		{
			while (window.pollEvent(event))
			{
				game.mousePosition = Mouse::getPosition(window);
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
					window.close();
				if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
				{
					if (game.playS.getGlobalBounds().contains(static_cast<Vector2f>(game.mousePosition)))
						game.state = PLAYING;
					if (game.exitS.getGlobalBounds().contains(static_cast<Vector2f>(game.mousePosition)))
					{
						window.close();
					}
					if (game.editorS.getGlobalBounds().contains(static_cast<Vector2f>(game.mousePosition)))
						game.state = PLAYING;
				}
			}
			window.clear();
			window.draw(game.TitleScreenS);
			window.draw(game.playS);
			window.draw(game.exitS);
			window.draw(game.editorS);
			window.display();
		}
		if (game.state == LOSE)
		{
			camera = View(sf::FloatRect(0, 0, 1920.f, 1080.f));
			window.setView(camera);
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
					window.close();
			}
			window.clear();
			window.draw(game.lostS);
			window.display();
		}
		if (game.state == WIN)
		{
			camera = View(sf::FloatRect(0, 0, 1920.f, 1080.f));
			window.setView(camera);
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
					window.close();
			}
			window.clear();
			window.draw(game.wonS);
			window.display();
		}
		if (game.state == PLAYING)
		{
			player.swordAttackCheck();
			if (player.isAttacking)
				player.swordAttack(enemy1[0]);
			player.Mouvement();
			player.update(1);
			if (player.health <= 0)
				game.state = LOSE;
			for (auto& enemy : enemy1) {
				enemy->update(1);
				enemy->updateMovement(player, 0.05f);
			}
			Draw(player, propManager, enemy1, camera);
			camera.setCenter(player.sprite.getPosition());
			window.setView(camera);
			for (int i = 0; i < propManager.getSecondLayer().size(); i++)
			{
				propManager.getSecondLayer()[i]->collectProp(player, propManager);
				propManager.getSecondLayer()[i]->useKey(player, propManager);
			}
			//colision player
			for (int i = 0; i < propManager.getFirstLayer().size(); i++) {
				player.Colision(propManager.getFirstLayer()[i]);
				player.Interact(propManager.getFirstLayer()[i], window);
				for (auto& enemy : enemy1) {
					enemy->Colision(propManager.getFirstLayer()[i]);
				}
			}
			for (int i = 0; i < propManager.getSecondLayer().size(); i++) {
				player.Colision(propManager.getSecondLayer()[i]);
				player.Interact(propManager.getSecondLayer()[i], window);
				for (auto& enemy : enemy1) {
					enemy->Colision(propManager.getSecondLayer()[i]);
				}
			}
			//
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					running = false;
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Enter)
					{
						window.close();
						running = false;
					}
				}
			}
		}

	}
	running = false;
	if (musicThread.joinable()) {
		musicThread.join();
	}
}