#include "MapLoader.h"
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

GB::GBMap* maploader::MapLoader::loadMap(std::string path, int playerCount)
{
	std::vector<int> nullKeys;
	std::unordered_map<int, deck::Tile*> starterTiles;

	std::ifstream inFile(path);

	if (!inFile)
	{
		std::cout << "Error: Failed to open file" << std::endl;
		return nullptr;
	}

	//char str[255];
	std::string str;
	bool tiles = false;
	bool nulls = false;

	//int key = 0;

	while (std::getline(inFile, str))
	{
		//Read the line
		//std::getline(inFile, str);
		//inFile.getline(str, 255);
		
		//if reached the flag for tiles
		if (str == "[TILES]")
		{
			tiles = true;
			//std::cout << "starting Tiles" << std::endl;
			continue;
		}
		//if reached the flag for nulls
		if (str == "[NULL]")
		{
			nulls = true;
			//std::cout << "starting Nulls" << std::endl;
			continue;
		}
		//key++;


		//std::cout << str << std::endl;


		//if reached the flag for end
		if (str == "[END]")
		{
			//std::cout << "Finished" << std::endl;
			if (tiles)
			{
				tiles = !tiles;
			}
			if (nulls)
			{
				nulls = !nulls;
			}
		}
		if (tiles)
		{

			const int TILESIZE = 5;
			std::string line[TILESIZE];
			int numbers[TILESIZE];
			int i = 0;
			std::stringstream ssin(str);
			while (ssin.good() && i < TILESIZE)
			{
				ssin >> line[i];
				++i;
			}

			if (i < TILESIZE)
			{
				std::cout << "Error: Invalid Tile format in file" << std::endl;
				return nullptr;
			}
			
			for (i = 0; i < TILESIZE; i++)
			{
				numbers[i] = std::stoi(line[i]);
			}
			
			starterTiles.insert({ numbers[0], new deck::Tile(static_cast<Resource>(numbers[1]), static_cast<Resource>(numbers[2]), static_cast<Resource>(numbers[3]), static_cast<Resource>(numbers[4])) });
		}
		if (nulls)
		{
			nullKeys.push_back(std::stoi(str));
		}
	}

	if (tiles || nulls)
	{
		std::cout << "Error: Invalid Ending Flags in text file" << std::endl;
		return nullptr;
	}

	if (starterTiles.size() == 0)
	{
		std::cout << "Error: No Starting Tiles specified" << std::endl;
		return nullptr;
	}

	inFile.close();

	//Create GB from file
	std::cout << "Success" << std::endl;

	GB::GBMap* newMap = new GB::GBMap(playerCount);

	if (newMap->buildBoard())
	{
		if (nullKeys.size() > 0)
			newMap->blockKeys(nullKeys);
		for (auto it : starterTiles)
		{
			newMap->placeTile(it.first, it.second);
			//std::cout << "key: " << it.first << std::endl;
			//it.second->printInfo();
		}

	}

	return newMap;
}

void maploader::MapLoaderDriver::run()
{
	maploader::MapLoader loader;
	//std::cout << "Loading 2 player default map" << std::endl;
	//GB::GBMap* two = loader.loadMap("./src/Maps/2player.txt", 2);
	//std::cout << "Default tile at 1 is: " << std::endl;
	//two->peekTile(1)->printInfo();
	//std::cout << std::endl;
	//std::cout << "Loading 3 player default map" << std::endl;
	//loader.loadMap("./src/Maps/3player.txt", 3);
	//std::cout << std::endl;
	std::cout << "Loading 4 player default map" << std::endl;
	GB::GBMap* four = loader.loadMap("./src/Maps/4player.txt", 4);
	std::cout << "Default tile at 9 is: " << std::endl;
	//four->peekTile(9)->printInfo();
	//std::cout << "Loading" << std::endl;
	//loader.loadMap("./src/Maps/InvalidTileFormat.txt");
	std::cout << std::endl;

	//delete two;
	//two = nullptr;

	delete four;
	four = nullptr;
}
