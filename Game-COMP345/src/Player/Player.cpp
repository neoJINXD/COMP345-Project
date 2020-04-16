#include "Player.h"
#include <cmath>

void player::Player::trackBuildings(int loc, Resource res)
{
	int row = loc / 6; // top = row - 1, bot = row + 1 ->  
	int col = loc % 6; // right = col + 1, left = col - 1 ->
	if (col == 0) col = 1;

	if (row - 1 >= 0) { resourceLoc->at(res).push_back((row - 1) * 5 + col); } //possible top loc
	if (row + 1 <= 5) { resourceLoc->at(res).push_back((row + 1) * 5 + col); } // possible bot loc
	if (col - 1 > 0) { resourceLoc->at(res).push_back(row * 5 + (col - 1)); }//possible left loc
	if (col + 1 < 6) { resourceLoc->at(res).push_back(row * 5 + (col + 1)); }//possible right loc

}

void player::Player::init()
{
	hands = new deck::Hand(Hdeck, Bdeck);
	std::cout << "Creating Village" << std::endl;
	village = new VG::VGMap("Boiomer"); //TODO remove
	counters = new std::map<Resource, int>();
	resourceLoc = new std::map<Resource, std::vector<int>>({ {Wheat,std::vector<int>()}, {Sheep,std::vector<int>()}, {Stone,std::vector<int>()}, {Timber,std::vector<int>()} });
	//count = new counter::ResourceCounter();
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

	//delete count;
	//count = nullptr;

	delete resourceLoc;
	resourceLoc = nullptr;
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
	int maxField = hands->getFieldAmount() - 1;
	std::cout << "Pick which building to draw from the selection; (0 to "<< maxField <<")" << std::endl;
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
	//counter::ResourceCounter count;
	std::map<Resource, int> counted = count->harvestCount(board->getRecentNode());
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

void player::Player::insertShipment(int location)
{
	board->placeTile(location, hands->getShipment());
	hands->killShipment();
}

deck::Tile* player::Player::getTileAt(int location)
{
	return board->peekTile(location);
}

std::pair<bool, int> player::Player::PlaceHarvestTile()
{
	int selection;
	std::cout << "Place harvest tile(1) or shipment tile(2)?" << std::endl;
	std::cin >> selection;
	std::cout << std::endl;

	int gbSize = board->getBoardSize();
	
	if (selection == 1)
	{
		// Placing normal harvest Tile
		std::cout << "Placing Harvest tile" << std::endl;

		int location;

		do
		{
			std::cout << "Select a location (1 to " << gbSize << ")" << std::endl;
			std::cin >> location;

			if (board->peekTile(location) == nullptr)
				break;
			else
				std::cout << "Invalid location, A tile is already placed there" << std::endl;
		} while (true);

		std::pair<int, deck::Tile*> placement = hands->exchange(location);


		board->placeTile(placement.first, placement.second);
		std::cout << "Placing at " << placement.first << std::endl;
		board->peekTile(placement.first)->printInfo();
		std::cout << std::endl;
		return std::pair<bool, int>(false, 0);

	}
	else if (selection == 2)
	{
		// Placing shipment tile
		std::cout << "Placing Shipment tile" << std::endl;

		int topLeft;
		int topRight;
		int bottomRight;
		int bottomLeft;


		std::cout << "Wheat:0, Sheep:1, Timber:2, Stone:3" << std::endl;
		std::cout << "What is top left resource" << std::endl;
		std::cin >> topLeft;
		std::cout << "What is top right resource" << std::endl;
		std::cin >> topRight;
		std::cout << "What is bottom right resource" << std::endl;
		std::cin >> bottomLeft;
		std::cout << "What is bottom left resource" << std::endl;
		std::cin >> bottomRight;
		
		//new tile with resource
		deck::Tile* eugen = new deck::Tile(static_cast<Resource>(topLeft), static_cast<Resource>(topRight), static_cast<Resource>(bottomRight), static_cast<Resource>(bottomLeft));

		//place in board
		int location;

		do
		{
			std::cout << "Select a location" << std::endl;
			std::cin >> location;
			
			if (board->peekTile(location) == nullptr)
				break;
			else
				std::cout << "Invalid location, A tile is already placed there" << std::endl;
		} while (true);

		board->placeTile(location, eugen);
		std::cout << "Placing at " << location << std::endl;
		board->peekTile(location)->printInfo();
		
		//return true since placed shipment tile
		std::cout << std::endl;
		return std::pair<bool, int>(true, location);
	}
	else
	{
		std::cout << "Invalid selection" << std::endl;
	}


}

bool player::Player::BuildVillage()
{
	hands->displayBuildings();

	int selection;
	std::cout << "Current Resource Stockpile:\n";
	for (auto r : *counters) {
		std::cout << r.first << ":\t" << r.second << std::endl;
	} 
	int maxSize = hands->getBuildingSize() - 1;
	
	std::cout << "Select a building: ( 0 to " << maxSize << " or -1 to skip )" << std::endl;
	std::cin >> selection;

	if (selection < 0) {
		std::cout << "Deciding not place UmU!\n";
		return false;
	}

	deck::Building* selected = hands->peekBuilding(selection);
	Resource buildingsRes = *selected->getResource();
	bool canBuild = true;

	if (getResourceAmount(*selected->getResource()) - selected->getCost() < 0) {
		canBuild = false;
	}

	while (!canBuild) {
		std::cout << "You do not have enough resources to place this building, pick another!\n";
		std::cout << "Select a building: ( 0 to " << maxSize << " or -1 to skip )" << std::endl;
		std::cin >> selection;
		if (selection < 0) {
			std::cout << "Deciding not place UmU!\n";
			return false;
		}
		selected = hands->peekBuilding(selection);
		buildingsRes = *selected->getResource();

		if (getResourceAmount(*selected->getResource()) - selected->getCost() >= 0) {
			canBuild = true;
		}
		
	}
	bool firstTimeResource = true;

	//Checks for an existing resource in the village
	if (!resourceLoc->at(*selected->getResource()).empty()) {
		firstTimeResource = false;
	}

	std::cout << "Do you want to place the building face down? (1 = yes / 0 = no)\n";
	int choice; 
	std::cin >> choice;

	if (choice > 0) {
		std::cout << "Setting selected building face down!\n";
		selected->setFaceDown(true);
	} 

	int location;

	if (!firstTimeResource) {
		for (auto loc : resourceLoc->at(buildingsRes)) {
			
			if (village->peekBuilding(loc) == nullptr)
				std::cout << loc << ", ";
		}
		std::cout << std::endl;
	}

	std::cout << "Select a location (1 to 30)" << std::endl;
	std::cin >> location;
	int row = ceil(location / 5.0f);
	int cost = 7 - row;
	std::cout << "Cost at location " << location << ": Row: " << row << " Cost: " << cost << std::endl;

	bool validLoc = std::find(resourceLoc->at(buildingsRes).begin(), resourceLoc->at(buildingsRes).end(), location) != resourceLoc->at(buildingsRes).end();
	while (village->peekBuilding(location) != nullptr || 
		(cost != selected->getCost() && !selected->getFaceDown()) || (!firstTimeResource && !validLoc)) {

		//Check if selected location is not occupied by an existing building
		if (village->peekBuilding(location) != nullptr) {
			std::cout << "A building already occupies this location!\nSelect location: (1 to 30)\n";
			std::cin >> location;
		}

		//Check if Cost is valid for the location
		else if (cost != selected->getCost() && !selected->getFaceDown()) {
			//std::cout << "Cost at location " << location << ": Row: " << row << " Cost: " << cost << std::endl;
			std::cout << "Please Select the location with the correct cost\nSelect location: (1 to 30)\n";
			std::cin >> location;
			row = ceil(location / 5.0f);
			cost = 7 - row;
		}

		//Check if selected location is adjacent to an existing building
		else if (!firstTimeResource && !validLoc) {
			for (auto loc : resourceLoc->at(buildingsRes)) {
				std::cout << loc << ", ";
			}
			std::cout << std::endl;
			std::cout << "Please place building adjacent to existing building!\nSelect location: (1 to 30)\n";
			std::cin >> location;
			validLoc = std::find(resourceLoc->at(buildingsRes).begin(), resourceLoc->at(buildingsRes).end(), location) != resourceLoc->at(buildingsRes).end();

		}
		
	}

	village->placeBuilding(location, selected);
	//Track current buildings to show possible placements
	trackBuildings(location, *selected->getResource());
	std::cout << "Placing at " << location << std::endl;
	village->peekBuilding(location)->printInfo();


	freeSpaceInVillage--;
	return true;

}

//Check for adjacent buildings at this location


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