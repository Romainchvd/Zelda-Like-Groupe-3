#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace sf;
enum Id { STONE, HOUSEFLOOR, GRASS, HOUSEUR, HOUSEUL, HOUSEDL, HOUSEDR, TOWERD, TOWERL, TOWER, TOWERUR, TOWERUL, CWALLL, CWALLR, CWALLH, CWALLD };

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
	vector<Prop*> map;
public:
	~PropManager();
	Prop* creerProp(Id id, int x, int y);
	void detruireProp(Prop* prop);
	void readFile();
	vector<Prop*> getMap();
};