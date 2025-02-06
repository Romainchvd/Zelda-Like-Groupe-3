#include "Boss.h"

using namespace std;
using namespace sf;

Boss::Boss() : currentFrame(1), elapsedTime(0.0f), animationSpeed(15.0f), isMoving(false), BossSpeed(0.5f) {
	BossSprite.setPosition(Vector2f(48.5 * 96, 37.5 * 96));
}

void Boss::draw(sf::RenderWindow& window) {
	window.draw(BossSprite);
}

void Boss::update(float deltaTime) {
	elapsedTime += deltaTime;
	if (elapsedTime >= animationSpeed)
	{
		elapsedTime = 0.0f;
		currentFrame++;
		currentFrame %= 4;
		BossSprite.setTexture(BossTextureIdle[currentFrame]);
	}
	BossSprite.setPosition(BossSprite.getPosition());
}

void Boss::loadTexture() {
	for (int i = 0; i < 4; ++i) {
		if (!BossTextureIdle[i].loadFromFile("Assets/Boss/Idle/BossIdle" + to_string(i) + ".png"))
		{
			cerr << "erreur de chargement des asset du boss" << endl;
		}
	}
	
	BossSprite.setTexture(BossTextureIdle[1]);
	BossSprite.setScale(Vector2f(2.0f, 2.0f));
}

void Boss::Movement(Player& player) {
	direction = player.sprite.getPosition() - BossSprite.getPosition();
	float distance = hypot(direction.x, direction.y);

	if (distance < 500)
	{
		if (BossSprite.getPosition().x <= player.getPosition().x)
		{
			BossSprite.move(Vector2f(BossSpeed, 0.0f));
		}
		if (BossSprite.getPosition().x >= player.getPosition().x)
		{
			BossSprite.move(Vector2f(-BossSpeed, 0.0f));
		}
		if (BossSprite.getPosition().y <= player.getPosition().y)
		{
			BossSprite.move(Vector2f(0.0f, BossSpeed));
		}
		if (BossSprite.getPosition().y >= player.getPosition().y)
		{
			BossSprite.move(Vector2f(0.0f, -BossSpeed));
		}
	}
}

