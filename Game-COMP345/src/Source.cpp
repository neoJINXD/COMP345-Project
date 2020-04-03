#define _DEBUG
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#endif

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
#include "MainLoop/MainLoop.h"

#include <sstream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Part 1
	//GB::GBMapDriver testGb;
	//testGb.run();


	//Part 2
	//VG::VGMapDriver testVg;
	//testVg.run();


	//Part 3
	//maploader::MapLoaderDriver mapTest;
	//mapTest.run();


	//Part 4
	//player::PlayerDriver playerTest;
	//playerTest.run();


	//Part 5
	//deck::HarvestDriver hDeckTest;
	//hDeckTest.run();
	//deck::BuildingDriver bDeckTest;
	//bDeckTest.run();
	//deck::HandDriver zahando;
	//zahando.run();


	//Part 6
	//counter::ScoringDriver testScore;
	//testScore.run();
	//counter::ResourceCounterDriver testRC;
	//testRC.run();

	//Game
	//engine::Game gam;
	//gam.loop();

	//Part 2
	maingame::MainLoopDriver mainLoop;
	mainLoop.run();

	system("pause");
	return 0;
}