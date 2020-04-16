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
		Observable* model;
		int currentTurn;

	public:
		TurnObserver(Observable* _model);
		~TurnObserver();

		/*
		Print out current player information
		
		*/
		void GameObserver::update();
	};

	class StatisticsObserver : public GameObserver {
	private:
		Observable* model;
	public:
		StatisticsObserver(Observable* _model);
		~StatisticsObserver();
		void isWinCondition();
		void GameObserver::update();
		//void setObservable(Observable* subject);
	};

	//Use this to share state information of the game
	class Observable {
		std::vector<GameObserver*>* views;

		// Model/State information
		int* currentTurn;
		std::map<int, player::Player*>* players;
		

	public:
		Observable();
		~Observable();
		void attach(GameObserver* obs);
		void notify();

		void setState();
		player::Player* getCurrentPlayer();
		void getTurnState();
		inline std::map<int, player::Player*>* getPlayers() { return players; }


	};

	class ObserverDriver {

	public:
		void run();
	};
}