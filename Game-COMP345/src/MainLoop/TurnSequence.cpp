#include "TurnSequence.h"
#include "../GBMaps/GBMap.h"
#include "../Resources/Resources.h"


void maingame::TurnSequence::playTurn(player::Player* player, player::Player** others)
{

	//Plays the harvest tile
	std::cout << "Building A Tile" << std::endl;
	player->PlaceHarvestTile();
	std::cout << std::endl;
	//handle playing shipment tile------------------------------------

	//Calculate the resources from previous play
	std::cout << "Calculating resources" << std::endl;
	player->CalculateResources();
	player->displayResources();
	std::cout << std::endl;

	player->PlaceHarvestTile();
	player->CalculateResources();
	player->PlaceHarvestTile();
	player->CalculateResources();

	//Build on the village board
	std::cout << "Build a bear together" << std::endl;
	player->BuildVillage();
	std::cout << std::endl;
	//keep track of recently placed node? (within player)


	int i = 0;
	if (player->getEmptyResources())
		i = 404;
	//Let other players build with same logic
	for (; i < 3; i++)
	{
		std::cout << "Next Player" << std::endl;
		player::Player* nowBuilding = *(others+i);
		player->passResources(nowBuilding);
		std::cout << "Build a bear together" << std::endl;
		nowBuilding->BuildVillage();
		std::cout << std::endl;
		if (nowBuilding->getEmptyResources())
			break;
	}

	//if shipment
	//gb needs to delete recentNode
	//hands places shipment pointer at same location


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

	player::Player* restPlayers[3] = {testPlayer2, testPlayer3, testPlayer4};

	testPlayer->DrawBuilding();
	testPlayer->DrawBuilding();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();

	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
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

}
