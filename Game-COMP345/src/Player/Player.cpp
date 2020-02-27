#include "Player.h"



void player::Player::initVB()
{
	//TODO await josh
}


player::Player::~Player()
{
	//delete name
	//delete village
	//delete hands
}

void player::Player::createHand(deck::HarvestDeck* HDeck, deck::BuildingDeck* BDeck)
{
	hands = new deck::Hand(HDeck, BDeck);
}
