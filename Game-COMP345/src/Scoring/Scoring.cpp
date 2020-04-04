#include "Scoring.h"

int counter::ScoringCounter::countScore(VG::VGMap* village)
{


	int* ROWSSCORE = village->getRowScore();
	int* COLSSCORE = village->getColScore();

	int finalScore = 0;

	int i = 0;
	int j = 0;

	for (int row = 0; row < 6; row++)
	{
		int currentScore = 0;
		bool scoreCounts = true;
		bool doubleScore = true;
		for (int col = 1; col < 6; col++)
		{
			if (village->peekBuilding(row * 5 + col))
			{
				if (village->peekBuilding(row * 5 + col)->getFaceDown())
				{
					doubleScore = false;
				}
			}
			else
			{
				scoreCounts = false;
				break;
			}
		}
		

		if (scoreCounts)
		{
			if (doubleScore)
			{
				finalScore += 2 * ROWSSCORE[i];
			}
			else
			{
				finalScore += ROWSSCORE[i];
			}
		}
		i++;
	}

	for (int col = 1; col < 6; col++)
	{
		int currentScore = 0;
		bool scoreCounts = true;
		bool doubleScore = true;
		for (int row = 0; row < 6; row++)
		{
			if (village->peekBuilding(row * 5 + col))
			{
				if (village->peekBuilding(row * 5 + col)->getFaceDown())
					doubleScore = false;
			}
			else
			{
				scoreCounts = false;
				break;
			}
		}

		if (scoreCounts)
		{
			if (doubleScore)
			{
				finalScore += 2 * COLSSCORE[j];
			}
			else
			{
				finalScore += COLSSCORE[j];
			}
		}
		j++;
	}

	return finalScore;

}

void counter::ScoringDriver::run()
{
	VG::VGMap* village = new VG::VGMap("ScoreTest");

	village->placeBuilding(1, new deck::Building(6, Wheat));
	village->placeBuilding(6, new deck::Building(6, Wheat));
	village->placeBuilding(11, new deck::Building(6, Wheat));
	village->placeBuilding(12, new deck::Building(6, Wheat));
	village->placeBuilding(13, new deck::Building(6, Wheat));
	village->placeBuilding(14, new deck::Building(6, Wheat));
	village->placeBuilding(15, new deck::Building(6, Wheat));
	village->placeBuilding(16, new deck::Building(6, Wheat));
	village->placeBuilding(21, new deck::Building(6, Wheat));
	village->placeBuilding(26, new deck::Building(6, Wheat));


	counter::ScoringCounter counter;
	int result = counter.countScore(village);

	std::cout << "Score is: " << result<< std::endl;

	village->peekBuilding(1)->setFaceDown(true);

	result = counter.countScore(village);

	std::cout << "Score now is: " << result << std::endl;

	int rows[6] = {1, 1, 1, 1, 1, 1};
	int cols[5] = {1, 1, 1, 1, 1};

	village->setCustomScores(rows, cols);
	result = counter.countScore(village);

	std::cout << "Score now is: " << result << std::endl;





	delete village;
	village = nullptr;
}
