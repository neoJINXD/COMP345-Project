#include "EndGame.h"
#include <list>
#include "../Scoring/Scoring.h"

void maingame::EndGame::init()
{
	players = new std::vector<player::Player*>();
}

int maingame::EndGame::villageFreeSpace(player::Player* _player)
{
	//Gets free space available in the village
	return 0;
}

maingame::EndGame::EndGame(std::vector<player::Player*>* _players)
{
	init();
	for (auto i : *_players)
	{
		players->push_back(i);
	}
}

maingame::EndGame::~EndGame()
{
	//for (auto i : *players)
	//{
	//	delete i;
	//}

	players->clear();
	delete players;
	players = nullptr;
}

std::vector<player::Player*> maingame::EndGame::computeScores()
{

	counter::ScoringCounter counter;
	std::vector<player::Player*> p = *players;
	std::vector<player::Player*> p2; //create this to store the first round
	std::vector<player::Player*> p3; //create this to store the second round
	std::vector<player::Player*> p4; //create this to store the last round

	int max1 = 0; // keep track of first round
	int minSpace = 404; // keep track of second round
	int minHand = 404; // keep track of third round

	int win1 = 0; // keep track if there's a winner first round
	int win2 = 0; //keep track if there's a winner second round
	int win3 = 0; //keep track if there's a winner second round

	//-----------------------------------------------------------------------------

	//First round checks - each player scores
	for (auto i : p)
	{
		if (counter.countScore(i->getVillage()) > max1)
		{
			// if theres a max score, it will be added to max
			max1 = counter.countScore(i->getVillage()); 
		}
	}
	//How many people with top score
	for (auto i : p)
	{
		if (counter.countScore(i->getVillage()) == max1)  // check how many players receive the maximum score
		{
			p2.push_back(i);
			win1++;
		}
	}

	if (win1 == 1) // if only 1 has top score then we have a winner
	{
		return p2;
		//std::vector<player::Player*> result;
		//result.push_back(p2.at(0));
		//return result; //display the winner, only one in the second vector
	}


	//-----------------------------------------------------------------------------

	else // more than 1 people with top scores, Second round test based on free space in village
	{
		for (auto i : p2) // check who has the least spaces left
		{
			if (i->getFreeSpace() < minSpace) // winner should be the player with lowest free space
			{
				minSpace = i->getFreeSpace(); // the max becomes the number of buildings
			}
		}

		for (auto i : p2)
		{
			if (i->getFreeSpace() == minSpace)  // check how many players receive the maximum score
			{
				p3.push_back(i);
				win2++; //increment 
			}
		}

		if (win2 == 1) // if 1 then we have a  winner
		{
			return p3;
			//std::vector<player::Player*> result;
			//result.push_back(p3.at(0));
			//return result; //display the winner, only one in the second vector
		}

		//-----------------------------------------------------------------------------

		else // more than 1, Third round test based on number of buildings in the hand
		{
			for (auto i : p3) // gets the lowest numbers of buildings in hand
			{
				if (i->getBuildingHandSize() < minHand) // Iterate
				{
					minHand = i->getBuildingHandSize();
				}
			}

			for (auto i : p3)
			{
				if (i->getBuildingHandSize() == minHand)
				{
					p4.push_back(i);
					win3++;// increment
				}
			}

			if (win3 == 1) // if 1 then we have a  winner
			{
				std::vector<player::Player*> result;
				result.push_back(p4.at(0));
				return result; //display the winner, only one in the second vector
			}
			else
			{
				//-----------------------------------------------------------------------------

				std::vector<player::Player*> result; //interate through the last vector
				for (auto i : p4)
				{
					result.push_back(i);
				}
				return result; //display the name of all winners
			}

		}
	}


}

void maingame::EndGameDriver::simulate(player::Player* _player)
{
}

void maingame::EndGameDriver::run()
{
	std::vector<player::Player*>* players = new std::vector<player::Player*>();

	GB::GBMap* map = new GB::GBMap(4);
	deck::HarvestDeck* hDeck = new deck::HarvestDeck();
	deck::BuildingDeck* bDeck = new deck::BuildingDeck();


	players->push_back(new player::Player(new std::string("p1"), map, hDeck, bDeck));
	players->push_back(new player::Player(new std::string("p2"), map, hDeck, bDeck));
	players->push_back(new player::Player(new std::string("p3"), map, hDeck, bDeck));
	players->push_back(new player::Player(new std::string("p4"), map, hDeck, bDeck));

	counter::ResourceCounter* count = new counter::ResourceCounter();
	players->at(0)->setCounterSystem(count);
	players->at(1)->setCounterSystem(count);
	players->at(2)->setCounterSystem(count);
	players->at(3)->setCounterSystem(count);

	simulate(players->at(0));

	EndGame end(players);

	//everyone is in a tie
	auto bots = end.computeScores();

	if (bots.size() == 1)
	{
		std::cout << "There is one winner and it is :" << *bots.at(0)->getName() << std::endl;
	}
	else
	{
		std::cout << "Despite all the tie breakers, there is still a tie between: " << std::endl;
		for (auto i : bots)
		{
			std::cout << *i->getName() << std::endl;
		}
	}


	//p3 has1 building in hand, so three way tie with the others
	players->at(2)->DrawBuilding();

	bots = end.computeScores();

	if (bots.size() == 1)
	{
		std::cout << "There is one winner and it is :" << *bots.at(0)->getName() << std::endl;
	}
	else
	{
		std::cout << "Despite all the tie breakers, there is still a tie between: " << std::endl;
		for (auto i : bots)
		{
			std::cout << *i->getName() << std::endl;
		}
	}

	//p1 has a building built, so he should be the winner
	//console user picks location for test
	players->at(0)->DrawBuilding();
	players->at(0)->BuildVillage();
	bots = end.computeScores();

	if (bots.size() == 1)
	{
		std::cout << "There is one winner and it is :" << *bots.at(0)->getName() << std::endl;
	}
	else
	{
		std::cout << "Despite all the tie breakers, there is still a tie between: " << std::endl;
		for (auto i : bots)
		{
			std::cout << *i->getName() << std::endl;
		}
	}


	delete players;
	players = nullptr;

	delete map;
	map = nullptr;

	delete hDeck;
	hDeck = nullptr;

	delete bDeck;
	bDeck = nullptr;

	delete count;
	count = nullptr;
}