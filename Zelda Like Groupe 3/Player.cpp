#include "Player.h"
#include "Map.h"
#include "Enemy1.h"
#include <type_traits>
using namespace std;
using namespace sf;


Player::Player(int s) : speed(s), currentFrame(1), currentFrame2(1), currentFrame3(1), currentFrame4(1), animationSpeed(15.0f), elapsedTime(0.0f), isMoving(false), isMovingLeft(false), isMovingRight(false) {
	if (!TexturePressE.loadFromFile("assets/InputTools/PressE.png")) {
		cerr << "Erreur lors du chargement de l'image run du joueur" << endl; }
	PressE.setTexture(TexturePressE);
	PressE.setPosition(48.5 * 96, 37.5 * 96);
	PressE.setScale(0.192f, 0.192f);
	if (!hitB.loadFromFile("Assets/sounds/hit.ogg")) throw("Erreur lors du chargement du son : hit");
	hit.setBuffer(hitB);
	if (!chestB.loadFromFile("Assets/sounds/chest.ogg")) throw("Erreur lors du chargement du son: coffre");
	chest.setBuffer(chestB);
	if (!solvedB.loadFromFile("Assets/sounds/solved.ogg")) throw("Erreur lors du chargement du son: solved");
	solved.setBuffer(solvedB);
	if (!collectB.loadFromFile("Assets/sounds/collected.ogg")) throw("Erreur lors du chargement du son: coffre");
	collect.setBuffer(collectB);
	if (!swordB.loadFromFile("Assets/sounds/slash.ogg")) throw("Erreur lors du chargement du son: attaque � l'�p�e");
	sword.setBuffer(swordB);
	if (!fistB.loadFromFile("Assets/sounds/fist.ogg")) throw("Erreur lors du chargement du son de coup de poing");
	fist.setBuffer(fistB);
	health = 100;
	maxHealth = health;
	attack = 10;
	if (!UIFont.loadFromFile("Assets/Font/victoryFont.ttf")) throw("Erreur lors du chargement de la police d'interface de jeu");
	keyNumber.setFont(UIFont);
	if (keyInterfaceTexture.loadFromFile("Assets/key.png"));
	keyInterface.setTexture(keyInterfaceTexture);
	healthTxt.setFont(UIFont);

}

