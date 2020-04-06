#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "../Player/Player.h"
#include <vector>
#include <list>


namespace maingame
{
	class EndGame
	{
	private:
		std::vector<player::Player*>* players;

		void init();

		int villageFreeSpace(player::Player* _player);
		
	public:
		EndGame(std::vector<player::Player*>* _players);
		~EndGame();


		std::vector<player::Player*> computeScores();

	};




	class EndGameDriver
	{
	private:
		void simulate(player::Player* _player);
	public:
		void run();
	};
}

