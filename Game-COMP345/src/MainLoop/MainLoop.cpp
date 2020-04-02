#include "MainLoop.h"

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
		std::cout << "no" << "bad boomer" << std::endl;
		exit(-404);
	}
}

maingame::MainLoop::MainLoop(int numberOfPlayer)
{
	init(numberOfPlayer);
}
