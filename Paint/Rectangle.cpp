#include "Rectangle.h"
#include <iostream>

CApp::Rectangle::Rectangle()
{
	std::cout << "CApp::Rectangle::Rectangle()" << std::endl;
}

void CApp::Rectangle::updateShape()
{
	std::cout << "void CApp::Rectangle::updateShape()" << std::endl;
}

CApp::Rectangle::~Rectangle()
{
	std::cout << "CApp::Rectangle::~Rectangle()" << std::endl;
}

size_t CApp::Rectangle::getPointCount() const
{
	// Return
	std::cout << "size_t CApp::Rectangle::getPointCount() const" << std::endl;
	return size_t();
}

sf::Vector2f CApp::Rectangle::getPoint(std::size_t) const
{
	// Return
	std::cout << "sf::Vector2f CApp::Rectangle::getPoint(std::size_t) const" << std::endl;
	return sf::Vector2f();
}

