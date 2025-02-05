#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class Entity {
public:
	Vector2f direction;
	Sprite sprite;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	int health;
	int attack;
	int maxHealth;
	Sound hit;
	SoundBuffer hitB;
};

