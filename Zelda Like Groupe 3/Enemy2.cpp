#include "enemy2.h"

using namespace sf;
using namespace std;

Texture enemy2;

void Enemy2::loadTexture() {
    for (int i = 0; i < 4; ++i) {
        if (!enemy2IdleTexture[i].loadFromFile("Assets/Enemies/enemy2idle/enemy2idle" + to_string(i) + ".png")) {
            cerr << "Erreur lors du chargement de l'image run de l'ennemis" << endl;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (!enemy2RunTexture[i].loadFromFile("Assets/Enemies/enemy2run/enemy2run" + to_string(i) + ".png")) {
            cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
        }
    }
    enemy2sprite.setTexture(enemy2IdleTexture[1]);
    enemy2sprite.setScale(Vector2f(2.2f, 2.2f));
}

Enemy2::Enemy2(Vector2f startPosition) : position(startPosition), currentFrame(1), currentFrame2(1), animationSpeed(15.0f), elapsedTime(0.0f), isMoving(false) {
    hitbox = enemy2sprite.getGlobalBounds();
    enemy2sprite.setPosition(position);

    followHitbox.width = enemy2sprite.getGlobalBounds().width * 5;
    followHitbox.height = enemy2sprite.getGlobalBounds().height * 5;
    followHitbox.left = position.x;
    followHitbox.top = position.y;
    enemy2sprite.setScale(0.4f, 0.4f);
    enemy2sprite.setOrigin(11, 17);
    maxHealth = 120.0f;
    health = maxHealth;
    if (!hitB.loadFromFile("Assets/sounds/hit.ogg")) throw("Erreur lors du chargement du son hit pour l'ennemi");
    hit.setBuffer(hitB);
}

void Enemy2::updateMovement(Player& player, float deltatime) {
    elapsedTime2 += deltatime;
    direction = player.getPosition() - position;
    float previousX = position.x;
    float distance = hypot(direction.x, direction.y);

    if (enemy2sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
        if (elapsedTime2 >= cooldown) {
            elapsedTime2 = 0.0f;
            player.health -= 15;
            cout << player.health << endl;
            hit.play();
        }
    }
    if (!isDead) {

        if (distance < 300 && distance > 10) {
            direction /= distance;
            position += direction * 1.0f;
            isMoving = true;
        }
        else {
            isMoving = false;
            position.x -= 0.0f;
        }
    }
    if (position.x > previousX) {
        enemy2sprite.setScale(2.2f, 2.2f);
    }
    else {
        enemy2sprite.setScale(-2.2f, 2.2f);
    }
    enemy2sprite.setPosition(position);

}


void Enemy2::checkDeath() {
    if (health <= 0.0f) {
        isDead = true;
    }
}

void Enemy2::draw(RenderWindow& window) {
    window.draw(enemy2sprite);
}

Vector2f Enemy2::getPosition() const {
    return position;
}

FloatRect Enemy2::getHitbox() const {
    return hitbox;
}

FloatRect Enemy2::getFollowHitbox() const {
    return followHitbox;
}

void Enemy2::update(float deltatime) {
    elapsedTime += deltatime;
    if (!isMoving) {
        if (elapsedTime >= animationSpeed) {
            elapsedTime = 0.0f;
            currentFrame++;
            currentFrame %= 4;
            enemy2sprite.setTexture(enemy2IdleTexture[currentFrame]);
        }
    }
    else {
        if (elapsedTime >= animationSpeed) {
            elapsedTime = 0.0f;
            currentFrame2++;
            currentFrame2 %= 4;
            enemy2sprite.setTexture(enemy2RunTexture[currentFrame2]);
        }
    }
}

void Enemy2::Colision(unique_ptr<Prop>& prop) {
    if (prop->isPossibleColision)
    {
        if (enemy2sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()))
        {
            position += direction * -1.0f;
            isMoving = true;
        }
    }
}
