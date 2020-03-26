#include "Text.h"
#include <stdio.h>


ui::Text::Text(float x, float y, std::string _text, sf::Font* _font, RENDER_TYPE _type)
{
	font = _font;


	txt.setFont(*font);
	txt.setString(_text);
	txt.setFillColor(sf::Color::Black);
	txt.setCharacterSize(24);

	if (_type == TOP_LEFT)
		txt.setPosition(sf::Vector2f(x, y));
	else
		txt.setPosition(sf::Vector2f(x - txt.getGlobalBounds().width / 2.f, y - txt.getGlobalBounds().height / 2.f));

	//printf("x = %f, y = %f", txt.getGlobalBounds().width, txt.getGlobalBounds().height);
}

ui::Text::~Text() {}

void ui::Text::render(sf::RenderTarget* target)
{
	target->draw(txt);
}
