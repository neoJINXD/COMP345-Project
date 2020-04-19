#include "GameObservers.h"
#include <string>
#include "../MainLoop/TurnSequence.h"
#include "../MainLoop/MainLoop.h"

obs::Observable::~Observable()
{
	delete currentTurn;
}

void obs::Observable::attach(GameObserver* obs)
{
	views->push_back(obs);
}

void obs::Observable::notify()
{
	for (auto &view : *views) {
		view->update();
	}
}

void obs::StatisticsObserver::update() {
	
	int i = 0;
	
	std::cout << "Current Game Statistics:\n";
	for (auto &p : *model->getPlayers()) {
		auto player = p.second;

		//Current resource markers on this turn
		if (i == 0) {
			//Only display this once since all players reference the same resourceCounter object
			player->displayResources();
		}

		std::cout << player->getName()  << " Info:" << std::endl;
		std::cout << "Colonists:\t" << player->getCurrentScore() << "\n";
		//Change the village print layout
		player->getVillage()->printGraph();

		std::cout << std::endl;
		
	}
}

obs::StatisticsObserver::StatisticsObserver(Observable* _model)
{
	
	model = _model;
	model->attach(this);

}

obs::StatisticsObserver::~StatisticsObserver()
{
	model = nullptr;
}

void obs::ObserverDriver::run()
{
	
	maingame::MainLoop loop(4);

	GB::GBMap* board = new GB::GBMap(4);
	deck::BuildingDeck* bDeck = new deck::BuildingDeck();
	deck::HarvestDeck* hDeck = new deck::HarvestDeck();

	//names of players
	std::string* p1 = new std::string("p1");
	std::string* p2 = new std::string("p2");
	std::string* p3 = new std::string("p3");
	std::string* p4 = new std::string("p4");

	player::Player* testPlayer = new player::Player(p1, board, hDeck, bDeck);
	player::Player* testPlayer2 = new player::Player(p2, board, hDeck, bDeck);
	player::Player* testPlayer3 = new player::Player(p3, board, hDeck, bDeck);
	player::Player* testPlayer4 = new player::Player(p4, board, hDeck, bDeck);

	counter::ResourceCounter* count = new counter::ResourceCounter();
	testPlayer->setCounterSystem(count);
	testPlayer2->setCounterSystem(count);
	testPlayer3->setCounterSystem(count);
	testPlayer4->setCounterSystem(count);


	loop.setupPlayerOrder(
		testPlayer,
		testPlayer2,
		testPlayer3,
		testPlayer4
	);

	//Set Observable objects
	obs::Observable* subject = new Observable();
	subject->setPlayers(loop.getPlayerQueue());
	subject->setCurrentTurn(1);
	//subject->setPlayers();
	obs::StatisticsObserver* statObserver = new StatisticsObserver(subject);
	
	maingame::TurnSequence turnSeq;
	for (int i = 0; i < 4; i++)
	{

		loop.turnStart();

		//Turn Sequence
		//turnSeq.playTurn(loop.getActivePlayer(), );
		//loop.setResources();

		//Active player draws Buildings based on empty resource counters
		loop.drawBuildings();
		

		//Draw Harvest Tiles
		loop.drawHarvestTiles();

		


		//Turn's end
		loop.turnEnd();

	}

	//std::cout << loop.checkEndState() << std::endl;

	delete board;
	board = nullptr;

	delete hDeck;
	hDeck = nullptr;

	delete bDeck;
	bDeck = nullptr;

	delete count;
	count = nullptr;


}
