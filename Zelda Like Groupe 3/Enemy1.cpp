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
    for (int i = 0; i < 4; ++i) {
        if (!enemy1RunTexture[i].loadFromFile("Assets/Enemies/run/run" + to_string(i) + ".png")) {
            cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
        }
    }
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
    enemy1sprite.setOrigin(11, 17);
    maxHealth = 100.0f;
    health = maxHealth;
    if (!hitB.loadFromFile("Assets/sounds/hit.ogg")) throw("Erreur lors du chargement du son hit pour l'ennemi");
    hit.setBuffer(hitB);
}

void Enemy1::updateMovement(const Player& player) {
    direction = player.getPosition() - position;
    float previousX = position.x;
    Vector2f direction = player.getPosition() - position;
    float distance = hypot(direction.x, direction.y);
    
    if (enemy1sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
        cout << "ok" << endl;
    }
    if (!isDead) {
     
        if (distance < 300 && distance > 10) {
            direction /= distance;
            position += direction * 0.6f;
            isMoving = true;
            {
                cout << "il est à mois de 300" << endl;
            isMoving = false;
            position.x -= 0.0f;
            }
        }
        else {
            //position.x -= 0.2f;
        }
  
    // cout << followHitbox.getPosition().x << endl;
    // cout << followHitbox.getPosition().y << endl;
    }
   // else {
      //  enemy1sprite.setScale(2.2f, 2.2f);
   // }
    enemy1sprite.setPosition(position);
    previousX = position.x;
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
	if (!isMoving) {
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

void Enemy1::Colision(unique_ptr<Prop>& prop) {
    if (prop->isPossibleColision)
    {
        if (enemy1sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()))
        { 
            
            
        }
    }
}
		}
	}
	else {
		if (elapsedTime >= animationSpeed) {
			elapsedTime = 0.0f;
			currentFrame2++;
			currentFrame2 %= 4;
            enemy1sprite.setTexture(enemy1RunTexture[currentFrame2]);
		}
	}
}