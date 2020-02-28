#include "Player.h"



void player::Player::initVB()
{
	//TODO await josh
	std::cout << "Creating Village" << std::endl;

}


player::Player::~Player()
{
	delete board;
	board = nullptr;

	//delete name
	delete name;
	name = nullptr;

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
	//take from hand, call its exchange with 
}