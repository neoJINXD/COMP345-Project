#pragma once
#include "../Resources/Resources.h"
#include <string>


namespace maploader 
{

	class MapLoader
	{
	public:
		void loadMap(std::string path); // returns GBMap

	};

	class MapLoaderDriver 
	{
	public:
		void run();
	};

}


