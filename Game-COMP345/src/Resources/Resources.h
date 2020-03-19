#pragma once
#ifndef _DEBUG
#define _DEBUG
#endif // !_DEBUG
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <memory>

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
	class Tile
	{
	private:
		std::vector<Resource>* resources;
	public:
		Tile(Resource _one, Resource _two, Resource _three, Resource _four)
		{
			resources = new std::vector<Resource>{ _one, _two,_three,_four };
		}

		//Tile(const Tile& tile) {
		//	resources = new std::vector<Resource>();

		//	for (auto r : *tile.resources) {
		//		resources->push_back(r);
		//	}
		//}

		~Tile();

		std::vector<Resource>* getResources() { return resources; }
		
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
	class Building 
	{
	
		std::unique_ptr<int> cost;
		std::unique_ptr<Resource> resource;
	public:
		Building() : cost(std::make_unique<int>()), resource(std::make_unique<Resource>()) {}
		Building(int _cost, Resource _res) : cost(std::make_unique<int>(_cost)), resource(std::make_unique<Resource>(_res)) {}
		Building(const Building& building);
		~Building();
		void printInfo() const;

		int getCost() const { return *cost.get(); }
		void setCost(int _cost) { *cost = _cost; }
		Resource getResource() const { return *resource.get(); }
		void setResource(Resource _resource) { *resource = _resource; }


	};

	class BuildingDeck
	{
	private:
		std::vector<std::unique_ptr<Building>>* deck;
		void buildDeck();
		void shuffle();

	public:
		BuildingDeck() : deck(new std::vector<std::unique_ptr<Building>>()) { buildDeck(); }
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

		//Building getBuilding(int location);
	};

	class HandDriver
	{
	public:
		void run();
	};
}

