#include "enemy1.h"

using namespace sf;
using namespace std;

Texture enemy1;


void Enemy1::loadTexture() {
    for (int i = 0; i < 4; ++i) {
       if (! enemy1IdleTexture[i].loadFromFile("Assets/Enemies/idle/idle" + to_string(i) + ".png")) {
            cerr << "Erreur lors du chargement de l'image run de l'ennemis" << endl;
       }
    }
   /* for (int i = 0; i < 4; ++i) {
        if (!enemy1RunTexture[i].loadFromFile("Assets/Enemies/run/run" + to_string(i) + ".png")) {
            cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
        }
    }*/
    enemy1sprite.setTexture(enemy1IdleTexture[1]);
    enemy1sprite.setScale(Vector2f(2.2f, 2.2f));
}

Enemy1::Enemy1(Vector2f startPosition) : position(startPosition), currentFrame(1), currentFrame2(1), animationSpeed(15.0f), elapsedTime(0.0f), isMoving(false) {
	enemy1sprite.setPosition(position);

	enemy1sprite.setScale(0.4f, 0.4f);
	hitbox = enemy1sprite.getGlobalBounds();
    followHitbox.left = hitbox.left - hitbox.width;
    followHitbox.top = hitbox.top - hitbox.height;
    followHitbox.width = hitbox.width * 4.4f;
    followHitbox.height = hitbox.height * 3.5f;
    maxHealth = 100.0f;
}

void Enemy1::updateMovement(const Player& player) {
    Vector2f direction = player.getPosition() - position;
    float distance = hypot(direction.x, direction.y);

    followHitbox.left = position.x - hitbox.width - 10;
    followHitbox.top = position.y - hitbox.height;

    if (followHitbox.intersects(player.getHitbox()) && !isDead) {
        isFollowing = true;
    }

    if (isFollowing && !isDead) {
        if (distance > 1.0f) {
            direction /= distance;
            position += direction * 40.0f;
        }
    }
    else if (!isDead) {
        position.x -= 50.0f;
    }
    else if (isDead) {
        position.x -= 65.f;
    }

    sprite.setPosition(position);
}


void Enemy1::checkDeath() {
	if (health <= 0.0f) {
		isDead = true;
	}
}

void Enemy1::draw(RenderWindow& window) {
	window.draw(enemy1sprite);
}

Vector2f Enemy1::getPosition() const {
	return position;
}

FloatRect Enemy1::getHitbox() const {
	return hitbox;
}

FloatRect Enemy1::getFollowHitbox() const {
	return followHitbox;
}

void Enemy1::update(float deltatime) {
	elapsedTime += deltatime;
	//if (!isMoving) {
		if (elapsedTime >= animationSpeed) {
			elapsedTime = 0.0f;
			currentFrame++;
            cout << currentFrame << endl;
	        currentFrame %= 4;
			enemy1sprite.setTexture(enemy1IdleTexture[currentFrame]);
			//sprite.setOrigin(16, 16);
		}
	//}
	//else {
			//if (elapsedTime >= animationSpeed) {
				//elapsedTime = 0.0f;
				//currentFrame2++;
				//currentFrame2 %= 4;
				//sprite.setTexture(enemy1RunTexture[currentFrame2]);
				//sprite.setOrigin(16, 16);	
		//}
	//}
}