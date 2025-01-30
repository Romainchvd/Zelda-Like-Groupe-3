#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
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