#include  "Header.h"

int main()
{
	const unsigned width = 500;
	const unsigned int height = 500;
	std::string title = "PAINT 2D";
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	CApp::Canvas * canvas = new CApp::Canvas(CApp::WindowSettings({ width, height }, title, settings));
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
				auto shape = canvas->getLastShape();
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					shape->updateShape(sf::Mouse::getPosition(*window));
					canvas->refresh();
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				canvas->generateShape(new CApp::Ellipse(sf::Mouse::getPosition(*window)));
				auto shape = canvas->getLastShape();
				while (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					shape->updateShape(sf::Mouse::getPosition(*window));
					canvas->refresh();
				}
			}
		}
	}

	delete canvas;
}
