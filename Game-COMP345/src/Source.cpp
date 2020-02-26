
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../HarvestDeck.h"
#include "../BuildingDeck.h"

int main()
{
	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Cyan);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/


	deck::HarvestDriver test1;
	test1.run();


	

	deck::BuildingDriver test2;
	test2.run();

	system("pause");

	return 0;
}