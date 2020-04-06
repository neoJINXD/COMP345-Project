#pragma once
#include "../GBMaps/GBMap.h"
#include "../VGMaps/VGMap.h"
#include "../Player/Player.h"
#include "../Resources/Resources.h"
#include "../Scoring/Scoring.h"
#include <vector>
#include <iostream>
#include <string>
const unsigned int N = 4;
vector<player::Player> Players[N]; // 4 players
Players[0].name = "Anik";
Players[1].name = "Hieu";
Players[2].name = "Minh";
Players[3].name = "Josh";

const unsigned int M = 4;
vector<int> Score[M]; //int vector to keep track of each player's score


namespace Breaker
{
	class TieBreak
	{
	public:
		void Break(VG::VGMap* village); // Tie Breaker function
	};
}