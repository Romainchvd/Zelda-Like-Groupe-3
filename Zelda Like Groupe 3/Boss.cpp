#include "Boss.h"

using namespace std;
using namespace sf;

Boss::Boss() : currentFrame1(1), currentFrame2(1), currentFrame3(1), currentFrame4(1), elapsedTime(0.0f), animationSpeed(15.0f), isMoving(false), BossSpeed(0.5f), MaxBossHP(300), BossHP(300), Phase2(false) {
	BossSprite.setPosition(Vector2f(114*96, 14*96));
}

void Boss::draw(sf::RenderWindow& window) {
	window.draw(BossSprite);
}

void Boss::update(float deltaTime) {
	elapsedTime += deltaTime;
	if (BossHP == MaxBossHP / 2) {
		Phase2 = true;
	}
	if (!Phase2)
	{
		if (!isMoving)
		{
			if (elapsedTime >= animationSpeed)
			{
				elapsedTime = 0.0f;
				currentFrame1++;
				currentFrame1 %= 4;
				BossSprite.setTexture(BossTextureIdle1[currentFrame1]);
			}
		}
		else
		{
			if (elapsedTime >= animationSpeed)
			{
				elapsedTime = 0.0f;
				currentFrame2++;
				currentFrame2 %= 4;
				BossSprite.setTexture(BossTextureRun1[currentFrame2]);
			}
		}
	}
	else
	{
		if (!isMoving)
		{
			if (elapsedTime >= animationSpeed)
			{
				elapsedTime = 0.0f;
				currentFrame3++;
				currentFrame3 %= 3;
				BossSprite.setTexture(BossTextureIdle2[currentFrame3]);
				BossSprite.setTextureRect(IntRect(0, 0, 38, 38));
			}
		} 
		else
		{
			if (elapsedTime >= animationSpeed)
			{
				elapsedTime = 0.0f;
				currentFrame4++;
				currentFrame4 %= 4;
				BossSprite.setTexture(BossTextureRun2[currentFrame4]);
				BossSprite.setTextureRect(IntRect(0, 0, 38, 40));
			}
		}
	}
	BossSprite.setPosition(BossSprite.getPosition());
}

void Boss::loadTexture() {
	for (int i = 0; i < 4; ++i) {
		if (!BossTextureIdle1[i].loadFromFile("Assets/Boss/Idle/Boss1Idle" + to_string(i) + ".png"))
		{
			cerr << "erreur de chargement des asset Idle1 du boss" << endl;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (!BossTextureIdle2[i].loadFromFile("Assets/Boss/Idle/Boss2Idle" + to_string(i) + ".png"))
		{
			cerr << "erreur de chargement des asset Idle2 du boss" << endl;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!BossTextureRun1[i].loadFromFile("Assets/Boss/Run/Run1Boss" + to_string(i) + ".png"))
		{
			cerr << "erreur de chargement des asset run du boss" << endl;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!BossTextureRun2[i].loadFromFile("Assets/Boss/Run/Run2Boss" + to_string(i) + ".png"))
		{
			cerr << "erreur de chargement des asset run du boss" << endl;
		}
	}
	BossSprite.setTexture(BossTextureIdle1[1]);
	BossSprite.setScale(Vector2f(2.0f, 2.0f));
}

void Boss::Movement(Player& player) {
	direction = player.sprite.getPosition() - BossSprite.getPosition();
	float distance = hypot(direction.x, direction.y);
	
	if (distance < 400)
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
	else
	{
		isMoving = false;
	}
}

int Boss::getHP() const {
	return BossHP;
}

void Boss::setHP(int _HP) {
	BossHP = _HP;
}