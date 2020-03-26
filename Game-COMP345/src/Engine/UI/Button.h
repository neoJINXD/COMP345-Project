#pragma once


#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <SFML/Graphics.hpp>
#include "UI.h"

namespace ui 
{


	class Button
	{
	private:
		sf::RectangleShape button;
		sf::Font* font;
		sf::Text txt;

		sf::Color normal;
		sf::Color highlighted;
		sf::Color click;

		unsigned short state;

	public:
		Button(
			float x, 
			float y, 
			float width, 
			float height, 
			sf::Font* _font, 
			std::string _text,
			RENDER_TYPE _type = TOP_LEFT
			);
		~Button();

		const bool isPressed() const;

		void update(const sf::Vector2f mousePos);

		void render(sf::RenderTarget* target);

		void setTransparent();
	};

}

