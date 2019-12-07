#include  "Header.h"

int main()
{
	CApp::Canvas * canvas = new CApp::Canvas;

	sf::RenderWindow window(sf::VideoMode(500, 500), "PK3");
	window.clear(sf::Color::Black);
	window.display();
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type) window.clear(sf::Color::Black);
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::Resized)
			{
				window.setView(sf::View(sf::FloatRect(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));
				canvas->refresh(window);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Rectangle test only
			{
				canvas->generateShape(new CApp::Rectangle(sf::Mouse::getPosition(window)));
				auto shape = canvas->getLastShape();
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					shape->updateShape(sf::Mouse::getPosition(window));
					canvas->refresh(window);
				}
			}
		}
	}

	delete canvas;
}