void Player::update(float deltatime) {
	elapsedTime += deltatime;
	if (hasSword) //Si le joueur a une �p�e
	{
		if (sword.getStatus() == Sound::Playing && hasSword) { // Si le joueur attaque � l'�p�e
			if (elapsedTime >= animationSpeed) {
				if (isMovingRight || isMovingLeft) // Droite ou gauche
				{
					elapsedTime = 0.0f;
					currentFrame2++;
					currentFrame2 %= 4;
					sprite.setTexture(playerAttackSwordTexture[currentFrame2]);
					sprite.setOrigin(10, 14);
					sprite.setTextureRect(IntRect(0, 0, 35, 31));
					if (isMovingRight) {
						sprite.setScale(2.2f, 2.2f);
					}
				    else if (isMovingLeft) {
						sprite.setScale(-2.2f, 2.2f);
					}
				}
				else if (isMovingDown || isMovingUp ) { //Haut ou bas
					if (elapsedTime >= animationSpeed) {
						elapsedTime = 0.0f;
						currentFrame4++;
						currentFrame4 %= 4;
						sprite.setOrigin(10, 14);
						sprite.setTextureRect(IntRect(0, 0, 28, 29));
						if (isMovingUp)
						{
							sprite.setTexture(playerAttackSwordTextureUp[currentFrame4]);
						}
						else if (isMovingDown)
						{
							sprite.setTexture(playerAttackSwordTextureDown[currentFrame4]);
						}
					}
				}

			}
		}
		else if (!isMoving) { //Si le joueur ne bouge pas mais a une �p�e
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame++;
				currentFrame %= 4;
				sprite.setTexture(playerIdleSwordTexture[currentFrame]);
				sprite.setOrigin(10, 14);
				sprite.setTextureRect(IntRect(0, 0, 30, 27));
				if (isMovingRight) {
					sprite.setScale(2.2f, 2.2f);
				}
				else if (isMovingLeft) {
					sprite.setScale(-2.2f, 2.2f);
				}
			}
		}
		else if (isMovingDown || isMovingUp) //S'il va en haut ou en bas sans attaquer
		{
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame3++;
				currentFrame3 %= 4;
				sprite.setOrigin(10, 14);
				sprite.setTextureRect(IntRect(0, 0, 28, 29));
				if (isMovingDown)
					sprite.setTexture(playerSwordDown[currentFrame3]);
				else if (isMovingUp)
					sprite.setTexture(playerSwordUp[currentFrame3]);
			}
		}
		else if (isMovingRight || isMovingLeft) //S'il va � droite ou a gauche sans attaquer
		{
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame3++;
				currentFrame3 %= 6;
				sprite.setOrigin(10, 14);
				sprite.setTextureRect(IntRect(0, 0, 32, 27));
				sprite.setTexture(playerSwordRun[currentFrame3]);
				if (isMovingRight)
					sprite.setScale(2.2f, 2.2f);
				else if (isMovingLeft)
					sprite.setScale(-2.2f, 2.2f);
			}
		}
	}
		else if (!hasSword) { //Si le joueur n'a pas d'�p�e
		 if (!isMoving) { //S'il ne bouge pas
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
				else if (isMovingLeft) {
					sprite.setScale(-2.2f, 2.2f);
				}
			}
		}
	}
	
	
		if (isMovingRight || isMovingLeft) { //S'il va a droite ou a gauche
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame2++;
				currentFrame2 %= 6;
				sprite.setTexture(playerRunTexture[currentFrame2]);
				sprite.setOrigin(10, 14);
				sprite.setTextureRect(IntRect(0, 0, 20, 28));
				if (isMovingRight) {
					sprite.setScale(2.2f, 2.2f);
				}
				else if (isMovingLeft) {
					sprite.setScale(-2.2f, 2.2f);
				}
			}
		}
		
		else if (isMovingUp && !hasSword && sword.getStatus() != Sound::Playing) { // S'il va en haut sans attaquer
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame3++;
				currentFrame3 %= 4;
				sprite.setTexture(playerRunUpTexture[currentFrame3]);
				sprite.setOrigin(10, 14);
				sprite.setTextureRect(IntRect(0, 0, 20, 28));
			}
		}
		
		else if (isMovingDown && !hasSword && sword.getStatus() != Sound::Playing) { //M�me chose en bas
			if (elapsedTime >= animationSpeed) {
				elapsedTime = 0.0f;
				currentFrame4++;
				currentFrame4 %= 4;
				sprite.setTexture(playerRunDownTexture[currentFrame4]);
				sprite.setOrigin(10, 14);
				sprite.setTextureRect(IntRect(0, 0, 20, 28));
			}
		}
		
	PressE.setPosition(sprite.getPosition().x + 20,sprite.getPosition().y -110);
	//cout << canPressE << endl;
}

void Player::draw(RenderWindow& window) {
	window.draw(sprite);
	if (isOnCarpet == true || closeToChest == true)
	{
		//cout << "il passse dedans" << endl;
		DrawPressE(window);
		//cout << boolalpha << closeToChest << endl;
	}

}

