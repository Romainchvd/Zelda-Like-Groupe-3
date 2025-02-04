#pragma once
#include "Player.h"
#include <fstream>

using namespace std;
using namespace sf;
enum Id {
	STONE, HOUSEFLOOR, GRASS, HOUSEUR, HOUSEUL, HOUSEDL, HOUSEDR, TOWER_BOTTOM, TOWER_TOP, TOWER_BASE, CWALLH, CWALLV, HOUSEWALL, HOUSEROOFU, HOUSEROOFR, HOUSEROOFL, HOUSEROOFD,
	BED_TOP, BED_BOTTOM, KITCHEN, DRESSER, SINK, COUNTER, CARPET, CARPET_OUTDOOR, TREE_BOTTOM, TREE_TOP, GUARD_HOUSE_DL, GUARD_HOUSE_DR, GUARD_HOUSE_UL, GUARD_HOUSE_UR, SPIKES_T, SPIKES_F,
	INTERRUPTOR_T, INTERRUPTOR_F, KEY, DOOR, FENCES_H, FENCES_V, CASTLE_DOOR, CASTLE_WALL, CASTLE_WINDOW, FLAG
};
enum Layer {FIRST_LAYER, SECOND_LAYER};

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
	void addKey(Player& player, PropManager& manager);
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
	void readFile();
	vector<unique_ptr<Prop>>& getFirstLayer();
	vector<unique_ptr<Prop>>& getSecondLayer();
};
//Les classes suivantes sont en développement et ne doivent pas être utilisée car non flexibles.
class Interruptor
{
public:
	Texture interruptorActivated;
	Texture interruptorDisabled;
	Sprite interruptor;
	bool interruptorIsActivated = false;
	bool interruptorCanChangeState = true;
};

class Spikes : public Interruptor
{
public:
	Texture spikesActivated;
	Texture spikesDisabled;
	Sprite sprite;
	void checkInterruptor(Player& player);
	Spikes();
};