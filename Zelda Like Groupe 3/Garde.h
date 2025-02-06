#pragma once
#include <iostream>
#include "Player.h"
#include "Map.h"
#include <cmath>
#include <memory>
using namespace std;
using namespace sf;



class Garde :public Entity {
protected:
	bool isMoving;
	float animationSpeed = 0.1f;
	float elapsedTime;
	float elapsedTime2;
	int currentFrame = 0;
	int currentFrame2 = 0;
	Texture gardeRunTexture[4];
	Texture gardeIdleTexture[4];
	Vector2f position;
public:
	float cooldown = 10.0f;
	Sprite gardesprite;
	float health = 100.0f;
	float maxHealth;
	bool isFollowing = false;
	bool isDead = false;
	FloatRect hitbox;
	FloatRect followHitbox;
	Vector2f getPosition() const;
	void checkDeath();
	Garde(Vector2f startPosition);
	void updateMovement(Player& player, float deltatime);
	void draw(sf::RenderWindow& window) override;
	void loadTexture();
	FloatRect getHitbox() const;
	FloatRect getFollowHitbox() const;
	void update(float deltaTime) override;
	void Colision(unique_ptr<Prop>& prop);
};