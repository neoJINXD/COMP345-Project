#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "../GBMaps/GBMap.h"
#include "../Resources/Resources.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"
#include <vector>

namespace maingame {
	class GameStart
	{
	private:
		//UwU
		GB::GBMap* gameboard;
		deck::BuildingDeck* buildingDeck;
		deck::HarvestDeck* harvestDeck;

		
		GB::GBMap* initGameBoard(unsigned);
	public:
	
		//Temp
		~GameStart() {
			delete gameboard;
			gameboard = nullptr;

			delete buildingDeck;
			buildingDeck = nullptr;

			delete harvestDeck;
			harvestDeck = nullptr;

		}
		
		deck::HarvestDeck* initHarvestDeck();
		deck::BuildingDeck* initBuildingDeck();

		void drawStart(player::Player* player);

		//Call new on players
		std::vector<player::Player*>* initPlayers(unsigned totalPlayers);
		
		//Game boards and deck are passed around

		//Set gameboard using maploader
		//Create decks - 
		//Set hand 

	};

	class GameStartDriver {
	public:
		void run();
	};
}
