#include "HarvestDeck.h"
#include<iostream>

HarvestDeck::HarvestDeck()
{

}

HarvestDeck::~HarvestDeck()
{


}

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
	deckOfHarvestTile.push_back(Tile(Stone, Stone, Timber, Stone)); //


}
