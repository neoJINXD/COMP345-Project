#include "TurnSequence.h"
#include "../GBMaps/GBMap.h"
#include "../Resources/Resources.h"

void maingame::TurnSequence::playTurn(player::Player* player)
{

	//Plays the harvest tile
	player->PlaceHarvestTile();
	//handle playing shipment tile

	//Calculate the resources from previous play
	player->CalculateResources();
	player->displayResources();

	//Build on the village board
	//keep track of recently placed node? (within player)

	//Let other players build with same logic



}

void maingame::TurnSequenceDriver::run()
{
	GB::GBMap* map = new GB::GBMap(2);
	map->buildBoard();
	deck::BuildingDeck* bDeck = new deck::BuildingDeck();
	deck::HarvestDeck* hDeck = new deck::HarvestDeck();

	player::Player* testPlayer = new player::Player(new std::string("jojo"), map, hDeck, bDeck);

	testPlayer->DrawBuilding();
	testPlayer->DrawBuilding();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawHarvestTile();
	testPlayer->DrawShipment();

	maingame::TurnSequence turnary;
	turnary.playTurn(testPlayer);

	delete map;
	map = nullptr;

	delete hDeck;
	hDeck = nullptr;

	delete bDeck;
	bDeck = nullptr;

	delete testPlayer;
	testPlayer = nullptr;


}
