#pragma once
#ifndef ENEMY1_H
#define ENEMY1_H
#include <iostream>
#include "Player.h"

using namespace std;
using namespace sf;

class Enemy1 :public Entity {
private:
	Sprite enemy1sprite;
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
};

#endif