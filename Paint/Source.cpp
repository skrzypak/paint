#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <cstring>
#include "Canvas.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Hexagon.h"
#include "Controller.h"
#include <vector>
#include <map>

#ifdef _DEBUG
#include <vld.h>
#endif

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(500, 500), "PAINT 2D", sf::Style::Titlebar | sf::Style::Close);
	CApp::Canvas* canvas = new CApp::Canvas;
	tgui::Gui* gui = new tgui::Gui{ *window };
	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	
	Controller* CTR = new Controller();
	
	std::multimap <std::vector<sf::String>, std::function<void()>> menuOptions;
	menuOptions.emplace(std::vector<sf::String> { "Color", "Fill", "Red" }, [&, CTR] { CTR->setShape<CApp::Ellipse>(); });
	menuOptions.emplace(std::vector<sf::String> { "Color", "Border", "Red" }, [&, CTR] { CTR->setShape<CApp::Ellipse>(); });
	menuOptions.emplace(std::vector<sf::String> { "Shape", "Ellipse" }, [&, CTR] { CTR->setShape<CApp::Ellipse>(); });
	menuOptions.emplace(std::vector<sf::String> { "Shape", "Hexagon" }, [&, CTR] { CTR->setShape<CApp::Hexagon>(); });
	menuOptions.emplace(std::vector<sf::String> { "Shape", "Rectangle" }, [&, CTR] { CTR->setShape<CApp::Rectangle>(); });
	
	menu->setSize(static_cast<float>((*window).getSize().x), 25.f);
	menu->setTextSize(13);

	for (auto const& option: menuOptions)
	{
		menu->addMenuItem(option.first);
		menu->connectMenuItem(option.first, option.second);
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
				auto shape = CTR->getShapeController()->generate(canvas, sf::Mouse::getPosition(*window));
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
	delete CTR;
	canvas = nullptr;
	window = nullptr;
	gui = nullptr;
	CTR = nullptr;

	return EXIT_SUCCESS;
}
