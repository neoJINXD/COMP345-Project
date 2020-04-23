#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

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
	enum class States {
		buildingPlaced,
		harvestPlaced,
		wealthShared,
		turnStart,
		turnEnd,
		idle,
		done
	};
	class Observable {
	private:
		std::vector<GameObserver*>* views = new std::vector<GameObserver*>();

		// Model/State information
		std::map<int, player::Player*>* players = nullptr;
		player::Player* currentPlayer = nullptr;
		//std::map<Resource, int>* counter = nullptr;
		
		//Store possible states of game
	

		States* const gameState = new States(States::idle);

	public:
		Observable() = default;
		~Observable();

		//Updates and attaches observers to the view
		void attach(GameObserver* _obs);
		void notify();

		//Use these mutator methods to change the state which will automatically update the observers 
		void setPlayers(std::map<int, player::Player*>* playerQueue) { players = playerQueue; }
		void setCurrentPlayer(player::Player* player);
		void placedBuilding(bool isBuildingPlayed);
		void setState(States state);

		//Accessors for the observers to use to update themselves
		player::Player* getCurrentPlayer() { return currentPlayer; }
		inline std::map<int, player::Player*>* getPlayers() { return players; }
		//std::map<Resource, int>* getResourceMarkers() { return counter; }
		States getState() { return *gameState; }
	};

	class ObserverDriver {

	public:
		void run();
	};
}