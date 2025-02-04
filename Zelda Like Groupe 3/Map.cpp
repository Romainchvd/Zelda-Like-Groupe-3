#include "map.h"



void Prop::setTexture()
{
	if(this != nullptr)
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
		case TOWER_BASE:
			if (!texture.loadFromFile("assets/towerBase.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
			break;
		case TOWER_BOTTOM:
			if (!texture.loadFromFile("assets/towerBottom.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
			break;
		case STONE:
			if (!texture.loadFromFile("assets/stone.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
			break;
		case HOUSEFLOOR:
			if (!texture.loadFromFile("assets/woodenplanks.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
			break;
		case GRASS:
			if (!texture.loadFromFile("assets/grass.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
			break;
		case TOWER_TOP:
			if (!texture.loadFromFile("assets/towerTop.png")) cerr << "Erreur lors du chargement de la texture de maison" << endl;
			break;
		case CWALLH:
			if (!texture.loadFromFile("assets/EcastleWallH.png")) cerr << "Erreur lors du chargement de la texture de mur de citadelle horizontal" << endl;
			break;
		case CWALLV:
			if (!texture.loadFromFile("assets/EcastleWallV.png")) cerr << "Erreur lors du chargement de la texture de mur de citadelle vertical" << endl;
			break;
		case HOUSEWALL:
			if (!texture.loadFromFile("assets/housewall.png")) cerr << "Erreur lors du chargement de la texture de mur de la maison" << endl;
			break;
		case HOUSEROOFU:
			if (!texture.loadFromFile("assets/houseRoofU.png")) cerr << "Erreur lors du chargement de la texture de mur horizontal interieur de la maison" << endl;
			break;
		case HOUSEROOFD:
			if (!texture.loadFromFile("assets/houseRoofD.png")) cerr << "Erreur lors du chargement de la texture de mur horizontal interieur de la maison" << endl;
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
		case CARPET_OUTDOOR:
			if (!texture.loadFromFile("assets/carpetE.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case TREE_TOP:
			if (!texture.loadFromFile("assets/treeTop.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case TREE_BOTTOM:
			if (!texture.loadFromFile("assets/treeBottom.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case GUARD_HOUSE_DL:
			if (!texture.loadFromFile("assets/guardHouseDL.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case GUARD_HOUSE_DR:
			if (!texture.loadFromFile("assets/guardHouseDR.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case GUARD_HOUSE_UL:
			if (!texture.loadFromFile("assets/guardHouseUL.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case GUARD_HOUSE_UR:
			if (!texture.loadFromFile("assets/guardHouseUR.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case SPIKES_F:
			if (!texture.loadFromFile("assets/spikesF.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case SPIKES_T:
			if (!texture.loadFromFile("assets/spikesT.png")) cerr << "Erreur lors du chargement de la texture de commode" << endl;
			break;
		case DOOR:
			if (!texture.loadFromFile("assets/door.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case KEY:
			if (!texture.loadFromFile("assets/key.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case FENCES_H:
			if (!texture.loadFromFile("assets/fencesH.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case FENCES_V:
			if (!texture.loadFromFile("assets/fencesV.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLE_DOOR:
			if (!texture.loadFromFile("assets/castleDoor.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLE_WALL:
			if (!texture.loadFromFile("assets/castleWall.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLE_WINDOW:
			if (!texture.loadFromFile("assets/castleWindow.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case FLAG:
			if (!texture.loadFromFile("assets/flag.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		default:
			break;
		}

		sprite.setTexture(texture);
	}
	else
		return;
}

Prop::Prop(Id i) : id(i) {}

void PropManager::creerProp(Id id, int x, int y, Layer layer, bool c, bool i)
{
	unique_ptr<Prop> p = make_unique<Prop>(id);
	p->setTexture();
	p->sprite.setPosition(x, y);
	p->isPossibleColision = c;
	p->InteractionPossible = i;
	if(layer == FIRST_LAYER)
	{
		firstLayer.push_back(move(p));
	}
	else if(layer == SECOND_LAYER)
		secondLayer.push_back(move(p));
	
}

void PropManager::detruireProp(unique_ptr<Prop>& prop)
{
	auto it = std::find_if(firstLayer.begin(), firstLayer.end(),
        [&prop](const std::unique_ptr<Prop>& p) { return p.get() == prop.get(); });

    if (it != firstLayer.end()) {
        firstLayer.erase(it);
    }

    it = std::find_if(secondLayer.begin(), secondLayer.end(),
        [&prop](const std::unique_ptr<Prop>& p) { return p.get() == prop.get(); });

    if (it != secondLayer.end()) {
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
				creerProp(HOUSEFLOOR, position.x, position.y, FIRST_LAYER, false, false);
			else if (c == '1')
				creerProp(HOUSEROOFD, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == '5')
				creerProp(GRASS, position.x, position.y, FIRST_LAYER, false, false);
			else if (c == '6')
				creerProp(STONE, position.x, position.y, FIRST_LAYER, false, false);
			else if (c == '7')
				creerProp(CASTLE_DOOR, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == '8')
				creerProp(CASTLE_WALL, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == '9')
				creerProp(CASTLE_WINDOW, position.x, position.y, FIRST_LAYER, true, false);
			//Attention espace vide disponible
			else if (c == 'G')
				creerProp(HOUSEWALL, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'H')
				creerProp(HOUSEROOFU, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'I')
				creerProp(HOUSEROOFL, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'J')
				creerProp(HOUSEROOFR, position.x, position.y, FIRST_LAYER, true, false);
			

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
				creerProp(BED_TOP, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '1')
				creerProp(SINK, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '2')
				creerProp(COUNTER, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '3')
				creerProp(KITCHEN, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '4')
				creerProp(DRESSER, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '5')
				creerProp(CARPET, position.x, position.y, SECOND_LAYER, false, true);
			else if (c == '6')
				creerProp(BED_BOTTOM, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '7')
				creerProp(TOWER_BOTTOM, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '8')
				creerProp(TOWER_BASE, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == '9')
				creerProp(TOWER_TOP, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'A')
				creerProp(CWALLH, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'B')
				creerProp(CWALLV, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'C')
				creerProp(HOUSEUL, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'D')
				creerProp(HOUSEUR, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'E')
				creerProp(HOUSEDL, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'F')
				creerProp(HOUSEDR, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'G')
				creerProp(TREE_BOTTOM, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'H')
				creerProp(TREE_TOP, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'I')
				creerProp(GUARD_HOUSE_UL, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'J')
				creerProp(GUARD_HOUSE_UR, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'K')
				creerProp(GUARD_HOUSE_DL, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'L')
				creerProp(GUARD_HOUSE_DR, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'M')
				creerProp(SPIKES_T, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'N')
				creerProp(SPIKES_F, position.x, position.y, SECOND_LAYER, false, false);
			else if (c == 'O')
				creerProp(DOOR, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'P')
				creerProp(KEY, position.x, position.y, SECOND_LAYER, false, false);
			else if (c == 'Q')
				creerProp(FENCES_H, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'R')
				creerProp(FENCES_V, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'S')
				creerProp(CARPET_OUTDOOR, position.x, position.y, SECOND_LAYER, false, true);
			else if (c == 'T')
				creerProp(FLAG, position.x, position.y, SECOND_LAYER, false, false);

			position.x += 96;
		}
		position.x = 0;
		position.y += 96;

	}
}
vector<unique_ptr<Prop>>& PropManager::getFirstLayer() { return firstLayer; }
vector<unique_ptr<Prop>>& PropManager::getSecondLayer() { return secondLayer; }

Spikes::Spikes()
{
	if (!spikesActivated.loadFromFile("assets/spikesT.png")) cerr << "Erreur lors du chargement de la texture de pics on" << endl;
	if (!spikesDisabled.loadFromFile("assets/spikesF.png")) cerr << "Erreur lors du chargement de la texture de pics off" << endl;
	if (!interruptorActivated.loadFromFile("assets/interruptorT.png")) cerr << "Erreur lors du chargement de la texture d'interrupteur on" << endl;
	if (!interruptorDisabled.loadFromFile("assets/interruptorF.png")) cerr << "Erreur lors du chargement de la texture d'interrupteur off" << endl;
	if (interruptorIsActivated)
	{
		sprite.setTexture(spikesDisabled);
		interruptor.setTexture(interruptorActivated);
	}
	else
	{
		sprite.setTexture(spikesActivated);
		interruptor.setTexture(interruptorDisabled);
	}
}
void Spikes::checkInterruptor(Player& player)
{
	if (interruptorCanChangeState)
	{
		if (player.sprite.getGlobalBounds().intersects(interruptor.getGlobalBounds()))
		{
			if (interruptorIsActivated)
			{
				interruptor.setTexture(interruptorDisabled);
				sprite.setTexture(spikesActivated);
				interruptorCanChangeState = false;
			}
			else if (!interruptorIsActivated)
			{
				interruptor.setTexture(interruptorActivated);
				sprite.setTexture(spikesDisabled);
				interruptorCanChangeState = false;
			}
		}
	}
}
void Prop::addKey(Player& player, PropManager& manager)
{
	if (player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && id == KEY)
	{
		player.keyCounter++;

		auto it = std::find_if(manager.getSecondLayer().begin(), manager.getSecondLayer().end(),
			[this](const unique_ptr<Prop>& p) { return p.get() == this; });

		if (it != manager.getSecondLayer().end())
			manager.getSecondLayer().erase(it);
	}
}

void Prop::useKey(Player& player, PropManager& manager)
{
	if (player.keyCounter > 0 && player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && id == DOOR)
	{
		player.keyCounter--;
		
		auto it = std::find_if(manager.getSecondLayer().begin(), manager.getSecondLayer().end(),
			[this](const unique_ptr<Prop>& p) { return p.get() == this; });

		if (it != manager.getSecondLayer().end())
			manager.getSecondLayer().erase(it);
	}
}