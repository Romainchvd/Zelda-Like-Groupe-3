#include "garde.h"

using namespace sf;
using namespace std;

Texture garde;

void Garde::loadTexture() {
    for (int i = 0; i < 4; ++i) {
        if (!gardeIdleTexture[i].loadFromFile("Assets/Enemies/idlegarde/idlegarde" + to_string(i) + ".png")) {
            cerr << "Erreur lors du chargement de l'image run de l'ennemis" << endl;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (!gardeRunTexture[i].loadFromFile("Assets/Enemies/rungarde/rungarde" + to_string(i) + ".png")) {
            cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
        }
    }
    gardesprite.setTexture(gardeIdleTexture[1]);
    gardesprite.setScale(Vector2f(2.2f, 2.2f));
}

Garde::Garde(Vector2f startPosition) : position(startPosition), currentFrame(1), currentFrame2(1), animationSpeed(15.0f), elapsedTime(0.0f), isMoving(false) {
    hitbox = gardesprite.getGlobalBounds();
    gardesprite.setPosition(position);
    gardesprite.setScale(0.4f, 0.4f);
    gardesprite.setOrigin(11, 17);
    maxHealth = 70.0f;
    health = maxHealth;
    if (!hitB.loadFromFile("Assets/sounds/hit.ogg")) throw("Erreur lors du chargement du son hit pour l'ennemi");
    hit.setBuffer(hitB);
}

void Garde::updateMovement(Player& player, float deltatime) {
    elapsedTime2 += deltatime;
    direction = player.getPosition() - position;
    float previousX = position.x;
    float distance = hypot(direction.x, direction.y);

    if (gardesprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
        if (elapsedTime2 >= cooldown) {
            elapsedTime2 = 0.0f;
            player.health -= 5;
            cout << player.health << endl;
            hit.play();
        }
    }
    if (!isDead) {

        if (distance < 500 && distance > 10) {
            direction /= distance;
            position += direction * 0.4f;
            isMoving = true;
        }
        else {
            isMoving = false;
            position.x -= 0.0f;
        }
    }
    if (position.x > previousX) {
        gardesprite.setScale(2.2f, 2.2f);
    }
    else {
        gardesprite.setScale(-2.2f, 2.2f);
    }
    gardesprite.setPosition(position);

}


void Garde::checkDeath() {
    if (health <= 0.0f) {
        isDead = true;
    }
}

void Garde::draw(RenderWindow& window) {
    window.draw(gardesprite);
}

Vector2f Garde::getPosition() const {
    return position;
}

FloatRect Garde::getHitbox() const {
    return hitbox;
}

FloatRect Garde::getFollowHitbox() const {
    return followHitbox;
}

void Garde::update(float deltatime) {
    elapsedTime += deltatime;
    if (!isMoving) {
        if (elapsedTime >= animationSpeed) {
            elapsedTime = 0.0f;
            currentFrame++;
            currentFrame %= 4;
            gardesprite.setTexture(gardeIdleTexture[currentFrame]);
        }
    }
    else {
        if (elapsedTime >= animationSpeed) {
            elapsedTime = 0.0f;
            currentFrame2++;
            currentFrame2 %= 4;
            gardesprite.setTexture(gardeRunTexture[currentFrame2]);
        }
    }
}

void Garde::Colision(unique_ptr<Prop>& prop) {
    if (prop->isPossibleColision)
    {
        if (gardesprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()))
        {
            position += direction * -0.4f;
            isMoving = true;
        }
    }
}
