#include "Player.h"



void player::Player::initVB()
{
	//TODO await josh
	std::cout << "Creating Village" << std::endl;
}


player::Player::~Player()
{
	//delete name
	//delete village
	//delete hands
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