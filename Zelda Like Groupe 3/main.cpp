#include "Game.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>

using namespace std;


Player player1(10);

int main()
{
	Game game(1920, 1080);
	game.musicManager.loadFile();
	player1.loadTexture();
	game.propManager.readFile();
	Renderer renderer;
	renderer.run(player1, game.propManager , game.enemy1, game.garde, game);
	
	return 0;
}