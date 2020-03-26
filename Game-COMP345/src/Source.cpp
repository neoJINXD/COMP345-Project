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
#include "Engine/Game.h"

#include <sstream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Part 1 - LEAK FREE
	//GB::GBMapDriver testGb;
	//testGb.run();

	//Part 2 - LEAK FREE
	//VG::VGMapDriver testVg;
	//testVg.run();

	//Part 3 - LEAK FREE
	//maploader::MapLoaderDriver mapTest;
	//mapTest.run();

	//Part 4 - LEAK FREE
	//player::PlayerDriver playerTest;
	//playerTest.run();

	//Part 5
	// - LEAK FREE
	//deck::HarvestDriver hDeckTest;
	//hDeckTest.run();

	// - LEAK FREE
	//deck::BuildingDriver bDeckTest;
	//bDeckTest.run();

	// - LEAK FREE
	//deck::HandDriver zahando;
	//zahando.run();

	//Part 6 - LEAK FREE
	//counter::ScoringDriver testScore;
	//testScore.run();
	//counter::ResourceCounterDriver testRC;
	//testRC.run();

	//Game
	//engine::Game gam;
	//gam.loop();


	system("pause");
	return 0;
}