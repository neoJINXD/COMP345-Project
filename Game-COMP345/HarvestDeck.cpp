#include "HarvestDeck.h"
#include<iostream>

HarvestDeck::HarvestDeck()
{

	// creates a shuffled deck of harvest
	HarvestDeck::buildDeckOfHarvest();
	
}

HarvestDeck::~HarvestDeck()
{


}


// Input data for the Harvest deck
void HarvestDeck::buildDeckOfHarvest()
{
	// create a array of Harvest Tile
	std::vector<Tile> deckOfHarvestTile;
	//push each elements in the array
	deckOfHarvestTile.push_back(Tile(Wheat, Stone, Stone, Wheat));  // Tile 1
	deckOfHarvestTile.push_back(Tile(Timber, Timber, Stone, Timber)); // Tile 2
	deckOfHarvestTile.push_back(Tile(Sheep, Sheep, Stone, Sheep)); // Tile 3
	deckOfHarvestTile.push_back(Tile(Wheat, Timber, Stone, Wheat)); // Tile 4
	deckOfHarvestTile.push_back(Tile(Timber, Wheat, Wheat, Timber)); //Tile 5
	deckOfHarvestTile.push_back(Tile(Sheep, Sheep, Wheat, Sheep)); //Tile 6
	deckOfHarvestTile.push_back(Tile(Timber, Stone, Stone, Timber)); // Tile 7
	deckOfHarvestTile.push_back(Tile(Stone, Wheat, Sheep, Stone)); // Tile 8
	deckOfHarvestTile.push_back(Tile(Wheat, Stone, Sheep, Wheat)); // Tile 9
	deckOfHarvestTile.push_back(Tile(Sheep, Stone, Wheat, Sheep)); // Tile 10
	deckOfHarvestTile.push_back(Tile(Timber, Sheep, Stone, Timber)); // Tile 11
	deckOfHarvestTile.push_back(Tile(Wheat, Sheep, Timber, Wheat)); // Tile 12
	deckOfHarvestTile.push_back(Tile(Timber, Stone, Timber, Sheep)); // Tile 13
	deckOfHarvestTile.push_back(Tile(Stone, Stone, Sheep, Stone)); // Tile 14
	deckOfHarvestTile.push_back(Tile(Sheep, Stone, Stone, Sheep)); // Tile 15
	deckOfHarvestTile.push_back(Tile(Sheep, Wheat, Stone, Sheep)); // Tile 16
	deckOfHarvestTile.push_back(Tile(Timber, Wheat, Wheat, Timber)); // Tile 17
	deckOfHarvestTile.push_back(Tile(Timber, Stone, Wheat, Timber)); // Tile 18
	deckOfHarvestTile.push_back(Tile(Sheep, Wheat, Wheat, Sheep)); // Tile 19
	deckOfHarvestTile.push_back(Tile(Sheep, Sheep, Timber, Sheep)); // Tile 20
	deckOfHarvestTile.push_back(Tile(Timber, Wheat, Stone, Timber)); // Tile 21
	deckOfHarvestTile.push_back(Tile(Stone, Sheep, Wheat, Stone)); // Tile 22
	deckOfHarvestTile.push_back(Tile(Stone, Stone, Wheat, Stone)); // Tile 23
	deckOfHarvestTile.push_back(Tile(Sheep, Stone, Sheep, Timber)); // Tile 24
	deckOfHarvestTile.push_back(Tile(Sheep, Wheat, Sheep, Timber)); //Tile 25
	deckOfHarvestTile.push_back(Tile(Stone, Wheat, Timber, Stone)); //Tile 26
	deckOfHarvestTile.push_back(Tile(Wheat, Sheep, Wheat, Timber)); // Tile 27
	deckOfHarvestTile.push_back(Tile(Stone, Stone, Timber, Stone)); // Tile 28
	deckOfHarvestTile.push_back(Tile(Timber, Sheep, Sheep, Timber)); // Tile 29
	deckOfHarvestTile.push_back(Tile(Wheat, Stone, Wheat, Timber)); // Tile 30
	deckOfHarvestTile.push_back(Tile(Sheep, Stone, Wheat, Sheep)); // Tile 31
	deckOfHarvestTile.push_back(Tile(Wheat, Timber, Sheep, Wheat)); // Tile 32
	deckOfHarvestTile.push_back(Tile(Stone, Sheep, Timber, Stone)); //Tile 33
	deckOfHarvestTile.push_back(Tile(Timber, Wheat, Sheep, Timber)); // Tile 34
	deckOfHarvestTile.push_back(Tile(Timber, Stone, Timber, Wheat)); //Tile 35
	deckOfHarvestTile.push_back(Tile(Wheat, Wheat, Timber, Wheat)); //Tile 36
	deckOfHarvestTile.push_back(Tile(Sheep, Timber, Wheat, Sheep)); // Tile 37
	deckOfHarvestTile.push_back(Tile(Timber, Sheep, Sheep, Timber)); // Tile 38
	deckOfHarvestTile.push_back(Tile(Wheat, Wheat, Sheep, Wheat)); // Tile 39
	deckOfHarvestTile.push_back(Tile(Wheat, Wheat, Stone, Wheat)); // Tile 40
	deckOfHarvestTile.push_back(Tile(Timber, Sheep, Wheat, Timber)); // Tile 41
	deckOfHarvestTile.push_back(Tile(Stone, Timber, Wheat, Stone)); // Tile 42
	deckOfHarvestTile.push_back(Tile(Sheep, Stone, Timber, Sheep)); // Tile 43
	deckOfHarvestTile.push_back(Tile(Stone, Wheat, Stone, Timber)); // Tile 44
	deckOfHarvestTile.push_back(Tile(Timber, Stone, Sheep, Timber)); // Tile 45
	deckOfHarvestTile.push_back(Tile(Sheep, Stone, Stone, Sheep)); //Tile 46
	deckOfHarvestTile.push_back(Tile(Stone, Timber, Sheep, Stone)); // Tile 47
	deckOfHarvestTile.push_back(Tile(Timber, Timber, Wheat, Timber)); //Tile 48
	deckOfHarvestTile.push_back(Tile(Sheep, Wheat, Wheat, Sheep)); // Tile 49
	deckOfHarvestTile.push_back(Tile(Wheat, Sheep, Stone, Wheat)); // Tile 50
	deckOfHarvestTile.push_back(Tile(Timber, Wheat, Timber, Sheep)); // Tile 51
	deckOfHarvestTile.push_back(Tile(Wheat, Stone, Stone, Wheat)); // Tile 52
	deckOfHarvestTile.push_back(Tile(Wheat, Stone, Timber, Wheat)); // Tile 53
	deckOfHarvestTile.push_back(Tile(Stone, Sheep, Stone, Timber)); //Tile 54
	deckOfHarvestTile.push_back(Tile(Stone, Wheat, Stone, Sheep)); // Tile 55
	deckOfHarvestTile.push_back(Tile(Sheep, Wheat, Timber, Sheep)); // Tile 56
	deckOfHarvestTile.push_back(Tile(Timber, Timber, Sheep, Timber)); //Tile 57
	deckOfHarvestTile.push_back(Tile(Sheep, Timber, Stone, Sheep)); // Tile 58
	deckOfHarvestTile.push_back(Tile(Wheat, Stone, Wheat, Sheep)); // Tile 59
	deckOfHarvestTile.push_back(Tile(Timber, Stone, Stone, Timber)); // TIle 60

	// Shuffle the deck
	HarvestDeck::shuffle(deckOfHarvestTile);
}

// Shuffle the deck

void HarvestDeck::shuffle(std::vector<Tile> harvestDeck)
{	
	// using built-in random generator to shuffle the harvestDeck
	std::random_shuffle(harvestDeck.begin(), harvestDeck.end());
	std::random_shuffle(harvestDeck.begin(), harvestDeck.end(), harvestDeck);
}