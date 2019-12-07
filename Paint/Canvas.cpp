#include "Canvas.h"
#include <iostream>

CApp::Canvas::Canvas(): 
	__window(new sf::RenderWindow(sf::VideoMode(500, 500), "PK3"))
{
	std::cout << "CApp::Canvas::Canvas()" << std::endl;
	__window->clear(sf::Color::Black);
	__window->display();
}

CApp::Canvas::~Canvas()
{
	std::cout << "CApp::Canvas::~Canvas()" << std::endl;
	for (auto el : __shapes)
	{
		delete el;
		el = nullptr;
	}
	delete __window;
}

void CApp::Canvas::generateShape(Shape* s)
{
	std::cout << "void CApp::Canvas::generate(Shape* s)" << std::endl;
	__shapes.push_back(s);
}

CApp::Shape* CApp::Canvas::getLastShape()
{
	std::cout << "CApp::Shape* CApp::Canvas::getLastShape()" << std::endl;
	return __shapes.back();
}

void CApp::Canvas::refresh()
{
	std::cout << "void CApp::Canvas::refresh()" << std::endl;
	this->__window->clear(sf::Color::Black);
	for (const auto& figure : this->__getShapes())
	{
		try {
			sf::Drawable* seed = static_cast<sf::Drawable*>(figure->getDrawable());
			this->__window->draw(*seed);
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	this->__window->display();
}

sf::RenderWindow* CApp::Canvas::getWindow()
{
	std::cout << "sf::RenderWindow* CApp::Canvas::getWindow()" << std::endl;
	return __window;
}

std::vector<CApp::Shape*> CApp::Canvas::__getShapes()
{
	std::cout << "std::vector<CApp::Shape*> CApp::Canvas::getShapes()" << std::endl;
	return __shapes;
}

