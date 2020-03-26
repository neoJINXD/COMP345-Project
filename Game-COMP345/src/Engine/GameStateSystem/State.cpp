#include "State.h"

statesystem::State::State(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states)
{
	win = _win;
	ended = false;
	validKeys = _validKeys;
	states = _states;

	if (!font.loadFromFile("./src/Files/fonts/Blacklisted.ttf"))
	{
		printf("ERROR::Stat - FAILED TO LOAD FONT");
		exit(-1);
	}

}

statesystem::State::~State()
{
}

const bool& statesystem::State::getEnd() const
{
	return ended;
}

void statesystem::State::checkEnd()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE"))))
	{
		//ended = true;
		killGame();
	}
}

void statesystem::State::updateMousePos()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*win);
	mousePosView = win->mapPixelToCoords(sf::Mouse::getPosition(*win));
}

void statesystem::State::killGame()
{
	win->close();
}

