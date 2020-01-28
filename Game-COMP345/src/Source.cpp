#include <SFML/Graphics.hpp>
#include "GBMaps/GBMap.h";
#include "VGMaps/VGMap.h";


int main()
{

	VG::VGMap vgTest;
	GB::GBMap gbTest;

	GB::GBMapDriver test;

	test.run();

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

	system("pause");

	return 0;
}