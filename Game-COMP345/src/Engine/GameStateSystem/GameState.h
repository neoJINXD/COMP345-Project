#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include "State.h"


namespace statesystem
{
	class GameState : public State
	{
	private:
		entity::Entity player;

		void initKeybinds();

	public:
		GameState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states);
		virtual ~GameState();


		void updateInputs(const float& dt);
		void quit();
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);
	};

}

