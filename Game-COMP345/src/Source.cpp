
#include <SFML/Graphics.hpp>
#include<iostream>
#include "../HarvestDeck.h"
<<<<<<< HEAD


=======
#include "../BuildingDeck.h"
>>>>>>> 04d97acdaf9dadf25b1dec56d2341d5a2e07d4d9
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

<<<<<<< HEAD
	deck::HarvestDriver test;
	test.run();

	system("pause");
	
=======
	deck::BuildingDriver test;
	test.run();

	system("pause");
>>>>>>> 04d97acdaf9dadf25b1dec56d2341d5a2e07d4d9
	return 0;
}