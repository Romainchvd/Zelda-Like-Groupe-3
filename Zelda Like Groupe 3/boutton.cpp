include "boutton.h"

Boutton::Play(){}
x = 120;
y = 50;
sf::RectangleShape shape(sf::Vector2f(x, y));
x = 100:
y = 100
shape.setPosition(x, y);
}
void Boutton::click() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && (mouseRect.interscts(BackButtonRect) {
	}
}
void Boutton::draw(sf::RenderWindow& window) {
	window.draw(shape);
}


Boutton::Exit() {}
x = 120;
y = 50;
sf::RectangleShape shape(sf::Vector2f(x, y));
x = 100:
y = 300
shape.setPosition(x, y);
}
void Boutton::click() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && (mouseRect.interscts(BackButtonRect) {
		window.close();
	}
}
void Boutton::draw(sf::RenderWindow& window) {
	window.draw(shape);
}
