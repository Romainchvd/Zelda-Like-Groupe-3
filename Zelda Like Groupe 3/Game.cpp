#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game(float x, float y) {
	//enemy1.push_back(std::make_unique<Enemy1>(Vector2f(4400.0f, 2200.f)));
	//for (auto it = enemy1.begin(); it != enemy1.end();) {
		//std::cout << "ok";
//}
	shape.setSize(Vector2f(x, y));
	victoryFont.loadFromFile("assets/font/victoryFont.ttf");
	victoryText.setFont(victoryFont);
	shape.setFillColor(sf::Color::Black);
}
void Game::endGame(RenderWindow& window) {
		
		if (state == WIN) {
			victoryText.setString("Congratulations, You won!");	
			
		}
		if (state == LOSE) {
			victoryText.setString("You lost, try again!");
			
				
		}
		window.draw(shape);
		window.draw(victoryText);

}
//	enemy1.emplace_back(std::make_unique<Enemy1>(Vector2f(5000.0f, 2300.f)));
//	for (auto it = enemy1.begin(); it != enemy1.end();) {
//		std::cout << "ok" << endl;
//		it++;
//	}

