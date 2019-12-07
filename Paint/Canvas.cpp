#include "Canvas.h"
#include <iostream>

CApp::Canvas::Canvas()
{
	std::cout << "CApp::Canvas::Canvas()" << std::endl;
}

CApp::Canvas::~Canvas()
{
	std::cout << "CApp::Canvas::~Canvas()" << std::endl;
	for (auto el : __shapes)
	{
		delete el;
		el = nullptr;
	}
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

void CApp::Canvas::refresh(sf::RenderWindow& w)
{
	std::cout << "void CApp::Canvas::refresh(sf::RenderWindow& w)" << std::endl;
	w.clear(sf::Color::Black);
	for (const auto& el : this->__getShapes()) w.draw(*(el->__shape));
	w.display();
}

std::vector<CApp::Shape*> CApp::Canvas::__getShapes()
{
	std::cout << "std::vector<CApp::Shape*> CApp::Canvas::getShapes()" << std::endl;
	return __shapes;
}

