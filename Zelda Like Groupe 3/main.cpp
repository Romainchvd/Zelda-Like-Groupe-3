#include "Game.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>

using namespace std;



Player player1(Vector2i(100, 100), 10);

int main()
{
	Game game;
	game.propManager.readFile();
	Renderer renderer;
	renderer.run(player1, game.propManager);
	return 0;
}