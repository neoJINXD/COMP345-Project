#pragma once
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

//TODO maybe have both decks extend from a base deck class

enum Resource {
	Wheat,
	Sheep,
	Timber,
	Stone
};

namespace deck 
{
	//////////////////////////////// HarvestTile deck
	struct Tile
	{

		Tile(Resource _one, Resource _two, Resource _three, Resource _four)
		{
			*resources = { _one, _two,_three,_four };
		}
		std::vector<Resource>* resources = new std::vector<Resource>();

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

	class Hand
	{
	private:
		std::vector<Tile>* HarvestHand = new std::vector<Tile>();
		std::vector<Building>* BuildingHand = new std::vector<Building>();

		HarvestDeck* _HarvestDeck;
		BuildingDeck* _BuildingDeck;
	public:
		Hand(HarvestDeck* HDeck, BuildingDeck* BDeck);
		~Hand();

		void drawTile();
		void drawBuilding();

		std::pair<int, deck::Tile> exchange();
		void displayTiles();
		void displayBuildings();

		Building getBuilding(int location);
	};

	class HandDriver
	{
	public:
		void run();
	};
}

