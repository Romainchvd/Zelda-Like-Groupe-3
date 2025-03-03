#include "Game.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>

using namespace std;


Player player1(10);
Boss boss;
int main()
{
	Game game(1920, 1080);
	game.musicManager.loadFile();
	player1.loadTexture();
	Renderer renderer;
	renderer.run(player1, game.propManager , game.enemy1, game.enemy2, game.garde, game, game.boss);
	
	return 0;
}