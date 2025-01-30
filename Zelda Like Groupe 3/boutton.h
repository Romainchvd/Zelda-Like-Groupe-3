#pragma once
#ifndef Boutton_H
#define Boutton_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Boutton {
public:
	int x;
	int y;
	sf::RectangleShape shape(sf::Vector2f(x, y));
	void click();
	void draw();
};
#endif