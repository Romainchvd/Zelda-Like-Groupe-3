#include "Game.h"

Renderer::Renderer() : event(), window(sf::VideoMode(1920, 1080), "Zelda Like", Style::Fullscreen) {
	window.setFramerateLimit(144);
}

void Renderer::musicThreadF(Game& game, Player& player, PropManager& propManager, atomic<bool>& running) {
	while (running.load()) {
		{
			if(game.state == PLAYING)
			{
				std::lock_guard<mutex> lock(propMutex);

				for (auto& prop : propManager.getFirstLayer())
					game.musicManager.playMusic(player, prop);

				for (auto& prop : propManager.getSecondLayer())
					game.musicManager.playMusic(player, prop);
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


void Renderer::Draw(Player& player, PropManager& propManager, Enemy1Manager& enemy1, Enemy2Manager& enemy2,
	GardeManager& garde, View& view, vector<unique_ptr<Boss>>& Boss){
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
	for (auto i = 0; i < enemy2.size(); i++) {
		if (enemy2[i]->health > 0)
		{
			enemy2[i]->draw(window);
		}
	}
	for (auto i = 0; i < garde.size(); i++) {
		if (garde[i]->health > 0)
		{
			garde[i]->draw(window);
		}
	}
	for (auto i = 0; i < Boss.size(); i++) {
		Boss[i]->draw(window);
	}
	/*window.draw(player.PressE);*/
	player.drawInterface(view, window);
	window.display();
}

void Renderer::run(Player& player, PropManager& propManager, Enemy1Manager& enemy1, Enemy2Manager& enemy2,
	GardeManager& garde, Game& game, vector<unique_ptr<Boss>>& Boss) {
	
	musicThread = thread(&Renderer::musicThreadF, this, std::ref(game), std::ref(player), std::ref(propManager), std::ref(running));
	View camera(View(Vector2f(100, 100), Vector2f(1920.f, 1080.f)));
	camera.setSize(Vector2f(1920.f / 2, 1080.f / 2));
	while (window.isOpen()) {
		if ((game.state == PLAYING && game.doInitialiaze )|| (game.state == EDITOR && game.doInitialiaze))
		{
			game.propManager.readFile(game);
			player.loadTexture();
			//player.getPosition() = player.sprite.getPosition();
			for (auto& garde1 : garde) {
				garde1->loadTexture();
			}
			for (auto& enemy : enemy1) {
				enemy->loadTexture();
			}
			for (auto& enemy2 : enemy2) {
				enemy2->loadTexture();
			}
			for (auto& boss : Boss) {
				boss->loadTexture();
			}
			game.doInitialiaze = false;
		}
		if ((game.state == PLAYING && game.doInitialiaze == false) || (game.state == EDITOR && game.doInitialiaze == false))
		{
			player.swordAttackCheck();
			if (player.isAttacking) {
				player.swordAttack(enemy1[0]);
				player.swordAttack(enemy2[0]);
				player.swordAttack(garde[0]);
				player.swordAttack(Boss[0]);
			}
			for (auto& boss : Boss) {
				boss->Movement(player);
				boss->update(1);
			}
			player.Mouvement();
			player.update(1);
			for (auto& enemy : enemy1) {
				enemy->update(1);
				enemy->updateMovement(player, 0.05f);
			}
			for (auto& enemy2 : enemy2) {
				enemy2->update(1);
				enemy2->updateMovement(player, 0.05f);
			}
			for (auto& garde1 : garde) {
				garde1->update(1);
				garde1->updateMovement(player, 0.05f);
			}
			if (player.health <= 0)
			{
				game.state = LOSE;
			}
			Draw(player, propManager, enemy1, enemy2, garde, camera, Boss);
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
				for (auto& enemy2 : enemy2) {
					enemy2->Colision(propManager.getFirstLayer()[i]);
				}
				for (auto& garde1 : garde) {
					garde1->Colision(propManager.getFirstLayer()[i]);
				}
			}
			for (int i = 0; i < propManager.getSecondLayer().size(); i++) {
				player.Colision(propManager.getSecondLayer()[i]);
				player.Interact(propManager.getSecondLayer()[i], window);
				for (auto& enemy : enemy1) {
					enemy->Colision(propManager.getSecondLayer()[i]);
				}
				for (auto& enemy2 : enemy2) {
					enemy2->Colision(propManager.getSecondLayer()[i]);
				}
				for (auto& garde1 : garde) {
					garde1->Colision(propManager.getSecondLayer()[i]);
				}
			}
			//
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Enter)
					{
						running = false;
						if (musicThread.joinable()) {
							musicThread.join();
						}
						window.close();
					}
				}
			}
		}
		if (game.state == MENU)
		{
			while (window.pollEvent(event))
			{
				game.mousePosition = Mouse::getPosition(window);
				if (event.type == Event::Closed)
				{
					running = false;
					if (musicThread.joinable()) {
						musicThread.join();
					}
					window.close();
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
				{
					running = false;
					if (musicThread.joinable()) {
						musicThread.join();
					}
					window.close();
				}
				if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
				{
					if (game.playS.getGlobalBounds().contains(static_cast<Vector2f>(game.mousePosition)))
						game.state = PLAYING;
					if (game.exitS.getGlobalBounds().contains(static_cast<Vector2f>(game.mousePosition)))
					{
						running = false;
						if (musicThread.joinable()) {
							musicThread.join();
						}
						window.close();
					}
					if (game.editorS.getGlobalBounds().contains(static_cast<Vector2f>(game.mousePosition)))
						game.state = EDITOR;
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
				{
					running = false;
					if (musicThread.joinable()) {
						musicThread.join();
					}
					window.close();
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
				{
					running = false;
					if (musicThread.joinable()) {
						musicThread.join();
					}
					window.close();
				}
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
				{
					running = false;
					if (musicThread.joinable()) {
						musicThread.join();
					}
					window.close();
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
				{
					running = false;
					if (musicThread.joinable()) {
						musicThread.join();
					}
					window.close();
				}
			}
			window.clear();
			window.draw(game.wonS);
			window.display();
		}
	}
}