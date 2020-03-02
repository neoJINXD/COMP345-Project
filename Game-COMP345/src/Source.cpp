#include <iostream>
#include <string>
#include "GBMaps/GBMap.h"
#include "VGMaps/VGMap.h"
#include "Resources/Resources.h"
#include "Player/Player.h"
#include "MapLoader/MapLoader.h"
#include "Scoring/Scoring.h"

#include <sstream>

int main()
{

	counter::ScoringDriver testScore;
	testScore.run();

	//GB::GBMapDriver test;
	//test.run();
	//deck::HarvestDriver test1;

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
	//deck::BuildingDriver test2;
	//test2.run();


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


	//maploader::MapLoaderDriver mapTest;
	//mapTest.run();


	/*std::string line = "1 3 1 2 2";
	const int size = 5;
	std::string arr[size];
	int i = 0;
	std::stringstream ssin(line);
	while (ssin.good() && i < size) {
		ssin >> arr[i];
		++i;
	}
	for (i = 0; i < 4; i++) {
		std::cout << arr[i] << std::endl;
	}*/

	//std::cout << "Ending Reading file" << std::endl;


	system("pause");
	return 0;
}