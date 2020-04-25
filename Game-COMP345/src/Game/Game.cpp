#include "Game.h"
#include "../Observer/GameObservers.h"
#include "../MainLoop/TurnSequence.h"
#include "../MainLoop/MainLoop.h"
#include "../GameStart/GameStart.h"
#include "../EndGame/EndGame.h"

void Game::playGame()
{
	std::cout << "Welcome to New Heaven" << std::endl;
	int numberOfPlayers;
	std::cout << "How many players?";
	std::cin >> numberOfPlayers;
	std::cout << "\n\n" << std::endl;
	
	maingame::MainLoop loop(numberOfPlayers);

	maingame::GameStart setGame;

	auto players = setGame.initPlayers(numberOfPlayers);
	loop.setupPlayerOrder(players);

	//Set Observable objects
	obs::Observable* subject = new obs::Observable();

	subject->setPlayers(loop.getPlayerQueue());
	//subject->setPlayers();
	obs::StatisticsObserver* statObserver = new obs::StatisticsObserver(subject);
	obs::TurnObserver* turnObserver = new obs::TurnObserver(subject);


	maingame::TurnSequence turnSeq;

	//For testing
	int test = 0;

	while (loop.getAnyPlayer()->getFreeSpaceLeftOnBoard() != 1)
	{
		loop.turnStart();

		//Turn Sequence
		turnSeq.playTurn(loop.getActivePlayer(),
			loop.getOtherPlayers(),
			numberOfPlayers - 1, subject);
		//loop.setResources();

		//Active player draws Buildings based on empty resource counters
		loop.drawBuildings();

		//Draw Harvest Tiles
		loop.drawHarvestTiles();

		subject->setState(obs::States::turnEnd);
		//Turn's end
		loop.turnEnd();

		//For testing
		/*if (test == 1)
			break;
		test++;*/
	}


	subject->setState(obs::States::done);

	//std::cout << loop.checkEndState() << std::endl;

	delete subject;
	subject = nullptr;

}
