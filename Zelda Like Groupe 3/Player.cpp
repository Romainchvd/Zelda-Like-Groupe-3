#include "Player.h"
using namespace std;
using namespace sf;

Player::Player(int s) : speed(s), currentFrame(1), currentFrame2(1), currentFrame3(1), currentFrame4(1), animationSpeed(15.0f), elapsedTime(0.0f), isMoving(false), isMovingLeft(false), isMovingRight(false) {
}

void Player::update(float deltatime) {
	elapsedTime += deltatime;
	if (!isMoving) {
		if (elapsedTime >= animationSpeed) {
			elapsedTime = 0.0f;
			currentFrame++;
			currentFrame %= 4;
			sprite.setTexture(playerIdleTexture[currentFrame]);
			sprite.setOrigin(10, 14);
			sprite.setTextureRect(IntRect(0, 0, 20, 28));
			if (isMovingRight) {
				sprite.setScale(2.2f, 2.2f);
			}
			if (isMovingLeft) {
				sprite.setScale(-2.2f, 2.2f);
			}
	     }
	}
	else {
		if (isMovingRight || isMovingLeft) {
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame2++;
				currentFrame2 %= 6;
				sprite.setTexture(playerRunTexture[currentFrame2]);
				sprite.setOrigin(10, 14);
				if (isMovingRight) {
					sprite.setScale(2.2f, 2.2f);
				}
				if (isMovingLeft) {
					sprite.setScale(-2.2f, 2.2f);
				}
			}
		}
		else if (isMovingUp) {
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame3++;
				currentFrame3 %= 4;
				sprite.setTexture(playerRunUpTexture[currentFrame3]);
				sprite.setOrigin(10, 14);
			}
		}
		else if (isMovingDown) {
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame4++;
				currentFrame4 %= 4;
				sprite.setTexture(playerRunDownTexture[currentFrame4]);
				sprite.setOrigin(10, 14);
			}
		}
	}
	//cout << sprite.getPosition().x << ", " << sprite.getPosition().y << endl;
}

void Player::draw(RenderWindow& window) {
	window.draw(sprite);
	RectangleShape hitboxShape(sf::Vector2f(Phitbox.width, Phitbox.height));
	hitboxShape.setPosition(Phitbox.left, Phitbox.top);
	hitboxShape.setFillColor(sf::Color(255, 0, 0, 128));
	window.draw(hitboxShape);
}

void Player::loadTexture() {
	for (int i = 0; i < 6; ++i) {
		if (!playerRunTexture[i].loadFromFile("Assets/Player/run/run" + to_string(i) + ".png")) {
			cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (!playerIdleTexture[i].loadFromFile("Assets/Player/idle/idle" + to_string(i) + ".png")) {
			cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (!playerRunUpTexture[i].loadFromFile("Assets/Player/runup/runup" + to_string(i) + ".png")) {
			cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (!playerRunDownTexture[i].loadFromFile("Assets/Player/rundown/rundown" + to_string(i) + ".png")) {
			cerr << "Erreur lors du chargement de l'image run du joueur" << endl;
		}
	}
	if (!TexturePlayer.loadFromFile("Assets/Player/player.png"))
	{
		cout << "faire le try cash ici je pense";
	}
//	sprite.setPosition(250, 200); //Maison
	sprite.setPosition(48 * 96 ,37 * 96); // Exterieur
	//sprite.setTexture(TexturePlayer);
	sprite.setOrigin(10, 14);
	sprite.setScale(Vector2f(2.2f, 2.2f));
}

void Player::Mouvement() {
	isMoving = false;
	isMovingUp = false;
	isMovingDown = false;
	isMovingRight = false;
	isMovingLeft = false;
	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		isMoving = true;
		isMovingUp = true;
		sprite.move(Vector2f(0.0f, -1.5f));
		position.y -= 1.5f;
		Phitbox = sprite.getGlobalBounds();
		Phitbox.width = 100.0f;
		Phitbox.height = 70.0f;
		Phitbox.left = position.x + 4558;
		Phitbox.top = position.y + 2240;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		isMoving = true;
		isMovingDown = true;
		sprite.move(Vector2f(0.0f, 1.5f));
		position.y += 1.5f;
		Phitbox = sprite.getGlobalBounds();
		Phitbox.width = 100.0f;
		Phitbox.height = 70.0f;
		Phitbox.left = position.x + 4558;
		Phitbox.top = position.y + 2310;
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		isMoving = true;
		isMovingRight = false;
		isMovingLeft = true;
		sprite.move(Vector2f(-1.5f, 0.0f));
		position.x -= 1.5f;
		Phitbox = sprite.getGlobalBounds();
		Phitbox.width = 70.0f;
		Phitbox.height = 100.0f;
		Phitbox.left = position.x + 4546;
		Phitbox.top = position.y + 2260;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		isMoving = true;
		isMovingLeft = false;
		isMovingRight = true;
		sprite.move(Vector2f(1.5f, 0.0f));
		position.x += 1.5f;
		Phitbox = sprite.getGlobalBounds();
		Phitbox.width = 70.0f;
		Phitbox.height = 100.0f;
		Phitbox.left = position.x + 4600;
		Phitbox.top = position.y + 2260;
	}
}
//void Player::Colision(playTest& playTest) {
//	
//
//	/*FloatRect playerBounds = sprite.getGlobalBounds();
//	FloatRect rectBounds = playTest.sprite.getGlobalBounds();
//
//	float ColisionMoveLeft = playerBounds.left + playerBounds.width - rectBounds.left;
//	float ColisionMoveRight = rectBounds.left + rectBounds.width - playerBounds.left;
//	float ColisionMoveTop = playerBounds.top + playerBounds.height - rectBounds.top;
//	float ColisionMoveBottom = rectBounds.top + rectBounds.height - playerBounds.top;*/
//
//	/*if (playerBounds.intersects(rectBounds))
//	{
//		if (ColisionMoveLeft < ColisionMoveRight && ColisionMoveLeft < ColisionMoveTop 
//			&& ColisionMoveLeft < ColisionMoveBottom)
//		{
//			sprite.move(Vector2f(-ColisionMoveLeft, 0.0f));
//		}
//	}*/
//
//	/*if (sprite.getGlobalBounds().intersects(playTest.sprite.getGlobalBounds()) && isMovingRight)
//	{
//		sprite.move(Vector2f(-1.5f, 0.0f));
//	}
//	if (sprite.getGlobalBounds().intersects(playTest.sprite.getGlobalBounds()) && isMovingLeft)
//	{
//		sprite.move(Vector2f(1.5f, 0.0f));
//	}
//	if (sprite.getGlobalBounds().intersects(playTest.sprite.getGlobalBounds()) && isMovingUp)
//	{
//		sprite.move(Vector2f(0.0f, 1.5f));
//	}
//	if (sprite.getGlobalBounds().intersects(playTest.sprite.getGlobalBounds()) && isMovingDown)
//	{
//		sprite.move(Vector2f(0.0f, -1.5f));
//	}*/
//
//}

Vector2f Player::getPosition() const {
	return position;
}

FloatRect Player::getHitbox() const {
	return Phitbox;
}
