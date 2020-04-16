#include "GameObservers.h"

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
	
	for (auto& p : model->getPlayers()) {

	}
}