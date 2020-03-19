#pragma once
#ifndef _DEBUG
#define _DEBUG
#endif // !_DEBUG
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif
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


