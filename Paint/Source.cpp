#include  "Header.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "PK3");

	CApp::Canvas canvas;

	canvas.generate("Rectangle");
	canvas.generate("Rectangle");
	auto obj = canvas.getShapes();

	for (const auto& el : obj)
	{
		el->update();
	}
		

	while (window.isOpen())
	{
		sf::Event event;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i position = sf::Mouse::getPosition();
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		window.clear();
		for (const auto& el : obj) //window.draw(shape);
		window.display();
	}

	return 0;
}