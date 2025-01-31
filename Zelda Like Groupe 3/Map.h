#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace sf;
enum Id {
	STONE, HOUSEFLOOR, GRASS, HOUSEUR, HOUSEUL, HOUSEDL, HOUSEDR, TOWERD, TOWERL, TOWER, TOWERUR, TOWERUL, CWALLL, CWALLR, CWALLH, CWALLD, HOUSEWALL, HOUSEROOFH, HOUSEROOFR, HOUSEROOFL,
	BED_TOP, BED_BOTTOM, KITCHEN, DRESSER, SINK, COUNTER, CARPET
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