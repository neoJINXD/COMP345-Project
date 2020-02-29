#include "Player.h"


void player::Player::init()
{
	hands = new deck::Hand(Hdeck, Bdeck);
	//TODO await josh
	std::cout << "Creating Village" << std::endl;

}


player::Player::~Player()
{
	delete board;
	board = nullptr;

	//delete village
	delete village;
	village = nullptr;

	//delete hands
	delete hands;
	hands = nullptr;

}

void player::Player::createHand(deck::HarvestDeck* HDeck, deck::BuildingDeck* BDeck)
{
	std::cout << "Creating Hand" << std::endl;

	hands = new deck::Hand(HDeck, BDeck);
}

void player::Player::printHand() 
{
	hands->displayBuildings();
	hands->displayTiles();
}

void player::Player::DrawBuilding() 
{
	hands->drawBuilding();
}

void player::Player::DrawHarvestTile() 
{
	hands->drawTile();
}

void player::Player::PlaceHarvestTile()
{

	//board->peekTile(2)->printInfo();
	std::pair<int, deck::Tile> placement = hands->exchange();
	board->placeTile(placement.first, &placement.second);
	std::cout << "Placing at " << placement.first << std::endl;
	board->peekTile(placement.first)->printInfo();

}

void player::PlayerDriver::run()
{
	GB::GBMap* map = new GB::GBMap(2);
	map->buildABear();

	deck::HarvestDeck* Hdeck = new deck::HarvestDeck();
	deck::BuildingDeck* Bdeck = new deck::BuildingDeck();

	std::string name = "Josuke";
	Player jojo(&name, map, Hdeck, Bdeck);

	jojo.DrawBuilding();
	jojo.DrawBuilding();

	jojo.DrawHarvestTile();
	jojo.DrawHarvestTile();
	jojo.DrawHarvestTile();

	jojo.PlaceHarvestTile();
	
}