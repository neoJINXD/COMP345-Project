#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "UI.h"

namespace ui
{
	class Text
	{
	private:
		sf::Font* font;
		//std::string txt;
		sf::Text txt;
		//sf::RectangleShape bound;

	public:
		Text(float x, float y, std::string _text, sf::Font* _font, RENDER_TYPE _type = TOP_LEFT);
		~Text();

		//void update(const sf::Vector2f mousePos);
		void render(sf::RenderTarget* target);

		void setColor(sf::Color newColor) { txt.setFillColor(newColor); }
		void setCharSize(int newSize) { txt.setCharacterSize(newSize); }
	};

}

