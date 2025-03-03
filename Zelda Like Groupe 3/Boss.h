#pragma once
#include "Player.h"

using namespace std;
using namespace sf;

class Boss : public Entity {
private:
	bool isMoving;
	bool Phase2;
	float animationSpeed;
	float elapsedTime;
	Texture BossTextureIdle1[4];
	int currentFrame1;
	Texture BossTextureRun1[4];
	int currentFrame2;
	Texture BossTextureIdle2[3];
	int currentFrame3;
	Texture BossTextureRun2[4];
	int currentFrame4;
	float BossSpeed;
public:
	int BossHP;
	int MaxBossHP;
	Sprite BossSprite;
	Boss();
	void draw(sf::RenderWindow& window) override;
	void update(float deltaTime) override;
	void Movement(Player& player);
	void loadTexture();
	int getHP() const;
	void setHP(int _HP);
};