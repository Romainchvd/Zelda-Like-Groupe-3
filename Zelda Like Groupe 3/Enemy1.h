#pragma once
#include <iostream>
#include "Player.h"
#include <cmath>
#include <memory>
using namespace std;
using namespace sf;

class Enemy1 :public Entity {
private:
	bool isMoving;
	float animationSpeed = 0.1f;
	float elapsedTime;
	int currentFrame = 0;
	int currentFrame2 = 0;
	Sprite enemy1sprite;
	Texture enemy1RunTexture[4];
	Texture enemy1IdleTexture[4];
	Vector2f position;
public:
	float health = 100.0f;
	float maxHealth;
	bool isFollowing = false;
	bool isDead = false;
	FloatRect hitbox;
	FloatRect followHitbox;
	Vector2f getPosition() const;
	void checkDeath();
	Enemy1(Vector2f startPosition);
	void updateMovement(const Player& player);
	void draw(sf::RenderWindow& window) override;
	void loadTexture();
	FloatRect getHitbox() const;
	FloatRect getFollowHitbox() const;
	void update(float deltaTime) override;
};