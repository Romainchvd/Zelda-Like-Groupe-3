#pragma once
#include "Player.h"

using namespace std;
using namespace sf;

class Boss : public Entity {
private:
	bool isMoving;
	float animationSpeed;
	float elapsedTime;
	Texture BossTextureIdle[4];
	int currentFrame1;
	Texture BossTextureRun[4];
	int currentFrame2;
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