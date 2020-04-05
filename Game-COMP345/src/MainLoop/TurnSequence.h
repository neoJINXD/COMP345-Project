#pragma once
#include "../Player/Player.h"

namespace maingame
{
	class TurnSequence
	{
	private:
		TurnSequence() {}
	public:
		void playTurn(player::Player* player);
	};


	class TurnSequenceDriver
	{
	public:
		void run();
	};

}

