#pragma once
#include <vector>
#include <algorithm>
#include "ResourceType.h"
#include <cstdlib>


// Harvest deck tile
struct Tile
{
	Tile(ResourceType _one, ResourceType _two, ResourceType _three, ResourceType _four)
	{
		resources = {_one, _two,_three,_four};
		
		one = _one;
		two = _two;
		three = _three;
		four = _four;
	}

	void rotateLeft() {
		std::rotate(resources.begin(), resources.begin() + 1, resources.end());
	}

	void rotateRight() {
		std::rotate(resources.rbegin(), resources.rbegin() + 1, resources.rend());
	}

	std::vector<ResourceType> resources;
	
	ResourceType one;
	ResourceType two;
	ResourceType three;
	ResourceType four;
};

class HarvestDeck
{
public:
	HarvestDeck();
	~HarvestDeck();
	void buildDeckOfHarvest();
	void shuffle();
	void printFirst();

	std::vector<Tile>* deckOfHarvestTile;
private:
};
