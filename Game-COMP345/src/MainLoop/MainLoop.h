#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <list>
#include <iostream>
#include "../Player/Player.h"

namespace maingame
{
	class MainLoop
	{
	private: 
		//MainLoop() {}

		std::list<player::Player*>* queue;
		player::Player* activePlayer;

		int freeTiles;
		void init(int numberOfPlayer);

	public:
		MainLoop(int numberOfPlayer);
		~MainLoop();
		

	};



	class MainLoopDriver
	{
	public:
		void run();
	};
}