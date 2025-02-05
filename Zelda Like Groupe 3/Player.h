#pragma once
#include <iostream>
#include "Entity.h"

class Prop;
class PropManager;

using namespace std;
using namespace sf;

class Player :public Entity {
private:
	
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
	Texture TexturePressE;
	Sprite playersprite;
	Vector2f position;
public:
	bool isOnCarpet = false;
	bool canPressE = true;
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
	void Interact(unique_ptr<Prop>& prop);
	void DrawPressE(RenderWindow& window);
	Vector2f getPosition() const;
	FloatRect getHitbox() const;
	Clock ClockPressE;
	Time PressEDiration = seconds(0.2f);
	Clock ClockCanPressE;
	Time CanPressEDiration = seconds(3.0f);
	Sound sword;
	Sound chest;
	Sound collect;
	Sound solved;
	SoundBuffer swordB;
	SoundBuffer chestB;
	SoundBuffer collectB;
	SoundBuffer solvedB;
};