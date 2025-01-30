#include "Player.h"
using namespace std;
using namespace sf;

Player::Player(Vector2i p, int s) : position(p), speed(s) {}

void Player::update(float deltatime) {}

void Player::draw(RenderWindow& window) {
	window.draw(sprite);
}

void Player::loadTexture() {
	if (!TexturePlayer.loadFromFile("Mettez Le Chemin D'acces"))
	{
		cout << "faire le try cash ici je pense";
	}
	sprite.setPosition(sprite.getPosition());
	sprite.setTexture(TexturePlayer);
	sprite.setScale(Vector2f(1, 1));
}

void Player::Mouvement() {
	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		sprite.move(Vector2f(0.0f, 1.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		sprite.move(Vector2f(-1.0f, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		sprite.move(Vector2f(0.0f, -1.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		sprite.move(Vector2f(1.0f, 0.0f));
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