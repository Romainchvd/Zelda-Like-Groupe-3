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
		if (!texture.loadFromFile("assets/towerU.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
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

	default:
		break;
	}

	sprite.setTexture(texture);
}

Prop::Prop(Id i) : id(i) {}

PropManager::~PropManager()
{
	for (auto prop : map)
	{
		delete prop;
	}
	map.clear();
}
Prop* PropManager::creerProp(Id id, int x, int y)
{
	Prop* p = new Prop(id);
	map.push_back(p);
	p->setTexture();
	p->sprite.setPosition(x, y);
	return p;
}

void PropManager::detruireProp(Prop* prop)
{
	auto it = find(map.begin(), map.end(), prop);
	if (it != map.end()) {
		delete* it;
		map.erase(it);
	}
}


void PropManager::readFile()
{
	ifstream file("assets/map.txt");
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
			break;
		for (char c : line)
		{
			if (c == '0')
				creerProp(HOUSEFLOOR, position.x, position.y);
			else if (c == '1')
				creerProp(HOUSEUL, position.x, position.y);
			else if (c == '2')
				creerProp(HOUSEUR, position.x, position.y);
			else if (c == '3')
				creerProp(HOUSEDL, position.x, position.y);
			else if (c == '4')
				creerProp(HOUSEDR, position.x, position.y);
			else if (c == '5')
				creerProp(GRASS, position.x, position.y);
			else if (c == '6')
				creerProp(STONE, position.x, position.y);
			else if (c == '7')
				creerProp(CWALLD, position.x, position.y);
			else if (c == '8')
				creerProp(CWALLR, position.x, position.y);
			else if (c == '9')
				creerProp(CWALLH, position.x, position.y);
			else if (c == 'A')
				creerProp(TOWERUL, position.x, position.y);
			else if (c == 'B')
				creerProp(TOWERUR, position.x, position.y);
			else if (c == 'C')
				creerProp(TOWER, position.x, position.y);
			else if (c == 'D')
				creerProp(TOWERD, position.x, position.y);
			else if (c == 'E')
				creerProp(CWALLD, position.x, position.y);
			else if (c == 'F')
				creerProp(CWALLH, position.x, position.y);
			

			position.x += 96;
		}
		position.x = 0;
		position.y += 96;

	}

}
vector<Prop*> PropManager::getMap() { return map; }
