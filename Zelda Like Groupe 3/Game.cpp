#include "Game.h"

Game::Game() {
	enemy1.emplace_back(std::make_unique<Enemy1>(Vector2f(4400.0f, 2200.f)));
	for (auto it = enemy1.begin(); it != enemy1.end();) {
		std::cout << "ok" << endl;
		it++;
	}
};

