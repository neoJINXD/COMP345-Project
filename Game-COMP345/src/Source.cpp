#define _DEBUG
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#endif

#include <iostream>
#include <sstream>
#include <string>

#include "Engine/Game.h"
#include "GBMaps/GBMap.h"
#include "GameStart/GameStart.h"
#include "MainLoop/MainLoop.h"
#include "MapLoader/MapLoader.h"
#include "Player/Player.h"
#include "ResourceCounter/ResourceCounter.h"
#include "Resources/Resources.h"
#include "Scoring/Scoring.h"
#include "VGMaps/VGMap.h"

int main() 
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  //A1----------------------------------------------------------------------------------
  // Part 1
  // GB::GBMapDriver testGb;
  // testGb.run();

  // Part 2
  // VG::VGMapDriver testVg;
  // testVg.run();

  // Part 3
  // maploader::MapLoaderDriver mapTest;
  // mapTest.run();

  // Part 4
  // player::PlayerDriver playerTest;
  // playerTest.run();

  // Part 5
  // deck::HarvestDriver hDeckTest;
  // hDeckTest.run();
  // deck::BuildingDriver bDeckTest;
  // bDeckTest.run();
  // deck::HandDriver zahando;
  // zahando.run();

  // Part 6
  //counter::ScoringDriver testScore;
  //testScore.run();
  // counter::ResourceCounterDriver testRC;
  // testRC.run();


  // Game
  //engine::Game gam;
  //gam.loop();

  //A2----------------------------------------------------------------------------------
  // Part 1
  //gi::GameStartDriver O_O;
  //O_O.run();

  // Part 2
  //maingame::MainLoopDriver mainLoop;
  //mainLoop.run();

  // Part 3
  //
  //



  system("pause");
  return 0;
}