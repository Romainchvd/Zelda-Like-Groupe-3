#pragma once
#include "Player.h"
#include "Enemy1.h"
#include <fstream>

using namespace std;
using namespace sf;

class Enemy1Manager
{
protected:
	vector<unique_ptr<Enemy1>> enemy1;
public:
	void creerEnemy1(int x, int y);
	void detruireEnemy1(unique_ptr<Enemy1>& enemy);
	//void readFile();
};