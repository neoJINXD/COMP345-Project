#include "GameObservers.h"
#include <string>

void obs::Observable::attach(GameObserver* obs)
{
	views->push_back(obs);
}

void obs::Observable::notify()
{
	for (auto &view : *views) {
		view->update();
	}
}

void obs::StatisticsObserver::update() {
	
	std::cout << "Game Statistics:\n";
	for (auto &p : *model->getPlayers()) {
		auto player = p.second;
		std::cout << player->getName()  << " Info:" << std::endl;
		//Change the village print layout
		player->getVillage()->printGraph();

		//Current resource markers on this turn
		player->displayResources();
		
		
	}
}

obs::StatisticsObserver::StatisticsObserver(Observable* _model)
{
	model = _model;

}

obs::StatisticsObserver::~StatisticsObserver()
{
	model = nullptr;
}

void obs::ObserverDriver::run()
{
	

}
