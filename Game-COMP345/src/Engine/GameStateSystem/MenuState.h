#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "State.h"

namespace statesystem
{
	class MenuState :
		public State
	{
	private:
		sf::RectangleShape bgd;

		void initKeybinds();
		void init();

	public:
		MenuState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states);
		virtual ~MenuState();


		void updateInputs(const float& dt);
		void quit();
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);

	};

}

