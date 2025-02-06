#pragma once
#include "Player.h"
#include "Enemy2.h"
#include <fstream>

using namespace std;
using namespace sf;

class Enemy2Manager
{
protected:
	vector<unique_ptr<Enemy2>> enemy2;
public:
	void creerEnemy2(int x, int y);
	void detruireEnemy2(unique_ptr<Enemy2>& enemy);
	//void readFile();
};