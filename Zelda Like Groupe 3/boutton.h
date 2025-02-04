#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Boutton {
public:
	Vector2f size;
	Sprite sprite;
	Texture texture;
	void click()override;
	void draw(sf::RenderWindow& window)override;
	
};