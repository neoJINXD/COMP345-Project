#pragma once
#include "../Player/Player.h"

namespace maingame
{
	class TurnSequence
	{
	private:
	public:
		TurnSequence() {}
		void playTurn(player::Player* player);
	};


	class TurnSequenceDriver
	{
	public:
		void run();
	};

}

