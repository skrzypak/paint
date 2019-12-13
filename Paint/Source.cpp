#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <cstring>
#include "Canvas.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Trapeze.h"
#include "Diamond.h"
#include "Pentagon.h"
#include "Custom.h"
#include "Line.h"
#include "Controller.h"

#ifdef _DEBUG
#include <vld.h>
#endif

void setMenu(Controller*, tgui::MenuBar::Ptr);

int main()
{
	sf::Image icon;
	if (!icon.loadFromFile("../assets/icon.png")) return EXIT_FAILURE;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(500, 500), "PAINT PK3", sf::Style::Titlebar | sf::Style::Close);
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	CApp::Canvas* canvas = new CApp::Canvas;
	tgui::Gui* gui = new tgui::Gui{ *window };
	
	Controller* CTR = new Controller();

	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	menu->setSize(static_cast<float>((*window).getSize().x), 25.f);
	menu->setTextSize(13);
	setMenu(CTR, menu);

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

void setMenu(Controller* CTR, tgui::MenuBar::Ptr menu)
{
	
	// --------------------------------------------MODE SECTION-----------------------------------------------------
	menu->addMenuItem({ "Mode", "Pencil" });
	menu->connectMenuItem("Mode", "Pencil", [&, CTR] { CTR->setShape<CApp::Custom>(); });
	menu->addMenuItem({ "Mode", "Shape", "Line" });
	menu->connectMenuItem({ "Mode", "Shape", "Line" }, [&, CTR] { CTR->setShape<CApp::Line>(); });
	menu->addMenuItem({ "Mode", "Shape", "Triangle" });
	menu->connectMenuItem({ "Mode", "Shape", "Triangle" }, [&, CTR] { CTR->setShape<CApp::Triangle>(); });
	menu->addMenuItem({ "Mode", "Shape", "Trapeze" });
	menu->connectMenuItem({ "Mode", "Shape", "Trapeze" }, [&, CTR] { CTR->setShape<CApp::Trapeze>(); });
	menu->addMenuItem({ "Mode", "Shape", "Rectangle" });
	menu->connectMenuItem({ "Mode", "Shape", "Rectangle" }, [&, CTR] { CTR->setShape<CApp::Rectangle>(); });
	menu->addMenuItem({ "Mode", "Shape", "Diamond" });
	menu->connectMenuItem({ "Mode", "Shape", "Diamond" }, [&, CTR] { CTR->setShape<CApp::Diamond>(); });
	menu->addMenuItem({ "Mode", "Shape", "Pentagon" });
	menu->connectMenuItem({ "Mode", "Shape", "Pentagon" }, [&, CTR] { CTR->setShape<CApp::Pentagon>(); });
	menu->addMenuItem({ "Mode", "Shape", "Hexagon" });
	menu->connectMenuItem({ "Mode", "Shape", "Hexagon" }, [&, CTR] { CTR->setShape<CApp::Hexagon>(); });
	menu->addMenuItem({ "Mode", "Shape", "Ellipse" });
	menu->connectMenuItem({ "Mode", "Shape", "Ellipse" }, [&, CTR] { CTR->setShape<CApp::Ellipse>(); });

	// --------------------------------------------COLOR PRIMARY SECTION--------------------------------------------
	menu->addMenuItem({ "Color", "Primary", "Red" });
	menu->connectMenuItem({ "Color", "Primary", "Red" }, [&, CTR] { CTR->setFillColor(sf::Color::Red); });
	menu->addMenuItem({ "Color", "Primary", "Green" });
	menu->connectMenuItem({ "Color", "Primary", "Green" }, [&, CTR] { CTR->setFillColor(sf::Color::Green); });
	menu->addMenuItem({ "Color", "Primary", "Blue" });
	menu->connectMenuItem({ "Color", "Primary", "Blue" }, [&, CTR] { CTR->setFillColor(sf::Color::Blue); });
	menu->addMenuItem({ "Color", "Primary", "White" });
	menu->connectMenuItem({ "Color", "Primary", "White" }, [&, CTR] { CTR->setFillColor(sf::Color::White); });
	menu->addMenuItem({ "Color", "Primary", "Black" });
	menu->connectMenuItem({ "Color", "Primary", "Black" }, [&, CTR] { CTR->setFillColor(sf::Color::Black); });

	// --------------------------------------------COLOR SECONDARY SECTION------------------------------------------
	menu->addMenuItem({ "Color", "Secondary", "Red" });
	menu->connectMenuItem({ "Color", "Secondary", "Red" }, [&, CTR] { CTR->setOutlineColor(sf::Color::Red); });
	menu->addMenuItem({ "Color", "Secondary", "Green" });
	menu->connectMenuItem({ "Color", "Secondary", "Green" }, [&, CTR] { CTR->setOutlineColor(sf::Color::Green); });
	menu->addMenuItem({ "Color", "Secondary", "Blue" });
	menu->connectMenuItem({ "Color", "Secondary", "Blue" }, [&, CTR] { CTR->setOutlineColor(sf::Color::Blue); });
	menu->addMenuItem({ "Color", "Secondary", "White" });
	menu->connectMenuItem({ "Color", "Secondary", "White" }, [&, CTR] { CTR->setOutlineColor(sf::Color::White); });
	menu->addMenuItem({ "Color", "Secondary", "Black" });
	menu->connectMenuItem({ "Color", "Secondary", "Black" }, [&, CTR] { CTR->setOutlineColor(sf::Color::Black); });

	// --------------------------------------------OUTLINE SECTION-------------------------------------------------
	menu->addMenuItem({ "Outline", "0" });
	menu->connectMenuItem({ "Outline", "0" }, [&, CTR] { CTR->setOutlineSize(0); });
	menu->addMenuItem({ "Outline", "3" });
	menu->connectMenuItem({ "Outline", "3" }, [&, CTR] { CTR->setOutlineSize(3); });
	menu->addMenuItem({ "Outline", "6" });
	menu->connectMenuItem({ "Outline", "6" }, [&, CTR] { CTR->setOutlineSize(6); });
	menu->addMenuItem({ "Outline", "9" });
	menu->connectMenuItem({ "Outline", "9" }, [&, CTR] { CTR->setOutlineSize(9); });

	// --------------------------------------------TEXTURE SECTION--------------------------------------------------
	menu->addMenuItem({ "Texture", "-" });
	menu->connectMenuItem({ "Texture", "-" }, [&, CTR] { CTR->clearTexture(); });
	menu->addMenuItem({ "Texture", "Style 1" });
	menu->connectMenuItem({ "Texture", "Style 1" }, [&, CTR] {CTR->setTexture("../assets/textures/grunge-style.png"); });
	menu->addMenuItem({ "Texture", "Style 2" });
	menu->connectMenuItem({ "Texture", "Style 2" }, [&, CTR] { CTR->setTexture("../assets/textures/watercolor.png"); });

}
