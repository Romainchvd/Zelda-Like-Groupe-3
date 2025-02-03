#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game() {
	//enemy1.push_back(std::make_unique<Enemy1>(Vector2f(4400.0f, 2200.f)));
	//for (auto it = enemy1.begin(); it != enemy1.end();) {
		//std::cout << "ok";
	//}

	Game::Game() {}
	void Game::win() {
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Black);
		if (GAME_STATE == WIN) {
			void draw(sf::RenderWindow & window)
				setText("You Win !")
		}
	}
	void Game::lose() {
		if (GAME_STATE == Loose) {
			void draw(sf::RenderWindow & window)
				setText("Too Bad , You lost ;-;")
		}
	}
	void draw(sf::RenderWindow & window) {
		window.clear();
		window.draw(shape);
	}


}
};

