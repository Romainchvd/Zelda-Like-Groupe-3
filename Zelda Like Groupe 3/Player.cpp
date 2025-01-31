#include "Player.h"
using namespace std;
using namespace sf;

Player::Player(Vector2i p, int s) : position(p), speed(s), currentFrame(1), animationSpeed(2.0f), elapsedTime(0.0f), isMoving(false), isMovingLeft(false), isMovingRight(false) {
}

void Player::update(float deltatime) {
	elapsedTime += deltatime;
		if (elapsedTime >= animationSpeed) {
			elapsedTime = 0.0f;
			currentFrame++;
			currentFrame %= 4;
			sprite.setTexture(playerRunTexture[currentFrame]);
			sprite.setScale(2.2f, 2.2f);
			sprite.setOrigin(16, 16);
		}
}

void Player::draw(RenderWindow& window) {
	window.draw(sprite);
}

void Player::loadTexture() {
	for (int i = 0; i < 4; ++i) {
		if (!playerRunTexture[i].loadFromFile("Assets/Player/idle/idle" + to_string(i) + ".png")) {
			cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
		}
	}
	if (!TexturePlayer.loadFromFile("Assets/Player/player.png"))
	{
		cout << "faire le try cash ici je pense";
	}
	sprite.setPosition(250, 200); //Maison
//	sprite.setPosition(48 * 96 ,24 * 96); // Exterieur
	sprite.setTexture(TexturePlayer);
	sprite.setOrigin(28, 112);
	sprite.setScale(Vector2f(1, 1));
}

void Player::Mouvement() {
	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		sprite.move(Vector2f(0.0f, -1.5f));
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		sprite.move(Vector2f(-1.5f, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		sprite.move(Vector2f(0.0f, 1.5f));
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		sprite.move(Vector2f(1.5f, 0.0f));
	}
}

void Player::Colision() {
	if (sprite.getPosition().x + sprite.getScale().x >= 1920)
	{
		sprite.move(Vector2f(-1.0f, 0.0f));
	}
	if (sprite.getPosition().x <= 0)
	{
		sprite.move(Vector2f(1.0f, 0.0f));
	}
	if (sprite.getPosition().y + sprite.getScale().y >= 1080)
	{
		sprite.move(Vector2f(0.0f, -1.0f));
	}if (sprite.getPosition().y <= 0)
	{
		sprite.move(Vector2f(0.0f, 1.0f));
	}
}

Vector2f Player::getPosition() const {
	return position;
}