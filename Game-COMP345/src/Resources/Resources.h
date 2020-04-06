#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <memory>
//#include "../GBMaps/GBMap.h"


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
		bool* isFaceDown;
	public:
		Tile(Resource _one, Resource _two, Resource _three, Resource _four) : isFaceDown(new bool(false))
		{
			resources = new std::vector<Resource>{ _one, _two,_three,_four };
		}

		//Tile(const Tile& tile) 
		//{
		//	resources = new std::vector<Resource>();
		//	for (int i = 0; i < tile.resources->size(); i++)
		//		resources->push_back(tile.resources->at(i));
		//	//*resources = *tile.resources;
		//}

		Tile& operator=(const Tile& other)
		{
			resources = new std::vector<Resource>();
			for (int i = 0; i < other.resources->size(); i++)
				resources->push_back(other.resources->at(i));

			return *this;
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
		void setFaceDown() { *isFaceDown = true; }
		bool getFaceDown() { return *isFaceDown; }
	};


	class HarvestDeck
	{
	private:
		std::vector<Tile*>* deck;
		void buildDeck();
		void shuffle();


	public:
		HarvestDeck() : deck(new std::vector<Tile*>()) { buildDeck(); }
		~HarvestDeck();

		Tile* draw();
		void printDeck();

		Tile* drawShipment();

	};

	class HarvestDriver
	{
	public:
		void run();
	};



	//////////////////////////////// Building deck
	class Building 
	{
		bool* isFaceDown;
		int* cost;
		Resource* resource;
	public:
		Building() : cost(new int()), resource(new Resource()), isFaceDown(new bool(false)) {}
		Building(int _cost, Resource _res) : cost(new int(_cost)), resource(new Resource(_res)), isFaceDown(new bool(false)) {}
		Building(const Building& building);
		~Building();
		void printInfo() const;

		int getCost() const { return *cost; }
		void setCost(int _cost) { *cost = _cost; }
		Resource getResource() const { return *resource; }
		void setResource(Resource _resource) { *resource = _resource; }
		void setFaceDown(bool _FaceDown) { *isFaceDown = _FaceDown; }
		bool getFaceDown() { return *isFaceDown; }


	};

	class BuildingDeck
	{
	private:
		std::vector<Building*>* deck;
		std::vector<Building*>* boardField;
		void buildDeck();
		void shuffle();

	public:
		BuildingDeck() : 
			deck(new std::vector<Building*>()), 
			boardField(new std::vector<Building*>()) 
		{ buildDeck(); }

		~BuildingDeck();

		Building* draw();
		Building* drawFromField(int pos);
		void refreshBoardField();

		void printDeck();
		void printField();
	};

	class BuildingDriver
	{
	public:
		void run();
	};

	class Hand
	{
	private:
		std::vector<Tile*>* HarvestHand = new std::vector<Tile*>();
		std::vector<Building*>* BuildingHand = new std::vector<Building*>();

		HarvestDeck* _HarvestDeck;
		BuildingDeck* _BuildingDeck;

		Tile* shipmentTile = nullptr;
	public:
		Hand(HarvestDeck* HDeck, BuildingDeck* BDeck);
		~Hand();

		void drawTile();
		void drawBuilding();
		void drawFromField(int pos);
		void refreshField();

		int countHarvestHand();

		std::pair<int, deck::Tile*> exchange(int loc);
		void displayTiles();
		void displayBuildings();
		void displayField();

		Building* getBuilding(int location);

		Tile* getShipment() { return shipmentTile; }
		void drawShipment();

		inline void killShipment() { shipmentTile = nullptr; }
		inline int getBuildingSize() { return BuildingHand->size(); }
	};

	class HandDriver
	{
	public:
		void run();
	};
}

