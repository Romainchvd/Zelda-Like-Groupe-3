#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy1.h"
#include "Map.h"
#include <thread>
#include <mutex>
#include <atomic>

class Game;

class Renderer {
private:
	
public:

	Event event;
	RenderWindow window;
	thread musicThread;
	mutex propMutex;
	atomic<bool> running = true;
	Renderer();
	void run(Player& player, PropManager& propManager, vector<unique_ptr<Enemy1>>& enemy1, Game& game);
	void Draw(Player& player, PropManager& manager, vector<unique_ptr<Enemy1>>& enemy1);
	void musicThreadF(Game& game, Player& player, PropManager& propManager, atomic<bool>& running);
};
