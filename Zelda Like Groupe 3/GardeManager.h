#pragma once
#include "Player.h"
#include "Garde.h"
#include <fstream>

using namespace std;
using namespace sf;

class GardeManager
{
protected:
	vector<unique_ptr<Garde>> garde;
public:
	void creerGarde(int x, int y);
	void detruireGarde(unique_ptr<Garde>& enemy);
	//void readFile();
};