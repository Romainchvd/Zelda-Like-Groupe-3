#include "map.h"



void Prop::setTexture()
{
	switch (id)
	{
	case HOUSEDL:
		if (!texture.loadFromFile("assets/houseDL.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case HOUSEDR:
		if (!texture.loadFromFile("assets/houseDR.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case HOUSEUL:
		if (!texture.loadFromFile("assets/houseUL.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case HOUSEUR:
		if (!texture.loadFromFile("assets/houseUR.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case TOWERD:
		if (!texture.loadFromFile("assets/towerD.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case TOWERUL:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case STONE:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case HOUSEFLOOR:
		if (!texture.loadFromFile("assets/woodenplanks.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case GRASS:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case CWALLL:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case TOWER:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case TOWERUR:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case TOWERL:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case CWALLR:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case CWALLH:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case CWALLD:
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
		break;
	case HOUSEWALL:
		if (!texture.loadFromFile("assets/housewall.png")) cerr << "Erreur lors du chargement de la texture de mur de la maison" << endl;
		break;
	case HOUSEROOFH:
		if (!texture.loadFromFile("assets/houseRoofH.png")) cerr << "Erreur lors du chargement de la texture de mur horizontal interieur de la maison" << endl;
		break;
	case HOUSEROOFR:
		if (!texture.loadFromFile("assets/houseRoofR.png")) cerr << "Erreur lors du chargement de la texture de mur droit interieur de la maison" << endl;
		break;
	case HOUSEROOFL:
		if (!texture.loadFromFile("assets/houseRoofL.png")) cerr << "Erreur lors du chargement de la texture de mur gauche interieur de la maison" << endl;
		break;
	case BED_TOP:
		if (!texture.loadFromFile("assets/bedTop.png")) cerr << "Erreur lors du chargement de la texture de lit haut" << endl;
		break;
	case BED_BOTTOM:
		if (!texture.loadFromFile("assets/bedBottom.png")) cerr << "Erreur lors du chargement de la texture de lit bas" << endl;
		break;
	case SINK:
		if (!texture.loadFromFile("assets/sink.png")) cerr << "Erreur lors du chargement de la texture d'evier" << endl;
		break;
	case KITCHEN:
		if (!texture.loadFromFile("assets/kitchen.png")) cerr << "Erreur lors du chargement de la texture de cuisine" << endl;
		break;
	case DRESSER:
		if (!texture.loadFromFile("assets/dresser.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
		break;
	case COUNTER:
		if (!texture.loadFromFile("assets/counter.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
		break;
	case CARPET:
		if (!texture.loadFromFile("assets/carpet.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
		break;
	default:
		break;
	}

	sprite.setTexture(texture);
}

Prop::Prop(Id i) : id(i) {}

PropManager::~PropManager()
{
	for (auto prop : firstLayer)
	{
		delete prop;
	}
	firstLayer.clear();
	for (auto prop : secondLayer)
	{
		delete prop;
	}
	secondLayer.clear();
}
Prop* PropManager::creerProp(Id id, int x, int y, Layer layer)
{
	Prop* p = new Prop(id);
	if(layer == FIRST_LAYER)
	{
		firstLayer.push_back(p);
	}
	else if(layer == SECOND_LAYER)
		secondLayer.push_back(p);
	p->setTexture();
	p->sprite.setPosition(x, y);
	return p;
}

void PropManager::detruireProp(Prop* prop)
{
	auto it = find(firstLayer.begin(), firstLayer.end(), prop);
	if (it != firstLayer.end()) {
		delete* it;
		firstLayer.erase(it);
	}
	it = find(secondLayer.begin(), secondLayer.end(), prop);
	if (it != secondLayer.end()) {
		delete* it;
		secondLayer.erase(it);
	}
}


void PropManager::readFile()
{
	//First Layer

	ifstream file("assets/map/1stLayer.txt");
	if (file.is_open() == false)
	{
		throw("Erreur critique : le fichier de la carte du jeu est introuvable.");
	}
	string line;
	Vector2f position(0, 0);
	while (true)
	{
		getline(file, line);
		if (line == ";")
		{
			file.close();
			break;
		}
		for (char c : line)
		{
			if (c == '0')
				creerProp(HOUSEFLOOR, position.x, position.y, FIRST_LAYER);
			else if (c == '1')
				creerProp(HOUSEUL, position.x, position.y, FIRST_LAYER);
			else if (c == '2')
				creerProp(HOUSEUR, position.x, position.y, FIRST_LAYER);
			else if (c == '3')
				creerProp(HOUSEDL, position.x, position.y, FIRST_LAYER);
			else if (c == '4')
				creerProp(HOUSEDR, position.x, position.y, FIRST_LAYER);
			else if (c == '5')
				creerProp(GRASS, position.x, position.y, FIRST_LAYER);
			else if (c == '6')
				creerProp(STONE, position.x, position.y, FIRST_LAYER);
			else if (c == '7')
				creerProp(CWALLD, position.x, position.y, FIRST_LAYER);
			else if (c == '8')
				creerProp(CWALLR, position.x, position.y, FIRST_LAYER);
			else if (c == '9')
				creerProp(CWALLH, position.x, position.y, FIRST_LAYER);
			else if (c == 'A')
				creerProp(TOWERUL, position.x, position.y, FIRST_LAYER);
			else if (c == 'B')
				creerProp(TOWERUR, position.x, position.y, FIRST_LAYER);
			else if (c == 'C')
				creerProp(TOWER, position.x, position.y, FIRST_LAYER);
			else if (c == 'D')
				creerProp(TOWERD, position.x, position.y, FIRST_LAYER);
			else if (c == 'E')
				creerProp(CWALLD, position.x, position.y, FIRST_LAYER);
			else if (c == 'F')
				creerProp(CWALLH, position.x, position.y, FIRST_LAYER);
			else if (c == 'G')
				creerProp(HOUSEWALL, position.x, position.y, FIRST_LAYER);
			else if (c == 'H')
				creerProp(HOUSEROOFH, position.x, position.y, FIRST_LAYER);
			else if (c == 'I')
				creerProp(HOUSEROOFL, position.x, position.y, FIRST_LAYER);
			else if (c == 'J')
				creerProp(HOUSEROOFR, position.x, position.y, FIRST_LAYER);
			

			position.x += 96;
		}
		position.x = 0;
		position.y += 96;

	}
	file.open("assets/map/2ndLayer.txt");
	position.x = 0; position.y = 0;
	while (true)
	{
		getline(file, line);
		if (line == ";")
		{
			file.close();
			break;
		}
		for (char c : line)
		{
			if (c == '0')
				creerProp(BED_TOP, position.x, position.y, SECOND_LAYER);
			else if(c == '1')
				creerProp(SINK, position.x, position.y, SECOND_LAYER);
			else if (c == '2')
				creerProp(COUNTER, position.x, position.y, SECOND_LAYER);
			else if (c == '3')
				creerProp(KITCHEN, position.x, position.y, SECOND_LAYER);
			else if (c == '4')
				creerProp(DRESSER, position.x, position.y, SECOND_LAYER);
			else if (c == '5')
				creerProp(CARPET, position.x, position.y, SECOND_LAYER);
			else if (c == '6')
				creerProp(BED_BOTTOM, position.x, position.y, SECOND_LAYER);

			position.x += 96;
		}
		position.x = 0;
		position.y += 96;

	}
}
vector<Prop*> PropManager::getFirstLayer() { return firstLayer; }
vector<Prop*> PropManager::getSecondLayer() { return secondLayer; }
