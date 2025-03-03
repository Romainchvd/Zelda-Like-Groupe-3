#pragma once
#include <iostream>
#include "Player.h"
#include "Map.h"
#include <cmath>
#include <memory>
using namespace std;
using namespace sf;



class Enemy2 :public Entity {
protected:
	bool isMoving;
	float animationSpeed = 0.1f;
	float elapsedTime;
	float elapsedTime2;
	int currentFrame = 0;
	int currentFrame2 = 0;
	Texture enemy2RunTexture[4];
	Texture enemy2IdleTexture[4];
	Vector2f position;
public:
	float cooldown = 10.0f;
	Sprite enemy2sprite;
	float health = 100.0f;
	float maxHealth;
	bool isFollowing = false;
	bool isDead = false;
	FloatRect hitbox;
	FloatRect followHitbox;
	Vector2f getPosition() const;
	void checkDeath();
	Enemy2(Vector2f startPosition);
	void updateMovement(Player& player, float deltatime);
	void draw(sf::RenderWindow& window) override;
	void loadTexture();
	FloatRect getHitbox() const;
	FloatRect getFollowHitbox() const;
	void update(float deltaTime) override;
	void Colision(unique_ptr<Prop>& prop);
};

class Enemy2Manager
{
protected:
	vector<unique_ptr<Enemy2>> enemy2;
public:
	void creerEnemy2(int x, int y);
	void detruireEnemy2(unique_ptr<Enemy2>& enemy);
	//void readFile();
};