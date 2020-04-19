#include "GameStart.h"
#include "../GBMaps/GBMap.h"
#include "../Resources/Resources.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"
#include <vector>
#include <iostream>
#include <string>
#include "../ResourceCounter/ResourceCounter.h"

GB::GBMap* maingame::GameStart::initGameBoard(unsigned players)
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

deck::HarvestDeck* maingame::GameStart::initHarvestDeck()
{
	return new deck::HarvestDeck();
}

deck::BuildingDeck* maingame::GameStart::initBuildingDeck()
{
	return new deck::BuildingDeck();
}

void maingame::GameStart::drawStart(player::Player* player)
{
	for (int cnt = 0; cnt < 6; cnt++) {
		player->DrawBuilding();
	}
	for (int cnt = 0; cnt < 2; cnt++) {
		player->DrawHarvestTile();
	}

	player->DrawShipment();
}




std::vector<player::Player*>* maingame::GameStart::initPlayers(unsigned totalPlayers)
{
	if (totalPlayers < 2 || totalPlayers > 4) { 
		std::cout << "Invlid number of players!" << std::endl;
		exit(-1337);
	}
	std::vector<player::Player*>* players = new std::vector<player::Player*>();
	//players->reserve(totalPlayers);
	gameboard = initGameBoard(totalPlayers);
	buildingDeck = initBuildingDeck();
	harvestDeck = initHarvestDeck();
	counter::ResourceCounter* count = new counter::ResourceCounter();

	for (auto i = 0; i < totalPlayers; i++) {
		std::string* name = new std::string("P" + std::to_string(i + 1));
		player::Player* player = new player::Player(name, gameboard, harvestDeck, buildingDeck);

		drawStart(player);
		player->setCounterSystem(count);
		players->push_back(player);
	}



	return players;
}

void maingame::GameStartDriver::run()
{
	GameStart* gs = new GameStart();

	auto players = gs->initPlayers(4);

	for (auto p : *players) {
		
		std::cout << *p->getName() << std::endl;
		p->printHand();
		std::cout << std::endl;
	}

	delete gs;
	gs = nullptr;

	for (auto p : *players) {
		delete p;
		p = nullptr;
	}

	delete players;
	players = nullptr;
}
