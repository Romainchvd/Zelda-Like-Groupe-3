#pragma once
#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class playTest {
public:
	Texture playTexture;
	Sprite sprite;
	playTest();
	void draw(sf::RenderWindow& window);
	void loadTexture();


};
#endif