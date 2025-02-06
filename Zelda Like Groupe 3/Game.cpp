#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game(float x, float y) {
	//enemy1.push_back(std::make_unique<Enemy1>(Vector2f(4400.0f, 2200.f)));
	//for (auto it = enemy1.begin(); it != enemy1.end();) {
		//std::cout << "ok";
//}
	shape.setSize(Vector2f(x, y));
	victoryFont.loadFromFile("assets/font/victoryFont.ttf");
	victoryText.setFont(victoryFont);
	shape.setFillColor(sf::Color::Black);
	enemy1.emplace_back(std::make_unique<Enemy1>(Vector2f(4800.0f, 3650.f)));
	enemy2.emplace_back(std::make_unique<Enemy2>(Vector2f(4600.0f, 2850.f)));
	garde.emplace_back(std::make_unique<Garde>(Vector2f(22 * 96, 4 * 96)));
	
	/*Enemy1Manager enemy1;
	Enemy2Manager enemy2;
	GardeManager garde;*/

	boss.emplace_back(make_unique<Boss>());
	//for (auto it = enemy2.begin(); it != enemy2.end();) {
	//	std::cout << "ok" << endl;
		//it++;
	//}
	if (!playT.loadFromFile("Assets/buttonPlay.png")) throw("Erreur texture bouton play");
	if (!exitT.loadFromFile("Assets/buttonExit.png")) throw("Erreur texture bouton exit");
	if (!editorT.loadFromFile("Assets/buttonEdit.png")) throw("Erreur texture bouton edit");
	if (!TitleScreenT.loadFromFile("Assets/titleScreen.png")) throw("Erreur texture ecran titre");
	if (!LostT.loadFromFile("Assets/lost.png")) throw("Erreur texture ecran defaite");
	if (!WonT.loadFromFile("Assets/win.png")) throw("Erreur texture ecran victoire");
	playS.setTexture(playT);
	exitS.setTexture(exitT);
	editorS.setTexture(editorT);
	TitleScreenS.setTexture(TitleScreenT);
	lostS.setTexture(LostT);
	wonS.setTexture(WonT);
	playS.setPosition(10, 700);
	exitS.setPosition(711, 700);
	editorS.setPosition(1410, 700);
}