void Player::DrawPressE(RenderWindow& window) {
	window.draw(PressE);
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
	for (int i = 0; i < 4; i++)
	{
		if (!playerAttackSwordTexture[i].loadFromFile("Assets/Player/sword_attack/" + to_string(i+1) + ".png")) {
			cerr << "Erreur lors du chargement de l'image swordAttack du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!playerIdleSwordTexture[i].loadFromFile("Assets/Player/sword_idle/" + to_string(i+1) + ".png")) {
			cerr << "Erreur lors du chargement de l'image swordAttack du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!playerAttackSwordTextureDown[i].loadFromFile("Assets/Player/sword_attack_down/" + to_string(i + 1) + ".png")) {
			cerr << "Erreur lors du chargement de l'image swordAttack down du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!playerSwordDown[i].loadFromFile("Assets/Player/sword_down/" + to_string(i + 1) + ".png")) {
			cerr << "Erreur lors du chargement de l'image swordAttack down du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!playerSwordUp[i].loadFromFile("Assets/Player/sword_up/" + to_string(i + 1) + ".png")) {
			cerr << "Erreur lors du chargement de l'image swordAttack down du joueur" << endl;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!playerAttackSwordTextureUp[i].loadFromFile("Assets/Player/sword_attack_up/" + to_string(i + 1) + ".png")) {
			cerr << "Erreur lors du chargement de l'image swordAttack up du joueur" << endl;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (!playerSwordRun[i].loadFromFile("Assets/Player/sword_run/" + to_string(i + 1) + ".png")) {
			throw ("Erreur lors du chargement de l'image run sword up du joueur");
		}
	}
	sprite.setPosition(250, 296); //Maison

//  sprite.setPosition(20*96, 96*5); //Maison garde
//	sprite.setPosition(112 * 96, 38 * 96); //Donjon Entr�e
	position = sprite.getPosition();
	
//	sprite.setPosition(48.5 * 96, 37.5 * 96); // Exterieur
	//sprite.setTexture(TexturePlayer);
	sprite.setOrigin(10, 14);
	sprite.setScale(Vector2f(2.2f, 2.2f));
}

void Player::Mouvement() {
	//cout << position.x << " " << position.y << endl;
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

	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		isMoving = true;
		isMovingDown = true;
		sprite.move(Vector2f(0.0f, 1.5f));
		position.y += 1.5f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		isMoving = true;
		isMovingRight = false;
		isMovingLeft = true;
		sprite.move(Vector2f(-1.5f, 0.0f));
		position.x -= 1.5f;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		isMoving = true;
		isMovingLeft = false;
		isMovingRight = true;
		sprite.move(Vector2f(1.5f, 0.0f));
		position.x += 1.5f;
	}
}
void Player::Colision(unique_ptr<Prop>& prop) {
	
	if (prop->isPossibleColision)
	{
		if (sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()) && isMovingUp)
		{
			sprite.move(Vector2f(0.0f, 1.5f));
			position.y += 1.5f;
		}
		if (sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()) && isMovingLeft)
		{
			sprite.move(Vector2f(1.5f, 0.0f));
			position.x += 1.5f;
		}
		if (sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()) && isMovingDown)
		{
			sprite.move(Vector2f(0.0f, -1.5f));
			position.y -= 1.5f;
		}
		if (sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()) && isMovingRight)
		{
			sprite.move(Vector2f(-1.5f, 0.0f));
			position.x -= 1.5f;
		}
	}
}

