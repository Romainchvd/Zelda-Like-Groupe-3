#pragma once
#include <iostream>
#include "Entity.h"

class Enemy1;
class Garde;
class Prop;
class PropManager;

using namespace std;
using namespace sf;

class Player :public Entity {
protected:
	bool isMoving;
	bool isMovingLeft;
	bool isMovingRight;
	bool isMovingDown;
	bool isMovingUp;
	float animationSpeed = 0.1f;
	float elapsedTime;
	int currentFrame = 0;
	int currentFrame2 = 0;
	int currentFrame3 = 0;
	int currentFrame4 = 0;
	Texture TexturePlayer;
	Texture playerRunTexture[6];
	Texture playerRunUpTexture[4];
	Texture playerRunDownTexture[4];
	Texture playerIdleTexture[4];
	Texture playerIdleSwordTexture[4];
	Texture playerAttackSwordTexture[4];
	Texture playerAttackSwordTextureUp[4];
	Texture playerAttackSwordTextureDown[4];
	Texture playerSwordDown[4];
	Texture playerSwordUp[4];
	Texture TexturePressE;
	Sprite playersprite;
	Vector2f position;
public:
	bool isOnCarpet = false;
	bool closeToChest = false;
	bool canPressE = true;
	bool canAttack = true;
	bool isAttacking = false;
	bool hasSword = false;
	Sprite sprite;
	Sprite PressE;
	int speed;
	int keyCounter = 0;
	FloatRect Phitbox;
	Player(int s);
	void update(float deltatime) override;
	void draw(sf::RenderWindow& window) override;
	void loadTexture();
	void Mouvement();
	void Colision(unique_ptr<Prop>& prop);
	void Interact(unique_ptr<Prop>& prop, RenderWindow& window);
	void DrawPressE(RenderWindow& window);
	Vector2f getPosition() const;
	FloatRect getHitbox() const;
	Clock ClockPressE;
	Time PressEDiration = seconds(0.2f);
	Clock ClockCanPressE;
	Clock swordClock;
	Clock isUsingSwordClock;
	Clock chestCanPressEClock;
	Time swordUsingDuration = seconds(0.1);
	Time swordCooldown = seconds(1);
	Time CanPressEDiration = seconds(1);
	Time chestCanPressETimeToDisapear = seconds(0.1);
	Sound sword;
	Sound chest;
	Sound collect;
	Sound solved;
	Sound fist;
	SoundBuffer swordB;
	SoundBuffer chestB;
	SoundBuffer collectB;
	SoundBuffer solvedB;
	SoundBuffer fistB;
	Text keyNumber;
	Font UIFont;
	Sprite keyInterface;
	Texture keyInterfaceTexture;
	void swordAttackCheck();
	void swordAttackCheck2();
	void drawInterface(View& view, RenderWindow& window);
	template<typename T1>
	void swordAttack(T1& enemy)
	{
		if constexpr (is_same_v<T1, unique_ptr<Enemy1>>)
		{
			if (sprite.getGlobalBounds().intersects(enemy->enemy1sprite.getGlobalBounds()))
			{
				cout << "Good" << endl;
				enemy->health -= attack;
				enemy->hit.play();
				isAttacking = false;
			}
		}
		if constexpr (is_same_v<T1, unique_ptr<Garde>>) {
			if (sprite.getGlobalBounds().intersects(enemy->gardesprite.getGlobalBounds()))
			{
				cout << "Good" << endl;
				enemy->health -= attack;
				enemy->hit.play();
				isAttacking = false;
			}
		}
	}
};