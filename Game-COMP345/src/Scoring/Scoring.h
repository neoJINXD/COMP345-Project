#pragma once
#include "../VGMaps/VGMap.h"
#include <algorithm>
#include <vector>

namespace counter
{
	class ScoringCounter
	{
	public:
		int countScore(VG::VGMap* village);
	};


	class ScoringDriver
	{
	public:
		void run();
	};
}


