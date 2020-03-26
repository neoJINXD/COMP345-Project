#pragma once

#include "State.h"

namespace statesystem
{
	class EndState:
		public State
	{
	private:
		sf::RectangleShape bgd;

		void initKeybinds();
		void init();

	public:
		EndState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states);
		virtual ~EndState();

		void updateInputs(const float& dt);
		void quit();
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);
	};

}

