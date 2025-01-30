#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Renderer {
private:
	
public:
	Event event;
	RenderWindow window;
	Renderer();
	void run();
	void draw();
};
