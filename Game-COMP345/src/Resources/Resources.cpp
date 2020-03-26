#include "Resources.h"


#include <ctime>
#include <random>
#include <chrono>


//Random Generator with random seeding
int IOP(int x)
{
	srand(time(nullptr));
	return std::rand() % x;
}

//////////////////////////////// HarvestTile deck


deck::Tile::~Tile()
{
	resources->clear();
	delete resources;
	resources = nullptr;
}

// Shifts vector values to the left
void deck::Tile::rotateLeft() 
{
	std::rotate(resources->begin(), resources->begin() + 1, resources->end());
}

// Shifts vector values to the right
void deck::Tile::rotateRight() 
{
	std::rotate(resources->rbegin(), resources->rbegin() + 1, resources->rend());
}

// Prints the Tile
void deck::Tile::printInfo() 
{
	if (this)
	{
		std::cout << "Card: " << resources->at(0) << resources->at(1) << resources->at(2) << resources->at(3) << std::endl;
	}
	else
	{
		std::cout << "Empty" << std::endl;
	}
}


deck::HarvestDeck::~HarvestDeck() 
{
	
	for (auto i : *deck)
	{
		delete i;
	}
	deck->clear();

	delete deck;
	deck = nullptr;
}


// Creates the deck
void deck::HarvestDeck::buildDeck()
{
	//push each elements in the array
	deck->push_back(new deck::Tile(Wheat, Stone, Stone, Wheat));  // Tile 1 
	deck->push_back(new deck::Tile(Timber, Timber, Stone, Timber)); // Tile 2
	deck->push_back(new deck::Tile(Sheep, Sheep, Stone, Sheep)); // Tile 3
	deck->push_back(new deck::Tile(Wheat, Timber, Stone, Wheat)); // Tile 4
	deck->push_back(new deck::Tile(Timber, Wheat, Wheat, Timber)); //Tile 5
	deck->push_back(new deck::Tile(Sheep, Sheep, Wheat, Sheep)); //Tile 6
	deck->push_back(new deck::Tile(Timber, Stone, Stone, Timber)); // Tile 7
	deck->push_back(new deck::Tile(Stone, Wheat, Sheep, Stone)); // Tile 8
	deck->push_back(new deck::Tile(Wheat, Stone, Sheep, Wheat)); // Tile 9
	deck->push_back(new deck::Tile(Sheep, Stone, Wheat, Sheep)); // Tile 10
	deck->push_back(new deck::Tile(Timber, Sheep, Stone, Timber)); // Tile 11
	deck->push_back(new deck::Tile(Wheat, Sheep, Timber, Wheat)); // Tile 12
	deck->push_back(new deck::Tile(Timber, Stone, Timber, Sheep)); // Tile 13
	deck->push_back(new deck::Tile(Stone, Stone, Sheep, Stone)); // Tile 14
	deck->push_back(new deck::Tile(Sheep, Stone, Stone, Sheep)); // Tile 15
	deck->push_back(new deck::Tile(Sheep, Wheat, Stone, Sheep)); // Tile 16
	deck->push_back(new deck::Tile(Timber, Wheat, Wheat, Timber)); // Tile 17
	deck->push_back(new deck::Tile(Timber, Stone, Wheat, Timber)); // Tile 18
	deck->push_back(new deck::Tile(Sheep, Wheat, Wheat, Sheep)); // Tile 19
	deck->push_back(new deck::Tile(Sheep, Sheep, Timber, Sheep)); // Tile 20
	deck->push_back(new deck::Tile(Timber, Wheat, Stone, Timber)); // Tile 21
	deck->push_back(new deck::Tile(Stone, Sheep, Wheat, Stone)); // Tile 22
	deck->push_back(new deck::Tile(Stone, Stone, Wheat, Stone)); // Tile 23
	deck->push_back(new deck::Tile(Sheep, Stone, Sheep, Timber)); // Tile 24
	deck->push_back(new deck::Tile(Sheep, Wheat, Sheep, Timber)); //Tile 25
	deck->push_back(new deck::Tile(Stone, Wheat, Timber, Stone)); //Tile 26
	deck->push_back(new deck::Tile(Wheat, Sheep, Wheat, Timber)); // Tile 27
	deck->push_back(new deck::Tile(Stone, Stone, Timber, Stone)); // Tile 28
	deck->push_back(new deck::Tile(Timber, Sheep, Sheep, Timber)); // Tile 29
	deck->push_back(new deck::Tile(Wheat, Stone, Wheat, Timber)); // Tile 30
	deck->push_back(new deck::Tile(Sheep, Stone, Wheat, Sheep)); // Tile 31
	deck->push_back(new deck::Tile(Wheat, Timber, Sheep, Wheat)); // Tile 32
	deck->push_back(new deck::Tile(Stone, Sheep, Timber, Stone)); //Tile 33
	deck->push_back(new deck::Tile(Timber, Wheat, Sheep, Timber)); // Tile 34
	deck->push_back(new deck::Tile(Timber, Stone, Timber, Wheat)); //Tile 35
	deck->push_back(new deck::Tile(Wheat, Wheat, Timber, Wheat)); //Tile 36
	deck->push_back(new deck::Tile(Sheep, Timber, Wheat, Sheep)); // Tile 37
	deck->push_back(new deck::Tile(Timber, Sheep, Sheep, Timber)); // Tile 38
	deck->push_back(new deck::Tile(Wheat, Wheat, Sheep, Wheat)); // Tile 39
	deck->push_back(new deck::Tile(Wheat, Wheat, Stone, Wheat)); // Tile 40
	deck->push_back(new deck::Tile(Timber, Sheep, Wheat, Timber)); // Tile 41
	deck->push_back(new deck::Tile(Stone, Timber, Wheat, Stone)); // Tile 42
	deck->push_back(new deck::Tile(Sheep, Stone, Timber, Sheep)); // Tile 43
	deck->push_back(new deck::Tile(Stone, Wheat, Stone, Timber)); // Tile 44
	deck->push_back(new deck::Tile(Timber, Stone, Sheep, Timber)); // Tile 45
	deck->push_back(new deck::Tile(Sheep, Stone, Stone, Sheep)); //Tile 46
	deck->push_back(new deck::Tile(Stone, Timber, Sheep, Stone)); // Tile 47
	deck->push_back(new deck::Tile(Timber, Timber, Wheat, Timber)); //Tile 48
	deck->push_back(new deck::Tile(Sheep, Wheat, Wheat, Sheep)); // Tile 49
	deck->push_back(new deck::Tile(Wheat, Sheep, Stone, Wheat)); // Tile 50
	deck->push_back(new deck::Tile(Timber, Wheat, Timber, Sheep)); // Tile 51
	deck->push_back(new deck::Tile(Wheat, Stone, Stone, Wheat)); // Tile 52
	deck->push_back(new deck::Tile(Wheat, Stone, Timber, Wheat)); // Tile 53
	deck->push_back(new deck::Tile(Stone, Sheep, Stone, Timber)); //Tile 54
	deck->push_back(new deck::Tile(Stone, Wheat, Stone, Sheep)); // Tile 55
	deck->push_back(new deck::Tile(Sheep, Wheat, Timber, Sheep)); // Tile 56
	deck->push_back(new deck::Tile(Timber, Timber, Sheep, Timber)); //Tile 57
	deck->push_back(new deck::Tile(Sheep, Timber, Stone, Sheep)); // Tile 58
	deck->push_back(new deck::Tile(Wheat, Stone, Wheat, Sheep)); // Tile 59
	deck->push_back(new deck::Tile(Timber, Stone, Stone, Timber)); // TIle 60

	// Shuffle the deck
	this->shuffle();
}



