#include "../TieBreaker/TieBreaker.h"


void Breaker::TieBreak::Break(VG::VGMap* village)
{
	counter::ScoringCounter score;
	score.countScore(); // run the CountStore()
	int bestPlayer = 0; //save the best player
	int maxScore = 0; //save the max score

	//if there is no tie winner is:
	for (int i = 0; i < N; i++) {
		if (Players[i].score > maxScore)
		{
			maxScore = Players[i].score;
			bestPlayer = i;
		}
	}
	std::Cout << "If there is no tie, the winner is: " << Players[bestPlayer] << std::endl;

	// if there is a tie:

	for (int i = 0; i < N; i++)
	{
		Players[i].score = Score[i]; // store the score in vector Score<int>

	}

	for (int i = 0; i < M; i++)
	{
		std::sort(Score.begin(), Score.end()); // sort the list of score of each player
	}

	

}