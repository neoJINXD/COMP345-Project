#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "../GBMaps/GBMap.h"
#include "../VGMaps/VGMap.h"
#include "../Resources/Resources.h"
#include "../ResourceCounter/ResourceCounter.h"
#include <string>

namespace player {
	class Player
	{
	private:
		 GB::GBMap* board;

		

		//Village Board
		VG::VGMap* village;

		deck::HarvestDeck* Hdeck;
		deck::BuildingDeck* Bdeck;

		//Harvest Tile "hand"
		//Building Tile "hand"
		deck::Hand* hands;

		//Resource Counter Markers
		//is temporary
		//counts resources from gameboard
		//then resets at end of turn
		//uses the exchange from part 5

		//Resource Gathered
		//counts resources gained(part 6) by placing tile(part 5)

		//Scoring from village board state(part 6)
		std::map<Resource, int>* counters;
		counter::ResourceCounter* count;

		void init();

	public:
		Player(std::string* _name, GB::GBMap* _board, deck::HarvestDeck* _Hdeck, deck::BuildingDeck* _Bdeck) : name(_name) { board = _board; Hdeck = _Hdeck; Bdeck = _Bdeck;  count = new counter::ResourceCounter();  init(); }
		~Player();
		const std::string* name;
		//std::string getName() { return name; }
		void createHand(deck::HarvestDeck* HDeck, deck::BuildingDeck* BDeck);

		void printHand();

		//part5
		void PlaceHarvestTile();
		void DrawBuilding();
		void DrawHarvestTile();
		void DrawFromField();

		void DrawShipment();
		inline bool hasShipment() { return hands->getShipment() == nullptr; }

		void ResourceTracker(int yes, int no, int maybe, int so);

		//part6
		void BuildVillage();
		void CalculateResources();
		void displayResources();
		void passResources(Player* otherPlayer);
		inline bool getEmptyResources() { return (counters->at(Wheat) == 0 && counters->at(Sheep) == 0 && counters->at(Timber) == 0 && counters->at(Stone) == 0); }

		int countDrawAmount();
		void refreshField();

		int countDrawAmountTiles();

	};

	class PlayerDriver
	{
	public:
		void run();
	};

}

