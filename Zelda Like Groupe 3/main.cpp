#include "Game.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>

using namespace std;



Player player1(10);
playTest play;

int main()
{
	Game game;
	player1.loadTexture();
	play.loadTexture();
	game.propManager.readFile();
	Renderer renderer;
	renderer.run(player1, game.propManager , game.enemy1);
	return 0;
}