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

std::multimap <std::vector<sf::String>, std::function<void()>> setMenu(Controller*);

int main()
{
	sf::Image icon;
	if (!icon.loadFromFile("../assets/icon.png")) return EXIT_FAILURE;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(500, 500), "PAINT PK3", sf::Style::Titlebar | sf::Style::Close);
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	CApp::Canvas* canvas = new CApp::Canvas;
	tgui::Gui* gui = new tgui::Gui{ *window };
	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	
	Controller* CTR = new Controller();
	auto menuOptions = setMenu(CTR);
	
	menu->setSize(static_cast<float>((*window).getSize().x), 25.f);
	menu->setTextSize(13);

	for (auto const& option: menuOptions)
	{
		menu->addMenuItem(option.first);
		menu->connectMenuItem(option.first, option.second);
	}

	gui->add(menu);
	canvas->refresh(window, gui);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (gui->handleEvent(event) ==  1) canvas->refresh(window, gui);
			if (event.type) window->clear(sf::Color::Black);
			if(event.type == sf::Event::Closed) window->close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				auto shape = CTR->getShapeController()->generate(canvas, sf::Mouse::getPosition(*window));
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					shape->update(sf::Mouse::getPosition(*window), CTR->getProperites());
					canvas->refresh(window, gui);
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				CTR->reverseColors();
				auto shape = CTR->getShapeController()->generate(canvas, sf::Mouse::getPosition(*window));
				while (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					shape->update(sf::Mouse::getPosition(*window), CTR->getProperites());
					canvas->refresh(window, gui);
				}
				CTR->reverseColors();
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

std::multimap <std::vector<sf::String>, std::function<void()>> setMenu(Controller* CTR)
{
	std::multimap <std::vector<sf::String>, std::function<void()>> m;
	m.emplace(std::vector<sf::String> { "Fill", "Color", "Red" }, [&, CTR] { CTR->setFillColor(sf::Color::Red); });
	m.emplace(std::vector<sf::String> { "Fill", "Color", "Green" }, [&, CTR] { CTR->setFillColor(sf::Color::Green); });
	m.emplace(std::vector<sf::String> { "Fill", "Color", "Blue" }, [&, CTR] { CTR->setFillColor(sf::Color::Blue); });
	m.emplace(std::vector<sf::String> { "Fill", "Color", "White" }, [&, CTR] { CTR->setFillColor(sf::Color::White); });
	m.emplace(std::vector<sf::String> { "Fill", "Texture", "Grunde Style" }, [&, CTR] { CTR->setTexture("../assets/textures/grunge-style.png"); });
	m.emplace(std::vector<sf::String> { "Fill", "Texture", "Watercolor" }, [&, CTR] { CTR->setTexture("../assets/textures/watercolor.png"); });
	m.emplace(std::vector<sf::String> { "Fill", "Texture", "None" }, [&, CTR] { CTR->clearTexture(); });
	m.emplace(std::vector<sf::String> { "Outline", "Color", "Red" }, [&, CTR] { CTR->setOutlineColor(sf::Color::Red); });
	m.emplace(std::vector<sf::String> { "Outline", "Color", "Green" }, [&, CTR] { CTR->setOutlineColor(sf::Color::Green); });
	m.emplace(std::vector<sf::String> { "Outline", "Color", "Blue" }, [&, CTR] { CTR->setOutlineColor(sf::Color::Blue); });
	m.emplace(std::vector<sf::String> { "Outline", "Color", "White" }, [&, CTR] { CTR->setOutlineColor(sf::Color::White); });
	m.emplace(std::vector<sf::String> { "Outline", "Size", "None" }, [&, CTR] { CTR->setOutlineSize(0); });
	m.emplace(std::vector<sf::String> { "Outline", "Size", "Thin" }, [&, CTR] { CTR->setOutlineSize(5); });
	m.emplace(std::vector<sf::String> { "Outline", "Size", "Medium" }, [&, CTR] { CTR->setOutlineSize(10); });
	m.emplace(std::vector<sf::String> { "Outline", "Size", "Thick" }, [&, CTR] { CTR->setOutlineSize(15); });
	m.emplace(std::vector<sf::String> { "Shape", "Ellipse" }, [&, CTR] { CTR->setShape<CApp::Ellipse>(); });
	m.emplace(std::vector<sf::String> { "Shape", "Hexagon" }, [&, CTR] { CTR->setShape<CApp::Hexagon>(); });
	m.emplace(std::vector<sf::String> { "Shape", "Rectangle" }, [&, CTR] { CTR->setShape<CApp::Rectangle>(); });
	return m;
}
