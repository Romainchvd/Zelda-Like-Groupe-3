#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Entity {
public:
	Sprite sprite;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};

#endif 
