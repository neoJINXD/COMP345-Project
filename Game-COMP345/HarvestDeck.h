#pragma once
#include <vector>
#include <algorithm>
#include "Resource.h"
#include <cstdlib>


namespace deck {
// Harvest deck tile
	struct Tile
	{

		Tile(Resource _one, Resource _two, Resource _three, Resource _four)
		{
			*resources = {_one, _two,_three,_four};
		}

		void rotateLeft();
		void rotateRight();

		std::vector<Resource>* resources = new std::vector<Resource>();

		void printInfo();
	};


	class HarvestDeck
	{
	private:
		std::vector<Tile>* deck;
		void buildDeck();
		void shuffle();

	public:
		HarvestDeck() : deck(new std::vector<Tile>()) { buildDeck(); }
		~HarvestDeck();

		Tile draw();

		void printDeck();

	};

	class HarvestDriver 
	{
	public:
		void run();
	};

}


