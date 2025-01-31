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
	int currentFrame3 = 0;
	int currentFrame4 = 0;
	Texture TexturePlayer;
	Texture playerRunTexture[6];
	Texture playerRunUpTexture[4];
	Texture playerRunDownTexture[4];
	Texture playerIdleTexture[4];
	Sprite playersprite;
	Vector2f position;
public:
	Sprite sprite;
	
	int speed;
	FloatRect Phitbox;
	Player(int s);
	void update(float deltatime) override;
	void draw(sf::RenderWindow& window) override;
	void loadTexture();
	void Mouvement();
	void Colision();
	Vector2f getPosition() const;
	FloatRect getHitbox() const;
};
#endif