#pragma once
#include "../VGMaps/VGMap.h"
#include <string>

namespace player {
	class Player
	{
	private:
		std::string name;

		//Village Board
		VG::VGMap* village;

		//Harvest Tile "hand"

		//Building Tile "hand"


		//Resource Counter Markers
		//is temporary
		//counts resources from gameboard
		//then resets at end of turn
		//uses the exchange from part 5

		//Resource Gathered
		//counts resources gained(part 6) by placing tile(part 5)

		//Scoring from village board state(part 6)


	public:
		Player(std::string _name);
		~Player();

		std::string getName() { return name; }

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

