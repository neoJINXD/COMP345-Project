#pragma once
#include "../Resources/Resources.h"
#include "../GBMaps/GBMap.h"
#include <string>


namespace maploader 
{

	class MapLoader
	{
	public:
		GB::GBMap* loadMap(std::string path, int playerCount); // returns GBMap

	};

	class MapLoaderDriver 
	{
	public:
		void run();
	};

}


