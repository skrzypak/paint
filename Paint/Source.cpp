#include  "Header.h"

int main()
{
	CApp::Canvas * canvas = new CApp::Canvas;
	auto window = canvas->getWindow();

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type) window->clear(sf::Color::Black);
			if (event.type == sf::Event::Closed) window->close();
			if (event.type == sf::Event::Resized)
			{
				window->setView(sf::View(sf::FloatRect(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));
				canvas->refresh();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				canvas->generateShape(new CApp::Rectangle(sf::Mouse::getPosition(*window)));
				//canvas->generateShape(new CApp::Ellipse(sf::Mouse::getPosition(*window)));
				auto shape = canvas->getLastShape();
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					shape->updateShape(sf::Mouse::getPosition(*window));
					canvas->refresh();
				}
			}
		}
	}

	delete canvas;
}
