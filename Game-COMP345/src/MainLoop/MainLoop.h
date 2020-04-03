#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <map>
#include <iostream>
#include "../Player/Player.h"

namespace maingame
{
	class MainLoop
	{
	private: 
		//MainLoop() {}

		std::map<int, player::Player*>* queue;
		player::Player* activePlayer;
		int currentPlayer;

		int freeTiles;
		void init(int numberOfPlayer);

	public:
		MainLoop(int numberOfPlayer);
		~MainLoop();

		void setupPlayerOrder(player::Player* p1, player::Player* p2, player::Player* p3, player::Player* p4);
		void start();
		void end();
	};



	class MainLoopDriver
	{
	public:
		void run();
	};
}