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
		player->getVillage()->printGraph();
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

