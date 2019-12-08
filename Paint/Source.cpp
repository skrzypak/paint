#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <cstring>
#include "Canvas.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Hexagon.h"
#include <vector>

#ifdef _DEBUG
#include <vld.h>
#endif

int main()
{
	enum StateIndex { FILE = 0, SHAPE, COLOR, PATTERN };
	std::string state[] = { "FILE", "Rectangle", "Red", "PATTERN" };
	std::string file[] = { "File", "Load", "Save", "/0" };
	std::string shape[] = { "Shape", "Ellipse", "Hexagon", "Rectangle", "/0" };
	std::string color[] = { "Color", "Red", "Green", "Blue", "/0" };
	std::string pattern[] = { "Pattern", "Default", "/0" };
	std::vector <void*> menuOpitons = { &file, &shape, &color, &pattern };

	CApp::Canvas* canvas = new CApp::Canvas;
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(750, 750), "PAINT 2D", sf::Style::Titlebar | sf::Style::Close, settings);
	tgui::Gui* gui = new tgui::Gui{ *window };
	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();

	menu->setSize(static_cast<float>((*window).getSize().x), 25.f);
	menu->setTextSize(13);

	for (size_t i = 0; i < menuOpitons.size(); i++)
	{
		auto option = static_cast<std::string *>(menuOpitons[i]);
		menu->addMenu(*option);
		auto f = option++;
		while (*option != "/0") {
			menu->addMenuItem(*f, *option);
			menu->connectMenuItem(*f, *option, [&, option, i]{state[i] = *option;});
			option++;
		}
	}
	(*gui).add(menu);
	canvas->refresh(window, gui);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if ((*gui).handleEvent(event) ==  1) canvas->refresh(window, gui);
			if (event.type) window->clear(sf::Color::Black);
			if(event.type == sf::Event::Closed) window->close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				CApp::Shape* shape{};
				if(state[StateIndex::SHAPE] == "Ellipse")
					shape = canvas->generateShape(new CApp::Ellipse(sf::Mouse::getPosition(*window)));
				else if(state[StateIndex::SHAPE] == "Hexagon")
					shape = canvas->generateShape(new CApp::Hexagon(sf::Mouse::getPosition(*window)));
				else
					shape = canvas->generateShape(new CApp::Rectangle(sf::Mouse::getPosition(*window)));

				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					shape->update(sf::Mouse::getPosition(*window));
					canvas->refresh(window, gui);
				}
			}
		}
	}

	delete canvas;
	delete gui;
	delete window;
	canvas = nullptr;
	window = nullptr;
	gui = nullptr;
	return EXIT_SUCCESS;
}
