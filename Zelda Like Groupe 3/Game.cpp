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
	enemy1.emplace_back(std::make_unique<Enemy1>(Vector2f(4800.0f, 3650.f)));
	garde.emplace_back(std::make_unique<Garde>(Vector2f(22 * 96, 4 * 96)));
	for (auto it = enemy1.begin(); it != enemy1.end();) {
		std::cout << "ok" << endl;
		it++;
	}
	for (auto it = garde.begin(); it != garde.end();) {
		std::cout << "ok2" << endl;
		it++;
	}
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
	

