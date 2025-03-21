#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Boss.h"
#include "Garde.h"
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
	atomic<bool> running = true; //Note: sert � �viter d'utiliser un autre mutex (je pouvais pas pour les vecteurs sans refaire tout le code li�) ne pas toucher merci
	Renderer();

	void run(Player& player, PropManager& propManager, vector<unique_ptr<Enemy1>>& enemy1, vector<unique_ptr<Enemy2>>& enemy2,
		vector<unique_ptr<Garde>>& garde, Game& game, vector<unique_ptr<Boss>>& Boss);

	void Draw(Player& player, PropManager& manager , vector<unique_ptr<Enemy1>>& enemy1, vector<unique_ptr<Enemy2>>& enemy2,
		vector<unique_ptr<Garde>>& garde, View& view, vector<unique_ptr<Boss>>& Boss);
	
	void musicThreadF(Game& game, Player& player, PropManager& propManager, atomic<bool>& running);
};
