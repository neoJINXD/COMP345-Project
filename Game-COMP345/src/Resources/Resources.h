#pragma once
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>


enum Resource {
	Wheat,
	Sheep,
	Timber,
	Stone
};

namespace deck 
{
	//////////////////////////////// HarvestTile deck
	class Tile
	{
	private:
		std::vector<Resource>* resources = new std::vector<Resource>();

	public:
		Tile(Resource _one, Resource _two, Resource _three, Resource _four)
		{
			*resources = { _one, _two,_three,_four };
		}
		~Tile();

		void rotateLeft();
		void rotateRight();

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



	//////////////////////////////// Building deck
	struct Building 
	{
		int* cost;
		Resource* resource;
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

