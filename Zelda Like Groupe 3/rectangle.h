#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Rectangle {
public:
	Vector2f position;
	Texture rectTexture;
	Sprite rectangle;
	Rectangle(Vector2f p);
	void draw(sf::RenderWindow& window);
	void loadTexture();
};