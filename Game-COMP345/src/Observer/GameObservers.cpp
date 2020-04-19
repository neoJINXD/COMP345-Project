#include "GameObservers.h"
#include <string>
#include "../MainLoop/TurnSequence.h"
#include "../MainLoop/MainLoop.h"
#include "../GameStart/GameStart.h"

obs::Observable::~Observable()
{
	delete currentTurn;

	for (auto& v : *views) {
		
		delete v;
		v = nullptr;
	}

	delete views;
	views = nullptr;
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

void obs::Observable::setCurrentTurn(int curTurn) {
	
	*currentTurn = curTurn;
}

void obs::Observable::setResourceMarkers(std::map<Resource, int>* _counter)
{
	counter = _counter;
}

void obs::StatisticsObserver::update() {
	
	int i = 0;
	
	std::cout << "CURRENT GAME STATE:\n";
	for (auto &p : *model->getPlayers()) {
		auto player = p.second;

		std::cout << *player->getName()  << ":\t" << std::endl;

		//Print a user score
		std::cout << "COLONISTS:\t" << player->getCurrentScore() << ", ";
		
		//Print the number of buildings this player has on his village
		std::cout << "Placed Buildings:\t" << player->getBuildingCount();

		std::cout << std::endl;
		
		//if (i == 0) {
		//	//Only display this once since all players reference the same resourceCounter object
		//	player->displayResources();
		//}
	}
	//display the current resources
	std::cout << "STATE OF RESOURCES:\n";
	for (auto res : *model->getResourceMarkers()) {
		std::cout << "ID:" << res.first << ": " << res.second << std::endl;
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

	maingame::GameStart setGame;

	auto players = setGame.initPlayers(2);
	loop.setupPlayerOrder(players);
	auto testPlayer = players->at(0);

	//Set Observable objects
	obs::Observable* subject = new Observable();
	subject->setPlayers(loop.getPlayerQueue());
	subject->setCurrentTurn(1);
	//subject->setPlayers();
	obs::StatisticsObserver* statObserver = new StatisticsObserver(subject);
	
	maingame::TurnSequence turnSeq;
	for (int i = 0; i < 4; i++)
	{

		//loop.turnStart();

		//Turn Sequence
		//turnSeq.playTurn(loop.getActivePlayer(), );
		//loop.setResources();
		/*testPlayer->DrawBuilding();
		testPlayer->DrawBuilding();
		testPlayer->DrawBuilding();
		testPlayer->DrawBuilding();
		testPlayer->DrawBuilding();
		testPlayer->DrawShipment();
		testPlayer->DrawHarvestTile();
		testPlayer->DrawHarvestTile();
		testPlayer->DrawHarvestTile();
		testPlayer->DrawHarvestTile();
		testPlayer->DrawHarvestTile();*/
		//testPlayer->printHand();
		testPlayer->PlaceHarvestTile();
		testPlayer->CalculateResources();
		testPlayer->displayResources();
		testPlayer->BuildVillage();
	
		subject->setResourceMarkers(testPlayer->getResCounter()); // automatically notify all observers
		subject->notify();
		testPlayer->ResourceTracker(0,0,0,0);
		//Active player draws Buildings based on empty resource counters
		//loop.drawBuildings();
		

		//Draw Harvest Tiles
		//loop.drawHarvestTiles();

		


		//Turn's end
		//loop.turnEnd();

	}

	//std::cout << loop.checkEndState() << std::endl;

	//delete board;
	//board = nullptr;

	//delete hDeck;
	//hDeck = nullptr;

	//delete bDeck;
	//bDeck = nullptr;

	//delete count;
	//count = nullptr;

	delete subject;
	subject = nullptr;

}
