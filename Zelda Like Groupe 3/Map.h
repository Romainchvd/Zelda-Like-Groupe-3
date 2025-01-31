#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace sf;
enum Id {
	STONE, HOUSEFLOOR, GRASS, HOUSEUR, HOUSEUL, HOUSEDL, HOUSEDR, TOWER_BOTTOM, TOWER_TOP, TOWER_BASE, CWALLH, CWALLV, HOUSEWALL, HOUSEROOFH, HOUSEROOFR, HOUSEROOFL,
	BED_TOP, BED_BOTTOM, KITCHEN, DRESSER, SINK, COUNTER, CARPET, TREE_BOTTOM, TREE_TOP, GUARD_HOUSE_DL, GUARD_HOUSE_DR, GUARD_HOUSE_UL, GUARD_HOUSE_UR
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
	Prop(Id i);
};

class PropManager
{
protected:
	vector<Prop*> firstLayer;
	vector<Prop*> secondLayer;
public:
	~PropManager();
	Prop* creerProp(Id id, int x, int y, Layer layer);
	void detruireProp(Prop* prop);
	void readFile();
	vector<Prop*> getFirstLayer();
	vector<Prop*> getSecondLayer();
};