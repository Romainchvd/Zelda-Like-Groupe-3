#include "Boss.h"

using namespace std;
using namespace sf;

Boss::Boss() : currentFrame1(1), currentFrame2(1), elapsedTime(0.0f), animationSpeed(15.0f), isMoving(false), BossSpeed(0.5f), MaxBossHP(300), BossHP(300) {
	BossSprite.setPosition(Vector2f(48.5 * 96, 37.5 * 96));
}

void Boss::draw(sf::RenderWindow& window) {
	window.draw(BossSprite);
}

void Boss::update(float deltaTime) {
	elapsedTime += deltaTime;
	if (!isMoving)
	{
		if (elapsedTime >= animationSpeed)
		{
			elapsedTime = 0.0f;
			currentFrame1++;
			currentFrame1 %= 4;
			BossSprite.setTexture(BossTextureIdle[currentFrame1]);
		}
	}
	else if (MaxBossHP == MaxBossHP / 2)
	{
		if (elapsedTime >= animationSpeed)
		{
			elapsedTime = 0.0f;
			currentFrame2++;
			currentFrame2 %= 4;
			BossSprite.setTexture(BossTextureRun[currentFrame2]);
		}
	}
	else {
		
	}
	cout << BossHP << endl;
	BossSprite.setPosition(BossSprite.getPosition());
}

void Boss::loadTexture() {
	for (int i = 0; i < 4; ++i) {
		if (!BossTextureIdle[i].loadFromFile("Assets/Boss/Idle/BossIdle" + to_string(i) + ".png"))
		{
			cerr << "erreur de chargement des asset Idle du boss" << endl;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!BossTextureRun[i].loadFromFile("Assets/Boss/Run/RunBoss" + to_string(i) + ".png"))
		{
			cerr << "erreur de chargement des asset Run du Boss" << endl;
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
		isMoving = true;
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

int Boss::getHP() const {
	return BossHP;
}

void Boss::setHP(int _HP) {
	BossHP = _HP;
}