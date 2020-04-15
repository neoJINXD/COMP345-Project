#include "TurnSequence.h"
#include "../GBMaps/GBMap.h"
#include "../Resources/Resources.h"
#include "../ResourceCounter/ResourceCounter.h"


void maingame::TurnSequence::playTurn(player::Player* player, player::Player** others)
{

	//Plays the harvest tile
	std::cout << "Building A Tile" << std::endl;
	std::pair<bool, int> shipmentPlaced = player->PlaceHarvestTile();
	std::cout << std::endl;
	//handle playing shipment tile

	//Calculate the resources from previous play
	std::cout << "Calculating resources" << std::endl;
	player->CalculateResources();
	player->displayResources();
	std::cout << std::endl;

	//placiung multiple tiles for testing purposes
	//player->PlaceHarvestTile();
	//player->CalculateResources();



	//Build on the village board
	std::cout << "Build a village together" << std::endl;
	player->BuildVillage();
	std::cout << std::endl;
	//keep track of recently placed node? (within player)

	int i = 0;
	std::cout << "Do you wish to have a trade deal mate? (1 == yes, 0 == no):\n";
	std::cin >> i;

	if (i == 0) {
		i = 1337;
	}
	//use resourceTracker to decrease based on cost, for player
	//buildvillage returns cost of building placed
	//if facedown, take cost of location
	//else cost of building being placed

	if (player->getEmptyResources())
		i = 404;
	//Let other players build with same logic
	for (; i < 3; i++)
	{
		std::cout << "Next Player" << std::endl;
		player::Player* nowBuilding = *(others+i);
		player->passResources(nowBuilding);
		std::cout << "Build a village together" << std::endl;
		nowBuilding->BuildVillage();
		std::cout << std::endl;

		//use resourceTracker to decrease based on cost, for nowBuilding
		//buildvillage returns cost of building placed
		//if facedown, take cost of location
		//else cost of building being placed

		if (nowBuilding->getEmptyResources())
			break;

		nowBuilding->passResources(player);
	}

	//if shipment was placed
	if (shipmentPlaced.first)
	{
		//gb needs to delete recentNode
		delete player->getTileAt(shipmentPlaced.second);
		//hands places shipment pointer at same location
		player->insertShipment(shipmentPlaced.second);
	}


}

void maingame::TurnSequenceDriver::run()
{
	GB::GBMap* map = new GB::GBMap(2);
	map->buildBoard();
	deck::BuildingDeck* bDeck = new deck::BuildingDeck();
	deck::HarvestDeck* hDeck = new deck::HarvestDeck();

	player::Player* testPlayer = new player::Player(new std::string("Joseph"), map, hDeck, bDeck);
	player::Player* testPlayer2 = new player::Player(new std::string("Jotaro"), map, hDeck, bDeck);
	player::Player* testPlayer3 = new player::Player(new std::string("Jolyne"), map, hDeck, bDeck);
	player::Player* testPlayer4 = new player::Player(new std::string("Johnny"), map, hDeck, bDeck);

	counter::ResourceCounter* count = new counter::ResourceCounter();
	testPlayer->setCounterSystem(count);
	testPlayer2->setCounterSystem(count);
	testPlayer3->setCounterSystem(count);
	testPlayer4->setCounterSystem(count);

	player::Player* restPlayers[3] = {testPlayer2, testPlayer3, testPlayer4};

	testPlayer->DrawBuilding();
	testPlayer->DrawBuilding();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();

	
	testPlayer->DrawShipment();

	testPlayer2->DrawBuilding();
	testPlayer3->DrawBuilding();
	testPlayer4->DrawBuilding();


	maingame::TurnSequence turnary;
	turnary.playTurn(testPlayer, restPlayers);

	delete map;
	map = nullptr;

	delete hDeck;
	hDeck = nullptr;

	delete bDeck;
	bDeck = nullptr;

	delete testPlayer;
	testPlayer = nullptr;

	delete testPlayer2;
	testPlayer2 = nullptr;

	delete testPlayer3;
	testPlayer3 = nullptr;

	delete testPlayer4;
	testPlayer4 = nullptr;

	delete count;
	count = nullptr;

}
