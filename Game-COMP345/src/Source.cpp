#include <iostream>
#include <string>
#include "GBMaps/GBMap.h"
#include "VGMaps/VGMap.h"
#include "Resources/Resources.h"
#include "Player/Player.h"

int main()
{

	//player::Player p1("dio");

	//std::cout << p1.getName() << std::endl;

	//GB::GBMapDriver test;
	//test.run();

	//deck::HarvestDriver test1;
	//test1.run();
	//deck::BuildingDriver test2;
	//test2.run();

	//deck::HandDriver zahando;
	//zahando.run();

	deck::HarvestDeck HDeck;
	deck::BuildingDeck BDeck;


	std::string p1 = "jojo";
	player::Player jojo(&p1);
	jojo.createHand(&HDeck, &BDeck);
	
	jojo.DrawBuilding();
	jojo.DrawHarvestTile();
	jojo.DrawHarvestTile();

	jojo.printHand();


	system("pause");
	return 0;
}