// Shuffles the deck
void deck::HarvestDeck::shuffle()
{
	//get current time and use it as a seed
	typedef std::chrono::high_resolution_clock gold_experience_requiem;
	auto ekko = gold_experience_requiem::now();

	auto seed = ekko.time_since_epoch().count();
	auto IOP = std::default_random_engine(seed);

	std::shuffle(deck->begin(), deck->end(), IOP);
}

// Draws a card
deck::Tile* deck::HarvestDeck::draw()
{
	// using the back of the vector as the "top" of the "pile"
	Tile* top = deck->back();
	deck->pop_back();
	this->shuffle();
	return top;
}

// Prints the whole deck
void deck::HarvestDeck::printDeck() 
{
	for (const auto& i : *deck) 
	{
		i->printInfo();
	}
}

// Runs test
void deck::HarvestDriver::run()
{
	HarvestDeck test;
	//test.printDeck();
	Tile* card = test.draw();
	card->printInfo();
	card->rotateLeft();
	card->printInfo();
	delete card;
	card = nullptr;
}


//////////////////////////////// Building deck

deck::Building::Building(const Building& building)
{
	//std::cout << cost << std::endl;
	cost = new int(*building.cost);
	resource = new Resource(*building.resource);
	isFaceDown = new bool(*building.isFaceDown);

}

deck::Building::~Building()
{
	//REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	
	delete cost;
	cost = nullptr;

	delete resource;
	resource = nullptr;

	delete isFaceDown;
	isFaceDown = nullptr;
}

// Prints the Building
void deck::Building::printInfo() const
{
	std::cout << "Cost: " << *cost << "\tResource: " << *resource << "\tFacedown: " << *isFaceDown << std::endl;
}

deck::BuildingDeck::~BuildingDeck()
{
	for (auto i : *deck)
	{
		delete i;
	}
	deck->clear();
	delete deck;
	deck = nullptr;
}


// Creates the deck
void deck::BuildingDeck::buildDeck()
{

	for (int res = Wheat; res <= Stone + 1 - 1; res++)
	{
		Resource resource = static_cast<Resource>(res);
		for (int cost = 1; cost <= 6; cost++)
		{
			for (int i = 0; i < 6; i++)
			{
				
				deck->push_back(new Building(cost, resource));
			}
		}
	}

	this->shuffle();
}

