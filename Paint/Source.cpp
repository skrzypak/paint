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

Controller* CTR = new Controller();

template<class T> 
Controller* createInstance()
{
	CTR->changeShapeController<T>();
	return CTR;
}


int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(750, 750), "PAINT 2D", sf::Style::Titlebar | sf::Style::Close);
	CApp::Canvas* canvas = new CApp::Canvas;
	tgui::Gui* gui = new tgui::Gui{ *window };
	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	menu->setSize(static_cast<float>((*window).getSize().x), 25.f);
	menu->setTextSize(13);

	std::multimap <std::string, Controller* (*)() > MENU;
	MENU.insert(std::make_pair("Shape/Ellipse", &createInstance<CApp::Ellipse>));
	MENU.insert(std::make_pair("Shape/Hexagon", &createInstance<CApp::Hexagon>));
	MENU.insert(std::make_pair("Shape/Rectangle", &createInstance<CApp::Rectangle>));

	menu->addMenu("Shape");
	for (auto const& el : MENU)
	{
		std::string parrent = (el.first).substr(0, (el.first).find('/'));
		std::string child = (el.first).substr((el.first).find('/') + 1, (el.first).size() - 1);
		menu->addMenuItem(parrent, child);
		menu->connectMenuItem(parrent, child, el.second);
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
