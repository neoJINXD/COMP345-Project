#pragma once

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <vector>
#include <stack>
#include <SFML/Graphics.hpp>
#include "../Entities/Entity.h"
#include "../UI/Button.h"
#include "../UI/Text.h"

namespace statesystem 
{
	class State
	{
	private:

	protected:
		sf::Font font;

		std::map<std::string, ui::Button*> buttons;
		std::map<std::string, ui::Text*> texts;

		std::stack<State*>* states;
		bool ended;
		sf::RenderWindow* win;
		std::vector<sf::Texture*> textures;

		std::map<std::string, int>* validKeys;
		std::map<std::string, int> keybinds;

		sf::Vector2i mousePosScreen;
		sf::Vector2i mousePosWindow;
		sf::Vector2f mousePosView;

		virtual void initKeybinds() = 0;

	public:
		State(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states);
		virtual ~State();

		const bool& getEnd() const;
		void checkEnd();

		virtual void updateInputs(const float& dt) = 0;
		virtual void updateMousePos();
		virtual void quit() = 0;
		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = nullptr) = 0;

		void killGame();
	};
}

