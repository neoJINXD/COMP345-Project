#include "GameStart.h"
#include "../GBMaps/GBMap.h"
#include "../Resources/Resources.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"
#include <vector>
#include <iostream>
#include <string>

GB::GBMap* gi::GameStart::initGameBoard(unsigned players)
{
	maploader::MapLoader loader;
	std::string path;
	switch (players) {
	case 2:
		path = "src/Files/maps/2player.txt";
		break;
	case 3:
		path = "src/Files/maps/3player.txt";
		break;
	case 4:
		path = "src/Files/maps/4player.txt";
		break;
	default:
		path = "";
		break;
	}

	return loader.loadMap(path, players);

}

deck::HarvestDeck* gi::GameStart::initHarvestDeck() 
{
	return new deck::HarvestDeck();
}

deck::BuildingDeck* gi::GameStart::initBuildingDeck()
{
	return new deck::BuildingDeck();
}


std::vector<player::Player*>* gi::GameStart::initPlayers(unsigned totalPlayers)
{
	std::vector<player::Player*>* players = new std::vector<player::Player*>();
	//players->reserve(totalPlayers);
	gameboard = initGameBoard(totalPlayers);
	buildingDeck = initBuildingDeck();
	harvestDeck = initHarvestDeck();

	if (totalPlayers < 2 || totalPlayers > 4) { 
		std::cout << "Invlid number of players dessuuu~~~" << std::endl;
		exit(-1337);
	}

	for (auto i = 0; i < totalPlayers; i++) {
		std::string* name = new std::string("P" + 1);
		player::Player* player = new player::Player(name, gameboard, harvestDeck, buildingDeck);
		player->DrawBuilding();
		player->DrawHarvestTile();
		players->push_back(player);
	}

	//switch (totalPlayers) {
	//case 2:
	//	//players.push_back(new player::Player());
	//	break;
	//case 3:
	//	break;

	//case 4:
	//	break;

	//default:
	//	std::cout << "Invalid number of players" << std::endl;
	//	break;
	//}

	return players;
}

void gi::MakarovsWeddingDress::run()
{
	GameStart* gs = new GameStart();

	auto players = gs->initPlayers(4);

	for (auto p : *players) {
		
		std::cout << p->name << std::endl;
		p->printHand();
	}

	delete gs;


	for (auto p : *players) {
		delete p;
		p = nullptr;
	}

	delete players;
	players = nullptr;
}