void Player::Interact(unique_ptr<Prop>& prop, RenderWindow& window) {
	if(prop->id == CARPET || prop->id == CARPET_OUTDOOR)
	{
		if (sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()) && prop->InteractionPossible)
		{
			isOnCarpet = true;
		}
		else if ((sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()) && prop->InteractionPossible) == false
			&& ClockPressE.getElapsedTime().asSeconds() > PressEDiration.asSeconds())
		{
			isOnCarpet = false;
			ClockPressE.restart();
		}

		if (ClockCanPressE.getElapsedTime().asSeconds() > CanPressEDiration.asSeconds() && canPressE == false)
		{
			canPressE = true;
		}
		if (isOnCarpet && sprite.getPosition().x >= 47 * 96 && sprite.getPosition().y >= 35 * 96
			&& sprite.getPosition().x <= 50 * 96 && sprite.getPosition().y <= 38 * 96 && canPressE)
		{
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				sprite.setPosition(4 * 96, 4 * 96);
				canPressE = false;
				ClockCanPressE.restart();
			}
		}
		if (isOnCarpet && sprite.getPosition().x >= 58 * 96 && sprite.getPosition().y >= 31 * 96
			&& sprite.getPosition().x <= 61 * 96 && sprite.getPosition().y <= 32 * 96 && canPressE)
		{
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				sprite.setPosition(19 * 96, 5 * 96);
				canPressE = false;
				ClockCanPressE.restart();
			}
		}
		if (isOnCarpet && sprite.getPosition().x >= 3 * 96 && sprite.getPosition().y >= 5 * 96
			&& sprite.getPosition().x <= 5 * 96 && sprite.getPosition().y <= 6 * 96 && canPressE)
		{
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				sprite.setPosition(48.5 * 96, 38.5 * 96);
				canPressE = false;
				ClockCanPressE.restart();
			}
		}
		if (isOnCarpet && sprite.getPosition().x >= 20 * 96 && sprite.getPosition().y >= 5 * 96
			&& sprite.getPosition().x <= 21 * 96 && sprite.getPosition().y <= 6 * 96 && canPressE)
		{
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				sprite.setPosition(57.9 * 96, 32 * 96);
				canPressE = false;
				ClockCanPressE.restart();
			}
		}
		if (isOnCarpet && sprite.getPosition().x >= 40 * 96 && sprite.getPosition().y >= 22 * 96
			&& sprite.getPosition().x <= 43 * 96 && sprite.getPosition().y <= 23 * 96 && canPressE)
		{
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				sprite.setPosition(110 * 96, 38 * 96);
				canPressE = false;
				ClockCanPressE.restart();
			}
		}
		position = sprite.getPosition();
	}
	else if (prop->id == CHEST && prop->opened == false)
	{
		
		FloatRect playerGB = sprite.getGlobalBounds();
		Vector2f detectionZone{ 32, 32 };
		playerGB.top -= detectionZone.x;
		playerGB.left -= detectionZone.y;
		playerGB.width += 2 * detectionZone.x;
		playerGB.height += 2 * detectionZone.y;
		if (playerGB.intersects(prop->sprite.getGlobalBounds()))
		{
			closeToChest = true;
			DrawPressE(window);
			
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				closeToChest = false;
				prop->opened = true;
				if (!prop->texture.loadFromFile("Assets/chestOpened.png")) throw("Erreur lors du chargement de la texture : coffre ouvert");
				prop->sprite.setTexture(prop->texture);
				keyCounter++;
				collect.play();
			}
		}
	}
	if (chestCanPressEClock.getElapsedTime().asSeconds() > chestCanPressETimeToDisapear.asSeconds() && closeToChest)
	{
		closeToChest = false;
		chestCanPressEClock.restart();
	}
}



Vector2f Player::getPosition() const {
	return position;
}

FloatRect Player::getHitbox() const {
	return Phitbox;
}

void Player::swordAttackCheck()
{
	if (hasSword)
	{
		attack = 20;
	}
	else
	{
		attack = 10;
	}
	if (swordClock.getElapsedTime().asSeconds() > swordCooldown.asSeconds() && canAttack == false)
	{
		canAttack = true;
	}
	else
	{
		canAttack = false;
	}
	if (canAttack && Mouse::isButtonPressed(Mouse::Left))
	{
		swordClock.restart();
		if (hasSword)
			sword.play();
		else
			fist.play();
		isAttacking = true;
	}
}

void Player::swordAttackCheck2()
{
	if (hasSword)
	{
		attack = 20;
	}
	else
	{
		attack = 10;
	}
	if (swordClock.getElapsedTime().asSeconds() > swordCooldown.asSeconds() && canAttack == false)
	{
		canAttack = true;
	}
	else
	{
		canAttack = false;
	}
	if (canAttack && Mouse::isButtonPressed(Mouse::Left))
	{
		swordClock.restart();
		if (hasSword)
			sword.play();
		else
			fist.play();
		isAttacking = true;
	}
}



void Player::drawInterface(View& view, RenderWindow& window)
{
	
	keyInterface.setPosition(view.getCenter().x + 275, view.getCenter().y + 175);
	keyNumber.setPosition(view.getCenter().x + 350, view.getCenter().y + 200);
	healthTxt.setPosition(view.getCenter().x -400, view.getCenter().y + 200);
	window.draw(healthTxt);
	healthTxt.setString("Health: " + to_string(health) + "/" + to_string(maxHealth));
	if (keyCounter > 0)
	{
		window.draw(keyInterface);
		keyNumber.setString("x" + to_string(keyCounter));
		window.draw(keyNumber);
	}
	
}