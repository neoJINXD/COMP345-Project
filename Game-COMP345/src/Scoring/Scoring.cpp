#include "Scoring.h"

int counter::ScoringCounter::countScore(VG::VGMap* village)
{
	int rows[6] = { 1,1,1,1,1,1 };
	int cols[5] = { 1,1,1,1,1 };

	//int ROWSSCORE[6] = {6,5,4,3,2,1};
	//int COLSSCORE[5] = {5,4,3,4,5};

	int* ROWSSCORE = village->getRowScore();
	int* COLSSCORE = village->getColScore();

	for (int row = 0; row < 6; row++)
	{
		for (int col = 1; col < 6; col++)
		{
			
			if (!village->peekBuilding(row*5+col)) //if is null
			{
				rows[row] = 0;
				cols[col-1] = 0;
			}

		}
	}


	int score = 0;

	for (int i = 0; i < 6; i++)
	{
		score += ROWSSCORE[i] * rows[i];
	}

	for (int i = 0; i < 5; i++)
	{
		score += COLSSCORE[i] * cols[i];
	}


	return score;

}

void counter::ScoringDriver::run()
{
	VG::VGMap* village = new VG::VGMap("ScoreTest");


	village->placeBuilding(1, new deck::Building(6, Wheat));
	village->placeBuilding(12, new deck::Building(6, Wheat));
	village->placeBuilding(13, new deck::Building(6, Wheat));
	village->placeBuilding(15, new deck::Building(6, Wheat));
	village->placeBuilding(14, new deck::Building(6, Wheat));
	village->placeBuilding(6, new deck::Building(6, Wheat));
	village->placeBuilding(11, new deck::Building(6, Wheat));
	village->placeBuilding(16, new deck::Building(6, Wheat));
	village->placeBuilding(21, new deck::Building(6, Wheat));
	village->placeBuilding(26, new deck::Building(6, Wheat));

	counter::ScoringCounter counter;
	int result = counter.countScore(village);

	std::cout << "Score is: " << result<< std::endl;

	int rows[6] = {1, 1, 1, 1, 1, 1};
	int cols[5] = {1, 1, 1, 1, 1};

	village->setCustomScores(rows, cols);
	result = counter.countScore(village);

	std::cout << "Score now is: " << result << std::endl;

	delete village;
	village = nullptr;
}
