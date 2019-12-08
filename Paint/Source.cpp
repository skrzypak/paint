#include <SFML/Graphics.hpp>
#include <cstring>
#include "Canvas.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Hexagon.h"

#ifdef _DEBUG
#include <vld.h>
#endif

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(500, 500), "PAINT 2D", sf::Style::Default, settings);
	window->display();

	CApp::Canvas * canvas = new CApp::Canvas;

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type) window->clear(sf::Color::Black);
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::Resized:
				window->setView(sf::View(sf::FloatRect(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));
				canvas->refresh(window);
				break;
			}
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				auto shape = canvas->generateShape(new CApp::Rectangle(sf::Mouse::getPosition(*window)));
				//auto shape = canvas->generateShape(new CApp::Ellipse(sf::Mouse::getPosition(*window)));
				//auto shape = canvas->generateShape(new CApp::Hexagon(sf::Mouse::getPosition(*window)));
				
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					shape->update(sf::Mouse::getPosition(*window));
					canvas->refresh(window);
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				//auto shape = canvas->generateShape(new CApp::Rectangle(sf::Mouse::getPosition(*window)));
				//auto shape = canvas->generateShape(new CApp::Ellipse(sf::Mouse::getPosition(*window)));
				auto shape = canvas->generateShape(new CApp::Hexagon(sf::Mouse::getPosition(*window)));
				
				while (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					shape->update(sf::Mouse::getPosition(*window));
					canvas->refresh(window);
				}
			}
		}
	}

	delete canvas;
	delete window;
	canvas = nullptr;
	window = nullptr;
}
