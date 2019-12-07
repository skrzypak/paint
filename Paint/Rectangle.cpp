#include "Rectangle.h"
#include <iostream>

CApp::Rectangle::Rectangle(const sf::Vector2i& s): 
	__shape(new sf::RectangleShape)
{
	std::cout << "CApp::Rectangle::Rectangle(const sf::Vector2i& s): __shape(new sf::RectangleShape)" << std::endl;
	_startPixel = s;
	__shape->setPosition(sf::Vector2f(_startPixel));
}

void CApp::Rectangle::updateShape(const sf::Vector2i& curr)
{
	std::cout << "void CApp::Rectangle::updateShape(const sf::Vector2i& curr)" << std::endl;
	__shape->setSize(sf::Vector2f(static_cast<float>(curr.x - _startPixel.x), static_cast<float>(curr.y - _startPixel.y)));
}

CApp::Rectangle::~Rectangle()
{
	std::cout << "CApp::Rectangle::~Rectangle()" << std::endl;
	delete __shape;
	__shape = nullptr;
}

void* CApp::Rectangle::getDrawable() const
{
	std::cout << "void* CApp::Rectangle::getDrawable() const" << std::endl;
	return __shape;
}

size_t CApp::Rectangle::getPointCount() const
{
	// Return
	std::cout << "size_t CApp::Rectangle::getPointCount() const" << std::endl;
	return __shape->getPointCount();
}

sf::Vector2f CApp::Rectangle::getPoint(std::size_t index) const
{
	// Return
	std::cout << "sf::Vector2f CApp::Rectangle::getPoint(std::size_t index) const" << std::endl;
	return __shape->getPoint(index);
}

