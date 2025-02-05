#pragma once
#include "Player.h"
#include <SFML/Audio.hpp>
class MusicPlayer
{
public:

	Music house;
	Music field;
	Music boss1;
	Music boss2;
	Music credit;
	Music guard;
	Music titleScreen;
	Music prologue;
	Music epilogue;
	Music castle;

	void loadFile();
	void playMusic(Player& player, unique_ptr<Prop>& prop);
	void playCastle();
	void playHouse();
	void playField();
	void playGuard();
};

