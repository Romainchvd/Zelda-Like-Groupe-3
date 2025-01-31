#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Entity.h"

using namespace std;
using namespace sf;

class Player :public Entity {
private:
	bool isMoving;
	bool isMovingLeft;
	bool isMovingRight;
	bool isMovingDown;
	bool isMovingUp;
	float animationSpeed = 0.1f;
	float elapsedTime;
	int currentFrame = 0;
	int currentFrame2 = 0;
	Texture TexturePlayer;
	Texture playerRunTexture[6];
	Texture playerIdleTexture[4];
	Sprite playersprite;
public:
	Sprite sprite;
	Vector2f position;
	int speed;
	
	Player(Vector2i p, int s);
	void update(float deltatime) override;
	void draw(sf::RenderWindow& window) override;
	void loadTexture();
	void Mouvement();
	void Colision();
	Vector2f getPosition() const;
};
#endif