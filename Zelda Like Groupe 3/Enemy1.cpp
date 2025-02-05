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
    hitbox = enemy1sprite.getGlobalBounds();
	enemy1sprite.setPosition(position);
   
    followHitbox.width = enemy1sprite.getGlobalBounds().width * 5;
    followHitbox.height = enemy1sprite.getGlobalBounds().height * 5;
    followHitbox.left = position.x;
    followHitbox.top = position.y;
	enemy1sprite.setScale(0.4f, 0.4f);
    enemy1sprite.setOrigin(73, 73);
    maxHealth = 100.0f;
    enemy1sprite.setOrigin(12, 20);
    maxHealth = 100;
    health = maxHealth;
}

void Enemy1::updateMovement(const Player& player) {
    Vector2f direction = player.getPosition() - position;
    float distance = hypot(direction.x, direction.y);
    
    if (Keyboard::isKeyPressed(Keyboard::T)) {
        cout << "Position ennemi:" << position.x << "  " << position.y << endl;
        cout << "Position joueur:" << player.getPosition().x << "  " << player.getPosition().y << endl;
        
        cout << distance << endl;
    }
    if (enemy1sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
        cout << "ok" << endl;
    }
    if (!isDead) {
     
        if (distance < 300) {
            direction /= distance;
            position += direction * 0.4f;
        }
        else {
            position.x -= 0.2f;
        }
    }
    else if (isDead) {
        position.x -= 1.f;
    }
  
    // cout << followHitbox.getPosition().x << endl;
    // cout << followHitbox.getPosition().y << endl;
    enemy1sprite.setPosition(position);
}


void Enemy1::checkDeath() {
	if (health <= 0.0f) {
		isDead = true;
	}
}

void Enemy1::draw(RenderWindow& window) {
	window.draw(enemy1sprite);
    RectangleShape hitboxShape(sf::Vector2f(enemy1sprite.getGlobalBounds().width , enemy1sprite.getGlobalBounds().height ));
    hitboxShape.setPosition(followHitbox.left, followHitbox.top);
    hitboxShape.setFillColor(sf::Color(255, 255, 0, 128));
    followHitbox = hitboxShape.getGlobalBounds();
    window.draw(hitboxShape);
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