#pragma once
#include "Player.h"

using namespace std;
using namespace sf;

class Boss : public Entity {
private:
	bool isMoving;
	float animationSpeed = 0.1f;
	float elapsedTime;
	Texture BossTextureIdle[4];
	int currentFrame = 0;
public:
	Sprite BossSprite;
	Boss();
	void draw(sf::RenderWindow& window) override;
	void update(float deltaTime) override;
	void loadTexture();
};