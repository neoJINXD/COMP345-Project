#include "ResourceType.h"
#include <vector>
#include <algorithm>
#include <iostream>

// Building Tile


// Building deck class

namespace deck {

	struct Building {
		int* cost;
		ResourceType* resource;
	public:
		void printInfo();
	};

	class BuildingDeck
	{
	private:
		std::vector<Building>* deck;
		void buildDeck();
		void shuffle();

	public:
		BuildingDeck() : deck(new std::vector<Building>()) { buildDeck(); }
		~BuildingDeck();
		
		Building draw();
		void printDeck();
	};

	class BuildingDriver
	{
	public:
		void run();
	};
}
