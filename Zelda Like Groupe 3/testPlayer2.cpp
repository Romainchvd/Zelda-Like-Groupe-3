#include "testPlayer2.h"

playTest::playTest()  {
	sprite.setPosition(Vector2f(4800, 2200));
	cout << sprite.getPosition().x << ", " << sprite.getPosition().y << endl;
}

void playTest::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void playTest::loadTexture() {
	if (!playTexture.loadFromFile("Assets/Player/rect.png"))
	{
		cout << "pas charger" << endl;
	}
	sprite.setTexture(playTexture);
	sprite.setScale(Vector2f(0.25f, 0.25f));
}