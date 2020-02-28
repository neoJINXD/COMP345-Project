#pragma once
#include "../GBMaps/GBMap.h"
#include "../VGMaps/VGMap.h"
#include "../Resources/Resources.h"
#include <string>

namespace player {
	class Player
	{
	private:
		const GB::GBMap* board;

		const std::string* name;

		//Village Board
		const VG::VGMap* village;

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

		void initVB();

	public:
		Player(std::string* _name, GB::GBMap* _board) : name(_name), board(_board) { initVB(); }
		~Player();

		//std::string getName() { return name; }
		void createHand(deck::HarvestDeck* HDeck, deck::BuildingDeck* BDeck);

		void printHand();

		//part5
		void PlaceHarvestTile();
		void DrawBuilding();
		void DrawHarvestTile();
		void ResourceTracker();

		//part6
		void BuildVillage();
		void CalculateResources();



	};

}

