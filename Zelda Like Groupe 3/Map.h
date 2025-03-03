#pragma once
#include<SFML/Graphics.hpp>
#include "Player.h"
#include <fstream>
class Game;
using namespace std;
using namespace sf;
enum Id {
	STONE, HOUSEFLOOR, GRASS, HOUSEUR, HOUSEUL, HOUSEDL, HOUSEDR, TOWER_BOTTOM, TOWER_TOP, TOWER_BASE, CWALLH, CWALLD, CWALLV, HOUSEWALL, HOUSEROOFU, HOUSEROOFR, HOUSEROOFL, HOUSEROOFD,
	BED_TOP, BED_BOTTOM, KITCHEN, DRESSER, SINK, COUNTER, CARPET, CARPET_OUTDOOR, TREE_BOTTOM, TREE_TOP, GUARD_HOUSE_DL, GUARD_HOUSE_DR, GUARD_HOUSE_UL, GUARD_HOUSE_UR, SPIKES_T, SPIKES_F,
	INTERRUPTOR_T, INTERRUPTOR_F, KEY, DOOR, FENCES_H, FENCES_V, CASTLE_DOOR_E, CASTLE_WALL_E, CASTLE_WINDOW_E, FLAG, CASTLEWALL_RIGHT,
	CASTLEWALL_LEFT, CASTLEWALL_UP, CASTLEWALL_DOWN, CASTLEWALL_UPLEFT, CASTLEWALL_UPRIGHT, CASTLEWALL_DOWNLEFT, CASTLEWALL_DOWNRIGHT, CASTLEFLOOR, GATE,
	CASTLE_SQUARE_UL, CASTLE_SQUARE_UR, CASTLEWALL_DOWNLEFTE, CASTLEWALL_DOWNRIGHTE, CHEST, SWORD, HEART, HEART_CHARGE
};
enum Layer { FIRST_LAYER, SECOND_LAYER };

class PropManager;

class Prop
{
public:
	Sprite sprite;
	Texture texture;
	void setTexture();
	Id id;
	bool isPossibleColision = false;
	bool InteractionPossible = false;
	bool opened = false;
	void collectProp(Player& player, PropManager& manager);
	void useKey(Player& player, PropManager& manager);
	Prop(Id i);
};

class PropManager
{
protected:
	vector<unique_ptr<Prop>> firstLayer;
	vector<unique_ptr<Prop>> secondLayer;
public:
	void creerProp(Id id, int x, int y, Layer layer, bool c, bool i);
	void detruireProp(unique_ptr<Prop>& prop);
	void readFile(Game& game);
	vector<unique_ptr<Prop>>& getFirstLayer();
	vector<unique_ptr<Prop>>& getSecondLayer();
};