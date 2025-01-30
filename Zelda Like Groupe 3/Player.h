#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
using namespace std;
using namespace sf;

class Player :public Entity {
private:
	Texture TexturePlayer;
public:
	Vector2i position;
	int speed;
	
	Player(Vector2i p, int s);
	void update(float deltatime) override;
	void draw(sf::RenderWindow& window) override;
	void loadTexture();
};
#endif