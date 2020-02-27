#include <iostream>

#include "GBMaps/GBMap.h"
#include "VGMaps/VGMap.h"
#include "Resources/Resources.h"
#include "Player/Player.h"

int main()
{

	player::Player p1("dio");

	std::cout << p1.getName() << std::endl;

	//GB::GBMapDriver test;
	//test.run();

	//deck::HarvestDriver test1;
	//test1.run();
	//deck::BuildingDriver test2;
	//test2.run();


	system("pause");
	return 0;
}