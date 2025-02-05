#include "MusicPlayer.h"
#include "Map.h"
void MusicPlayer::loadFile()
{
	if (!house.openFromFile("Assets/music/house.ogg")) throw("Musique introuvable: maison");
	house.setLoop(true);
	if (!field.openFromFile("Assets/music/field.ogg")) throw("Musique introuvable: plaine");
	field.setLoop(true);
	if (!boss1.openFromFile("Assets/music/finalBoss1.ogg")) throw("Musique introuvable: boss1");
	boss1.setLoop(true);
	if (!boss2.openFromFile("Assets/music/finalBoss2.ogg")) throw("Musique introuvable: boss2");
	boss2.setLoop(true);
	if (!credit.openFromFile("Assets/music/credits.ogg")) throw("Musique introuvable: credit");
	credit.setLoop(false);
	if (!guard.openFromFile("Assets/music/knight.ogg")) throw("Musique introuvable: guarde");
	guard.setLoop(true);
	//if (!titleScreen.openFromFile("Assets/music/boss2.ogg")) throw("Musique introuvable: boss2");
	//if (!prologue.openFromFile("Assets/music/boss2.ogg")) throw("Musique introuvable: boss2");
	//if (!epilogue.openFromFile("Assets/music/boss2.ogg")) throw("Musique introuvable: boss2");
	if (!castle.openFromFile("Assets/music/castle.ogg")) throw("Musique introuvable: chateau");
	castle.setLoop(true);
}
void MusicPlayer::playCastle()
{
	house.stop();
	field.stop();
	guard.stop();
	if (castle.getStatus() != Sound::Playing)
	{
		castle.play();
	}
}
void MusicPlayer::playField()
{
	house.stop();
	castle.stop();
	guard.stop();
	if (field.getStatus() != Sound::Playing)
	{
		field.play();
	}
}
void MusicPlayer::playHouse()
{
	field.stop();
	castle.stop();
	guard.stop();
	if (house.getStatus() != Sound::Playing)
	{
		house.play();
	}
}
void MusicPlayer::playMusic(Player& player, unique_ptr<Prop>& prop)
{
	if (player.sprite.getGlobalBounds().intersects(prop->sprite.getGlobalBounds()))
	{
		switch (prop->id)
		{
		case CASTLEFLOOR:
			playCastle();
			break;
		case GRASS:
			playField();
			break;
		case STONE:
			playField();
			break;
		case HOUSEFLOOR:
			playHouse();
			break;
		default:
			break;
		}
	}
}