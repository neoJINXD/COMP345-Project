#include <iostream>

#include "GBMaps/GBMap.h";
#include "VGMaps/VGMap.h";
#include "Resources/Resources.h"


int main()
{
	GB::GBMapDriver testGb;
	//testGb.run();
	VG::VGMapDriver testVg;
	testVg.run();

	deck::HarvestDriver test1;
	//test1.run();
	deck::BuildingDriver test2;
	//test2.run();

	system("pause");
	return 0;
}