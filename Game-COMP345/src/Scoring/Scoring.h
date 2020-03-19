#pragma once
#ifndef _DEBUG
#define _DEBUG
#endif // !_DEBUG
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif
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