// Shuffles the deck
void deck::BuildingDeck::shuffle()
{
	//get current time and use it as a seed
	typedef std::chrono::high_resolution_clock gold_experience_requiem;
	auto ekko = gold_experience_requiem::now();
	
	auto seed = ekko.time_since_epoch().count();
	auto IOP = std::default_random_engine(seed);
	
	std::shuffle(deck->begin(), deck->end(), IOP);
}

// Draws a card
deck::Building* deck::BuildingDeck::draw()
{
	Building* top = deck->back();
	deck->pop_back();
	this->shuffle();
	return top;
}


// Prints the whole deck
void deck::BuildingDeck::printDeck()
{
	int count = 0;
	for (const auto& b : *deck)
	{
		b->printInfo();
		(count)++;
	}

	std::cout << "Building counter: " << count << std::endl;


}

// Runs test
void deck::BuildingDriver::run()
{
	BuildingDeck deck;

	deck.printDeck();

	std::vector<Building*> tempHand;

	tempHand.push_back(deck.draw());
	tempHand.push_back(deck.draw());
	tempHand.push_back(deck.draw());
	tempHand.push_back(deck.draw());
	tempHand.push_back(deck.draw());
	tempHand.push_back(deck.draw());

	for (auto i : tempHand)
	{
		i->printInfo();
	}
	for (auto i : tempHand)
	{
		delete i;
	}
	tempHand.clear();

}

//////////////////////////////// Hand


deck::Hand::Hand(HarvestDeck* HDeck, BuildingDeck* BDeck)
{
	_HarvestDeck = HDeck;
	_BuildingDeck = BDeck;
}

deck::Hand::~Hand()
{
	//TODO delete the hands

	for (auto i : *HarvestHand)
	{
		delete i;
	}
	
	for (auto i : *BuildingHand)
	{
		delete i;
	}

	delete HarvestHand;
	HarvestHand = nullptr;
	delete BuildingHand;
	BuildingHand = nullptr;

	delete _HarvestDeck;
	_HarvestDeck = nullptr;
	delete _BuildingDeck;
	_BuildingDeck = nullptr;
}

void deck::Hand::drawTile()
{
	HarvestHand->push_back(_HarvestDeck->draw());
}

void deck::Hand::drawBuilding()
{
	BuildingHand->push_back(_BuildingDeck->draw());
}


void deck::Hand::displayTiles()
{
	if (HarvestHand->size() > 0)
	{
		std::cout << "Your Tiles are: " << std::endl;
		for (auto i : *HarvestHand)
		{
			i->printInfo();
		}
	}
	else
		std::cout << "Empty Harvest Hand" << std::endl;
}

void deck::Hand::displayBuildings()
{
	if (BuildingHand->size() > 0) 
	{
		std::cout << "Your Buildings are: " << std::endl;
		for (auto i : *BuildingHand)
		{
			i->printInfo();
		}
	}
	else
		std::cout << "Empty Building Hand" << std::endl;
}

void deck::HandDriver::run()
{
	HarvestDeck* Hdeck = new HarvestDeck();
	BuildingDeck* Ddeck = new BuildingDeck();


	Hand test(Hdeck, Ddeck);

	test.drawTile();
	test.drawTile();
	test.drawTile();
	test.displayTiles();

	test.drawBuilding();
	test.drawBuilding();
	test.drawBuilding();
	test.displayBuildings();

	std::pair<int, deck::Tile*> picked = test.exchange();
	std::cout << "You picked location "<< picked.first << " and Tile : " << std::endl;
	picked.second->printInfo();

	delete picked.second;
	picked.second = nullptr;
}

std::pair<int, deck::Tile*> deck::Hand::exchange() {
	//have player select a Tile from list
	displayTiles();

	int location;
	std::cout << "Select a location" << std::endl;
	std::cin >> location;

	int selection;
	std::cout << "Select a tile" << std::endl;
	std::cin >> selection;

	Tile* selected = HarvestHand->at(selection);
	Tile* temp = HarvestHand->at(selection); // <- make sure this doesnt get deleted since contains pointer also used in HarvestHand
	//Last 2 getting deleted at end of current scope, since not pointers
	//might need assignment to make deep copy

	//is functional if remove the destructor for Tile, but leaves us with memory leaks

	HarvestHand->at(selection) = HarvestHand->back();
	HarvestHand->back() = temp;
	//HarvestHand->erase(HarvestHand->begin() + selection);
	HarvestHand->pop_back();
	displayTiles();
	
	std::pair<int, deck::Tile*> result = {location, selected};


	return result;	
}

deck::Building* deck::Hand::getBuilding(int location) 
{
	deck::Building* selected = BuildingHand->at(location);
	BuildingHand->erase(BuildingHand->begin() + location);
	return selected;
}