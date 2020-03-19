#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include "GBMaps/GBMap.h"
#include "VGMaps/VGMap.h"
#include "Resources/Resources.h"
#include "Player/Player.h"
#include "MapLoader/MapLoader.h"
#include "Scoring/Scoring.h"
#include "ResourceCounter/ResourceCounter.h"

#include <sstream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(952);
	//counter::ScoringDriver testScore;
	//testScore.run();
	//
	//GB::GBMapDriver test;
	//test.run();
	//deck::HarvestDriver test1;
	//counter::ResourceCounterDriver testRC;
	//testRC.run();

	//GB::GBMapDriver testGb;
	//testGb.run();

	//VG::VGMapDriver testVg;
	//testVg.run();
	//GB::GBMapDriver testGb;
	//testGb.run();
	//VG::VGMapDriver testVg;
	//testVg.run();

	//deck::HarvestDriver test1;

	//test1.run();
	deck::BuildingDriver test2;
	test2.run();


	//deck::HandDriver zahando;
	//zahando.run();

	//deck::HarvestDeck HDeck;
	//deck::BuildingDeck BDeck;

	//player::PlayerDriver playerTest;
	//playerTest.run();

	//std::string p1 = "jojo";
	//player::Player jojo(&p1);
	//jojo.createHand(&HDeck, &BDeck);
	
	//jojo.DrawBuilding();
	//jojo.DrawHarvestTile();
	//jojo.DrawHarvestTile();

	//jojo.printHand();


	//std::cout << "Begin Reading file" << std::endl;
	//std::cout << std::endl;

	//Memory leaks here Uwu
	//maploader::MapLoaderDriver mapTest;
	//mapTest.run();


	


	system("pause");
	return 0;
}