#pragma once
#include <vector>
#include <map>
#include "../Player/Player.h"


namespace obs {

	class Observable;

	class GameObserver
	{
	public:
		virtual void update() = 0;
	};

	class TurnObserver : public GameObserver {
	private:
		//Dependent functionality
		Observable* model;
		int currentTurn;

	public:
		TurnObserver(Observable* _model);
		~TurnObserver();

		/*
		Print out current active player name information
		i) Show the increase of resource markers when harvest tile is played
		ii) Show what the current player decided to do, place building etc
		iii) Update village building count of player
		*/
		void GameObserver::update();
	};

	class StatisticsObserver : public GameObserver {
	private:

		//Dependent functionality
		Observable* model;
	public:
		StatisticsObserver(Observable* _model);
		~StatisticsObserver();

		void GameObserver::update();
		//void setObservable(Observable* subject);
	};

	//Use this to share state information of the game
	class Observable {
	private:
		std::vector<GameObserver*>* views = new std::vector<GameObserver*>();

		// Model/State information
		int* currentTurn = new int(0);
		std::map<int, player::Player*>* players = nullptr;
		bool* isBuildingPlaced;
		//bool* isHarvestTilePlaced;

	public:
		Observable() = default;
		~Observable();

		//Updates and attaches observers to the view
		void attach(GameObserver* obs);
		void notify();

		//Use these mutator methods to change the state which will automatically update the observers 
		void setPlayers(std::map<int, player::Player*>* playerQueue) { players = playerQueue; }
		void setCurrentTurn(int curTurn);

		//Accessors for the observers to use to update themselves
		player::Player* getCurrentPlayer();
		int getTurnState() { return *currentTurn; }
		inline std::map<int, player::Player*>* getPlayers() { return players; }


	};

	class ObserverDriver {

	public:
		void run();
	};
}