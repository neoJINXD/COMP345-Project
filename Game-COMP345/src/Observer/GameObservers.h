#pragma once
#include <vector>
#include <map>
#include "../Player/Player.h"


namespace obs {
	class GameObserver
	{
	public:
		virtual void update() = 0;
	};

	class TurnObserver : public GameObserver {
	private:
		//Basically this is the subject my comrade. You use this object
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
		Observable* model;
	public:
		StatisticsObserver(Observable* _model);
		~StatisticsObserver();

		void GameObserver::update();
		//void setObservable(Observable* subject);
	};

	//Use this to share state information of the game
	class Observable {
		std::vector<GameObserver*>* views;

		// Model/State information
		int* currentTurn = new int(0);
		std::map<int, player::Player*>* players = nullptr;
		

	public:
		Observable() = default;
		~Observable();
		void attach(GameObserver* obs);
		void notify();

		void setPlayers(std::map<int, player::Player*>* playerQueue) { players = playerQueue; }
		void setCurrentTurn(int curTurn) { *currentTurn = curTurn; }
		player::Player* getCurrentPlayer();
		int getTurnState() { return *currentTurn; }
		inline std::map<int, player::Player*>* getPlayers() { return players; }


	};

	class ObserverDriver {

	public:
		void run();
	};
}