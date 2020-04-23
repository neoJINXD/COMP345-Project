#include "GameObservers.h"
#include <string>
#include "../MainLoop/TurnSequence.h"
#include "../MainLoop/MainLoop.h"
#include "../GameStart/GameStart.h"
#include "../EndGame/EndGame.h"
//#include "../Helpers/StrConversion.h"
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

	delete gameState;


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

void obs::Observable::setCurrentPlayer(player::Player* player) 
{ 
	currentPlayer = player; 
	setState(States::turnStart);
}

void obs::Observable::placedBuilding(bool isBuildingPlayed)
{
	if (isBuildingPlayed) {
		
		setState(States::buildingPlaced);
	}
	else {
		
		setState(States::idle);
	}
}

void obs::Observable::setState(States state)
{
	*gameState = state;
	notify();
}

void obs::TurnObserver::update() {

	player::Player* currentPlayer = model->getCurrentPlayer();
	std::string name = *currentPlayer->getName();

	std::cout << "***TURN OBSERVER:\t";

	switch (model->getState()) {

	case obs::States::harvestPlaced:
		std::cout << name << " PLACED A HARVEST TILE ON THE GAMEBOARD!";
		break;

	case obs::States::buildingPlaced:
		std::cout << name << " PLACED A BUILDING ON THEIR VILLAGE!\n";
		break;

	case obs::States::turnStart:
		std::cout << name << " IS CURRENTLY PLAYING!";
		break;

	case obs::States::turnEnd:
		std::cout << "END OF " << name << "'s TURN!";
		break;

	case obs::States::wealthShared:
		std::cout << "SHARE THE WEALTH HAS BEEN CHOSEN!";
		break;

	case obs::States::idle:
		std::cout << "NO ACTION WAS PLAYED!";
		break;
	}
		
	std::cout << std::endl;
	
}

void obs::StatisticsObserver::update() {
	
	int i = 0;

	obs::States state = model->getState();

	if (state == obs::States::buildingPlaced || state == obs::States::harvestPlaced) {
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
		//display the current resources
		
		std::cout << "STATE OF RESOURCES:\n";
		if (model->getState() == States::buildingPlaced) {
			std::cout << "RESOURCES AFTER BUILDING PLACED\n";
		}
		for (auto res : *model->getCurrentPlayer()->getResCounter()) {
			std::cout << "" << resToStr(res.first) << ": " << res.second << std::endl;
		}
		std::cout << "\n" << std::endl;

		std::cout << "******STAT-OBSERVER END******\n";

	}

	//Winning condition
	if (state == obs::States::done) {
		std::cout << "STAT-OBSERVER - GAME FINISHED!\nWINNERS ARE..\n";
		std::vector<player::Player*>* players = new std::vector<player::Player*>();

		for (auto p : *model->getPlayers()) {
			players->push_back(p.second);
		}

		maingame::EndGame winnableLmao(players);
		auto winnerwinnerchickendinner = winnableLmao.computeScores();

		for (auto losers : winnerwinnerchickendinner) {
			std::cout << *losers->getName() << "\n";
		}

		delete players;
		players = nullptr;
		std::cout << "******STAT-OBSERVER END******\n";
	}
	
	
}

/*
	OBSERVER CLASSES IMPLEMENTATIONS START
*/

obs::TurnObserver::TurnObserver(Observable* _model)
{
	model = _model;
	model->attach(this);
}

obs::TurnObserver::~TurnObserver()
{
	model = nullptr;

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
/*
	OBSERVER CLASSES IMPLEMENTATIONS END
*/


void obs::ObserverDriver::run()
{
	const int numberOfPlayers = 2;

	maingame::MainLoop loop(numberOfPlayers);

	maingame::GameStart setGame;

	auto players = setGame.initPlayers(numberOfPlayers);
	loop.setupPlayerOrder(players);

	//Set Observable objects
	obs::Observable* subject = new Observable();

	subject->setPlayers(loop.getPlayerQueue());
	//subject->setPlayers();
	obs::StatisticsObserver* statObserver = new StatisticsObserver(subject);
	obs::TurnObserver* turnObserver = new TurnObserver(subject);
	

	maingame::TurnSequence turnSeq;
	//for (int i = 0; i < 4; i++)
	//{

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
		
		subject->setState(obs::States::turnEnd);
		//Turn's end
		loop.turnEnd();

	//}

	subject->setState(obs::States::done);

	//std::cout << loop.checkEndState() << std::endl;


	//delete subject;
	//subject = nullptr;

}
