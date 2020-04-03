#include "MainLoop.h"

#include "../GBMaps/GBMap.h"
#include "../Resources/Resources.h"
#include "../Engine/Utilities/Helpers.h"

void maingame::MainLoop::init(int numberOfPlayer)
{
	// finding number of empty tiles the board will start with
	switch (numberOfPlayer)
	{
	case 2:
		freeTiles = 5 * 5;
		break;
	case 3:
		freeTiles = 5 * 7;
		break;
	case 4:
		freeTiles = 7 * 7 - 4;
		break;
	default:
		std::cout << "ERROR: INVALID NUMBER OF PLAYERS - MAINLOOP.CPP" << std::endl;
		exit(-404);
	}

	currentPlayer = 0;
	nbPlayers = numberOfPlayer;
}

maingame::MainLoop::MainLoop(int numberOfPlayer)
{
	init(numberOfPlayer);
	queue = new std::map<int, player::Player*>();
	activePlayer = nullptr;
}

maingame::MainLoop::~MainLoop()
{
	for (auto i : *queue)
	{
		delete i.second;
	}

	queue->clear();
	delete queue;
	queue = nullptr;
}

void maingame::MainLoop::setupPlayerOrder(player::Player* p1, player::Player* p2, player::Player* p3, player::Player* p4)
{
	queue->emplace(0, p1);
	queue->emplace(1, p2);
	queue->emplace(2, p3);
	queue->emplace(3, p4);
	
}

void maingame::MainLoop::turnStart()
{
	activePlayer = queue->at(currentPlayer);
}

void maingame::MainLoop::turnEnd()
{
	currentPlayer = (currentPlayer + 1) % nbPlayers;
}

bool maingame::MainLoop::checkEndState()
{
	return freeTiles == 1;
}



void maingame::MainLoopDriver::run()
{
	MainLoop loop(4);
	
	GB::GBMap* board = new GB::GBMap(4);
	deck::BuildingDeck* bDeck = new deck::BuildingDeck();
	deck::HarvestDeck* hDeck = new deck::HarvestDeck();

	std::string p1 = "p1";
	std::string p2 = "p2";
	std::string p3 = "p3";
	std::string p4 = "p4";

	loop.setupPlayerOrder(
		new player::Player(&p1, board, hDeck, bDeck),
		new player::Player(&p2, board, hDeck, bDeck),
		new player::Player(&p3, board, hDeck, bDeck),
		new player::Player(&p4, board, hDeck, bDeck)
		);
	



	loop.turnStart();



	loop.turnEnd();



	std::cout << loop.checkEndState() << std::endl;

	delete board;
	board = nullptr;

	delete hDeck;
	hDeck = nullptr;

	delete bDeck;
	bDeck = nullptr;
}