#include "GameObservers.h"
#include <string>
#include "../MainLoop/TurnSequence.h"
#include "../MainLoop/MainLoop.h"
#include "../GameStart/GameStart.h"

obs::Observable::~Observable()
{

	players = nullptr;
	currentPlayer = nullptr;

	for (auto& v : *views) {
		
		delete v;
		v = nullptr;
	}

	delete views;
	views = nullptr;

	delete isBuildingPlaced;
	isBuildingPlaced = nullptr;
	
	delete isHarvestPlaced;
	isHarvestPlaced = nullptr;

	delete turnStart;

	delete turnEnd;
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


void obs::Observable::setResourceMarkers(std::map<Resource, int>* _counter)
{
	counter = _counter;
}

void obs::TurnObserver::update() {

	player::Player* currentPlayer = model->getCurrentPlayer();
	std::string name = *currentPlayer->getName();
	bool stateChanged = true;
	/*
		For future, can potentially split these if into their own observers observers.
	*/
	//Display whos turn it is and only once.
	std::cout << "------TURN OBSERVER------" << std::endl;
	if (model->isTurnStart()|| model->isWealthShared()) {
		
		if (model->isWealthShared()) {
			std::cout << "SHARE THE WEALTH HAS BEEN CHOSEN!\n";
		}

		std::cout << name << " IS NOW PLAYING!" << std::endl;
		model->setTurnStart(false); // resets state
		stateChanged = true;
	}
	
	//Notify console if player placed a harvest tile
	if (model->getBoardState()) {
		std::cout << name << " PLACED A HARVEST TILE ON THE GAMEBOARD!\n";
		model->setGBChange(false); // resets state
		stateChanged = true;
	}

	//Notify if player placed a building
	if (model->getVillageState()) {
		std::cout << name << " PLACED A BUILDING ON THEIR VILLAGE!\n";
		stateChanged = true;
	
	}

	if (model->isTurnEnd()) {
		std::cout << "END OF " << name << "'s TURN!" << std::endl;
		model->setTurnEnd(false);
		stateChanged = true;
	}

	if (!stateChanged) {
		std::cout << "AN ACTION HAPPENED BUT NO ONE CAME...";
	}
		
	std::cout << "------END TURN OBSERVER------\n" << std::endl;
	
}

void obs::StatisticsObserver::update() {
	
	int i = 0;

	//Only print this out if a building was placed
	std::cout << "\n-------STAT-OBSERVER - CURRENT GAME STATE:-------\n\n";
	std::cout << *model->getCurrentPlayer()->getName() << " IS CURRENTLY PLAYING!\n\n";
	for (auto& p : *model->getPlayers()) {
		auto player = p.second;

		std::cout << *player->getName() << ":\t";

		//Print a user score
		std::cout << "COLONISTS:\t" << player->getCurrentScore() << ", ";

		//Print the number of buildings this player has on his village
		std::cout << "Placed Buildings:\t" << player->getBuildingCount();

		std::cout << std::endl;

	}
	std::cout << "\n" << std::endl;
	if (model->getVillageState() || model->getBoardState()) {
		//display the current resources
		
		std::cout << "STATE OF RESOURCES:\n";
		if (model->getVillageState()) {
			std::cout << "RESOURCES AFTER BUILDING PLACED\n";
		}
		for (auto res : *model->getResourceMarkers()) {
			std::cout << "ID:" << res.first << ": " << res.second << std::endl;
		}
		std::cout << "\n" << std::endl;
		
	}
	std::cout << "-----END OF STAT_OBSERVER-----\n" << std::endl;
	
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
	const int numberOfPlayers = 2;

	maingame::MainLoop loop(numberOfPlayers);

	maingame::GameStart setGame;

	auto players = setGame.initPlayers(numberOfPlayers);
	loop.setupPlayerOrder(players);
	auto testPlayer = players->at(0);

	//Set Observable objects
	obs::Observable* subject = new Observable();

	subject->setPlayers(loop.getPlayerQueue());
	//subject->setPlayers();
	obs::StatisticsObserver* statObserver = new StatisticsObserver(subject);
	obs::TurnObserver* turnObserver = new TurnObserver(subject);
	

	maingame::TurnSequence turnSeq;
	for (int i = 0; i < 4; i++)
	{

		loop.turnStart();

		//Turn Sequence
		turnSeq.playTurn(loop.getActivePlayer(), 
			loop.getOtherPlayers(), 
			numberOfPlayers-1, subject);
		//loop.setResources();

	
		//subject->setResourceMarkers(testPlayer->getResCounter()); // automatically notify all observers
		//subject->notify();
		//testPlayer->ResourceTracker(0,0,0,0);
		//Active player draws Buildings based on empty resource counters
		loop.drawBuildings();
		

		//Draw Harvest Tiles
		loop.drawHarvestTiles();

		
		//Mew
		subject->setTurnEnd(true);
		subject->notify();
		//Turn's end
		loop.turnEnd();

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

obs::TurnObserver::TurnObserver(Observable* _model)
{
	model = _model;
	model->attach(this);
}

obs::TurnObserver::~TurnObserver()
{
	model = nullptr;

}
