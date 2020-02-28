#include "MapLoader.h"
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

void maploader::MapLoader::loadMap(std::string path)
{
	std::vector<int> nullKeys;
	std::unordered_map<int, deck::Tile> starterTiles;

	std::ifstream inFile(path);

	if (!inFile)
	{
		std::cout << "Error: Failed to open file" << std::endl;
		return;
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
				return;
			}
			
			for (i = 0; i < TILESIZE; i++)
			{
				numbers[i] = std::stoi(line[i]);
			}
			
			starterTiles.insert({ numbers[0], deck::Tile(static_cast<Resource>(numbers[1]), static_cast<Resource>(numbers[2]), static_cast<Resource>(numbers[3]), static_cast<Resource>(numbers[4])) });
		}
		if (nulls)
		{
			nullKeys.push_back(std::stoi(str));
		}
	}

	if (tiles || nulls)
	{
		std::cout << "Error: Invalid Ending Flags in text file" << std::endl;
		return;
	}

	if (starterTiles.size() == 0)
	{
		std::cout << "Error: No Starting Tiles specified" << std::endl;
		return;
	}

	inFile.close();

	//Create GB from file
	std::cout << "Success" << std::endl;

}

void maploader::MapLoaderDriver::run()
{
	maploader::MapLoader loader;
	std::cout << "Loading 2 player default map" << std::endl;
	loader.loadMap("./src/Maps/2player.txt");
	//std::cout << std::endl;
	//std::cout << "Loading 3 player default map" << std::endl;
	//loader.loadMap("./src/Maps/3player.txt");
	//std::cout << std::endl;
	//std::cout << "Loading 4 player default map" << std::endl;
	//loader.loadMap("./src/Maps/4player.txt");
	//std::cout << "Loading" << std::endl;
	//loader.loadMap("./src/Maps/InvalidTileFormat.txt");
	std::cout << std::endl;

}
