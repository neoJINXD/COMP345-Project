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

	};

	//Use this to share state information of the game
	/*
	procedure:
	- create and attach observers to observable / subject
	- set the state of the observables
	- once all states are set notify the observers
	*/
	class Observable {
	private:
		std::vector<GameObserver*>* views = new std::vector<GameObserver*>();

		// Model/State information
		std::map<int, player::Player*>* players = nullptr;
		player::Player* currentPlayer = nullptr;
		bool* isBuildingPlaced = new bool(true);
		bool* isHarvestTilePlaced = new bool(true);
		bool* isTurnStart = new bool(true);
		bool* isTurnEnd = new bool(false);
		std::map<Resource, int>* counter;


	public:
		Observable() = default;
		~Observable();

		//Updates and attaches observers to the view
		void attach(GameObserver* _obs);
		void notify();

		//Use these mutator methods to change the state which will automatically update the observers 
		void setPlayers(std::map<int, player::Player*>* playerQueue) { players = playerQueue; }
		void setResourceMarkers(std::map<Resource, int>* _counter);
		inline void setCurrentPlayer(player::Player* player) { currentPlayer = player; }
		void setVillageChange(bool villageChange) { *isBuildingPlaced = villageChange; }


		//Accessors for the observers to use to update themselves
		player::Player* getCurrentPlayer() { return currentPlayer; }
		inline std::map<int, player::Player*>* getPlayers() { return players; }
		std::map<Resource, int>* getResourceMarkers() { return counter; }
		bool isBuildingPlaced() { return *isBuildingPlaced; }

	};

	class ObserverDriver {

	public:
		void run();
	};
}