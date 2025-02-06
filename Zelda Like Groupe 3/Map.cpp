#include "map.h"
#include "Game.h"


void Prop::setTexture()
{
	if (this != nullptr)
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
		case CASTLE_DOOR_E:
			if (!texture.loadFromFile("assets/castleDoorE.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLE_WALL_E:
			if (!texture.loadFromFile("assets/castleWallE.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLE_WINDOW_E:
			if (!texture.loadFromFile("assets/castleWindowE.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case FLAG:
			if (!texture.loadFromFile("assets/flag.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEFLOOR:
			if (!texture.loadFromFile("assets/castleFloor.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_RIGHT:
			if (!texture.loadFromFile("assets/castleWallR.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_UP:
			if (!texture.loadFromFile("assets/castleWallU.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_DOWN:
			if (!texture.loadFromFile("assets/castleWallD.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_LEFT:
			if (!texture.loadFromFile("assets/castleWallL.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_DOWNLEFT:
			if (!texture.loadFromFile("assets/castleWallDL.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_DOWNRIGHT:
			if (!texture.loadFromFile("assets/castleWallDR.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_DOWNLEFTE:
			if (!texture.loadFromFile("assets/castleWallDLE.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_DOWNRIGHTE:
			if (!texture.loadFromFile("assets/castleWallDRE.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_UPRIGHT:
			if (!texture.loadFromFile("assets/castleWallUR.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLEWALL_UPLEFT:
			if (!texture.loadFromFile("assets/castleWallUL.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case GATE:
			if (!texture.loadFromFile("assets/gateClosed.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CWALLD:
			if (!texture.loadFromFile("assets/EcastleWallHD.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLE_SQUARE_UR:
			if (!texture.loadFromFile("assets/castleWallSquareUR.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CASTLE_SQUARE_UL:
			if (!texture.loadFromFile("assets/castleWallSquareUL.png")) cerr << "Erreur lors du chargement de la texture de porte" << endl;
			break;
		case CHEST:
			if (!texture.loadFromFile("assets/chestClosed.png")) cerr << "Erreur lors du chargement de la texture de coffre" << endl;
			break;
		case SWORD:
			if (!texture.loadFromFile("assets/sword.png")) cerr << "Erreur lors du chargement de la texture de l'epee" << endl;
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
	if (layer == FIRST_LAYER)
	{
		firstLayer.push_back(move(p));
	}
	else if (layer == SECOND_LAYER)
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


void PropManager::readFile(Game& game)
{
	//First Layer
	ifstream file;
	if(game.state == PLAYING)
	{
		file.open("assets/map/1stLayer.txt");
	}
	else if (game.state == EDITOR)
	{
		file.open("assets/map/1stLayerEdit.txt");

	}
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
				creerProp(CASTLE_DOOR_E, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == '8')
				creerProp(CASTLE_WALL_E, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == '9')
				creerProp(CASTLE_WINDOW_E, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'A')
				creerProp(CASTLEWALL_DOWNLEFT, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'B')
				creerProp(CASTLEWALL_DOWNRIGHT, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'C')
				creerProp(CASTLEWALL_UPLEFT, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'D')
				creerProp(CASTLEWALL_UPRIGHT, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'E')
				creerProp(CASTLE_SQUARE_UR, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'F')
				creerProp(CASTLE_SQUARE_UL, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'G')
				creerProp(HOUSEWALL, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'H')
				creerProp(HOUSEROOFU, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'I')
				creerProp(HOUSEROOFL, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'J')
				creerProp(HOUSEROOFR, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'W')
				creerProp(CASTLEWALL_RIGHT, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'X')
				creerProp(CASTLEWALL_LEFT, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'Y')
				creerProp(CASTLEFLOOR, position.x, position.y, FIRST_LAYER, false, false);
			else if (c == 'Z')
				creerProp(CASTLEWALL_UP, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'a')
				creerProp(CASTLEWALL_DOWN, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'b')
				creerProp(CASTLEWALL_DOWNLEFTE, position.x, position.y, FIRST_LAYER, true, false);
			else if (c == 'c')
				creerProp(CASTLEWALL_DOWNRIGHTE, position.x, position.y, FIRST_LAYER, true, false);


			position.x += 96;
		}
		position.x = 0;
		position.y += 96;

	}
	if(game.state == PLAYING)
	{
		file.open("assets/map/2ndLayer.txt");
	}
	else if (game.state == EDITOR)
	{
		file.open("assets/map/2ndLayerEdit.txt");
	}
	if (file.is_open() == false)
	{
		throw("Erreur critique : le fichier de la carte du l'editeur est introuvable.");
	}
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
			else if (c == 'U')
				creerProp(GATE, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'V')
				creerProp(CWALLD, position.x, position.y, SECOND_LAYER, true, false);
			else if (c == 'W')
				creerProp(CHEST, position.x, position.y, SECOND_LAYER, true, true);
			else if (c == 'X')
				creerProp(SWORD, position.x, position.y, SECOND_LAYER, false, false);
			


			position.x += 96;
		}
		position.x = 0;
		position.y += 96;

	}
}
vector<unique_ptr<Prop>>& PropManager::getFirstLayer() { return firstLayer; }
vector<unique_ptr<Prop>>& PropManager::getSecondLayer() { return secondLayer; }

void Prop::collectProp(Player& player, PropManager& manager)
{
	if (id == KEY)
	{
		if (player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		{
			player.keyCounter++;
			player.collect.play();

			auto it = std::find_if(manager.getSecondLayer().begin(), manager.getSecondLayer().end(),
				[this](const unique_ptr<Prop>& p) { return p.get() == this; });

			if (it != manager.getSecondLayer().end())
				manager.getSecondLayer().erase(it);
		}
	}
	else if (id == SWORD)
	{
		if(player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		{
			player.hasSword = true;
			player.collect.play();
			auto it = std::find_if(manager.getSecondLayer().begin(), manager.getSecondLayer().end(),
				[this](const unique_ptr<Prop>& p) { return p.get() == this; });

			if (it != manager.getSecondLayer().end())
				manager.getSecondLayer().erase(it);
		}
	}
}

void Prop::useKey(Player& player, PropManager& manager)
{
	if (player.keyCounter > 0 && player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && id == DOOR)
	{
		player.keyCounter--;
		player.solved.play();
		auto it = std::find_if(manager.getSecondLayer().begin(), manager.getSecondLayer().end(),
			[this](const unique_ptr<Prop>& p) { return p.get() == this; });

		if (it != manager.getSecondLayer().end())
			manager.getSecondLayer().erase(it);
	}
	else if (player.keyCounter > 0 && player.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && id == GATE)
	{
		player.keyCounter--;
		player.solved.play();
		if (!this->texture.loadFromFile("Assets/gateOpened.png")) cerr << "Erreur lors du chargement de texture de porte ouverte";
		this->sprite.setTexture(this->texture);
		this->isPossibleColision = false;
	}
}