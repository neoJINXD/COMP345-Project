#pragma once
#include <vector>
#include <algorithm>
#include "Resource.h"
#include <cstdlib>


namespace deck {
// Harvest deck tile
	struct Tile
	{
<<<<<<< HEAD
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

=======
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
	HarvestDeck()= default;
	~HarvestDeck();
	void buildDeckOfHarvest();
	void shuffle();
	void printFirst();

	
private:
	std::vector<Tile>* deckOfHarvestTile = new std::vector<Tile>();
};
>>>>>>> 04d97acdaf9dadf25b1dec56d2341d5a2e07d4d9
