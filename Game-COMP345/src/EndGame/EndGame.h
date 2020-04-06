#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "../Player/Player.h"
#include <vector>

namespace maingame
{
	class EndGame
	{
	private:
		std::vector<player::Player*>* players;

		void init();
		
	public:
		EndGame() : players(new std::vector<player::Player*>()) { init(); }
		~EndGame();


		std::vector<player::Player*> computeScores();



	};




	class EndGameDriver
	{
	public:
		void run();
	};
}

