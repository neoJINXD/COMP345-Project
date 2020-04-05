#include "Player.h"

void player::Player::init()
{
	hands = new deck::Hand(Hdeck, Bdeck);
	std::cout << "Creating Village" << std::endl;
	village = new VG::VGMap("Boiomer"); //TODO remove
	counters = new std::map<Resource, int>();
}


player::Player::~Player() 
{

   //delete board;
   board = nullptr;

	delete name;
	name = nullptr;

	// delete village
	delete village;
	village = nullptr;

	// delete hands
	delete hands;
	hands = nullptr;

	delete counters;
	counters = nullptr;
}

void player::Player::createHand(deck::HarvestDeck* HDeck,
	deck::BuildingDeck* BDeck)
{
	std::cout << "Creating Hand" << std::endl;

	hands = new deck::Hand(HDeck, BDeck);
}

void player::Player::printHand()
{
	hands->displayBuildings();
	hands->displayTiles();
	if (hands->getShipment())
		std::cout << "This player has a Shipment Card" << std::endl;
	else
		std::cout << "No Shipment Tile available" << std::endl;
}

void player::Player::DrawBuilding() { hands->drawBuilding(); }

void player::Player::DrawHarvestTile() { hands->drawTile(); }

void player::Player::DrawFromField()
{
	std::cout << "Pick which building to draw from the selection" << std::endl;
	hands->displayField();

	int selection;
	std::cin >> selection;
	hands->drawFromField(selection);
}

void player::Player::DrawShipment() { hands->drawShipment(); }

void player::Player::ResourceTracker(int yes, int no, int maybe, int so)
{
	counters->emplace(Wheat, yes);
	counters->emplace(Sheep, no);
	counters->emplace(Timber, maybe);
	counters->emplace(Stone, so);
}

void player::Player::CalculateResources()
{
	counter::ResourceCounter count;
	std::map<Resource, int> counted = count.harvestCount(board->getRecentNode());
	ResourceTracker(counted.at(Wheat), counted.at(Sheep), counted.at(Timber),
		counted.at(Stone));
}

void player::Player::displayResources()
{
	std::cout << "Current ressources: " << std::endl;
	std::cout << "Wheat: " << counters->at(Wheat) << std::endl;
	std::cout << "Sheep: " << counters->at(Sheep) << std::endl;
	std::cout << "Timber: " << counters->at(Timber) << std::endl;
	std::cout << "Stone: " << counters->at(Stone) << std::endl;
}

void player::Player::passResources(Player* otherPlayer)
{
	otherPlayer->ResourceTracker(
		counters->at(Wheat),
		counters->at(Sheep),
		counters->at(Timber),
		counters->at(Stone)
	);
}

int player::Player::countDrawAmount()
{
	int result = 0;

	for (auto i : *counters) {
		if (i.second == 0) result++;
	}

	return result;
}

void player::Player::refreshField() { hands->refreshField(); }

int player::Player::countDrawAmountTiles()
{
	int result = 2;
	// hand always need to have 2 harvest tiles
	result -= hands->countHarvestHand();
	std::cout << "need to draw:  " << result << std::endl;

	return result;
}

void player::Player::PlaceHarvestTile()
{
	int selection;
	std::cout << "Place harvest tile(1) or shipment tile(2)?" << std::endl;
	std::cin >> selection;
	std::cout << std::endl;

	if (selection == 1)
	{
		// Placing normal harvest Tile
		std::cout << "Placing Hervest tile" << std::endl;

		std::pair<int, deck::Tile*> placement = hands->exchange();
		board->placeTile(placement.first, placement.second);
		std::cout << "Placing at " << placement.first << std::endl;
		board->peekTile(placement.first)->printInfo();
		std::cout << std::endl;

	}
	else if (selection == 2)
	{
		// Placing shipment tile
		std::cout << "Placing Shipment tile" << std::endl;
		std::cout << std::endl;

	}
	else
	{
		std::cout << "Invalid selection" << std::endl;
	}


}

void player::Player::BuildVillage()
{
	hands->displayBuildings();

	int location;
	std::cout << "Select a location" << std::endl;
	std::cin >> location;

	int selection;
	std::cout << "Select a building" << std::endl;
	std::cin >> selection;

	deck::Building* selected = hands->getBuilding(selection);
	village->placeBuilding(location, selected);
	std::cout << "Placing at " << location << std::endl;
	village->peekBuilding(location)->printInfo();
}

void player::PlayerDriver::run()
{
	GB::GBMap* map = new GB::GBMap(2);
	map->buildBoard();

	deck::HarvestDeck* Hdeck = new deck::HarvestDeck();
	deck::BuildingDeck* Bdeck = new deck::BuildingDeck();

	std::string* name = new std::string("Josuke");
	Player jojo(name, map, Hdeck, Bdeck);

	jojo.DrawBuilding();
	jojo.DrawBuilding();

	jojo.DrawHarvestTile();
	jojo.DrawHarvestTile();
	jojo.DrawHarvestTile();

	jojo.DrawShipment();

	std::cout << "Attempting to place Harvest Tile on Game Board" << std::endl;
	jojo.PlaceHarvestTile();
	jojo.CalculateResources();
	jojo.PlaceHarvestTile();


	std::cout << "Attempting to place Building on Village Board" << std::endl;
	jojo.BuildVillage();
	jojo.BuildVillage();

	delete map;
	map = nullptr;

	delete Hdeck;
	Hdeck = nullptr;

	delete Bdeck;
	Bdeck = nullptr;

}