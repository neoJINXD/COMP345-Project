#pragma once
enum ResourceType {
	Wheat,
	Sheep,
	Timber,
	Stone
};

// declaring struct for each tile
struct Tile
{
	Tile(ResourceType _one, ResourceType _two, ResourceType _three, ResourceType _four)
	{
		one = _one;
		two = _two;
		three = _three;
		four = _four;
	}
	ResourceType one;
	ResourceType two;
	ResourceType three;
	ResourceType four;
};

class HarvestDeck
{
public:
	HarvestDeck();
	~HarvestDeck();
	void buildDeckOfHarvest();


private:

};
