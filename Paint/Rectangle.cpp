#include "Rectangle.h"

CApp::Rectangle::Rectangle(const sf::Vector2i& s): 
	__rectangle(new sf::RectangleShape)
{
#ifdef _DEBUG
	std::cout << "CApp::Rectangle::Rectangle(const sf::Vector2i& s): __rectangle(new sf::RectangleShape)" << std::endl;
#endif
	_startXY = s;
	__rectangle->setPosition(sf::Vector2f(_startXY));
}

CApp::Rectangle::~Rectangle()
{
#ifdef _DEBUG
	std::cout << "CApp::Rectangle::~Rectangle()" << std::endl;
#endif
	delete 	__rectangle;
	__rectangle = nullptr;
}

size_t CApp::Rectangle::getPointCount() const
{
#ifdef _DEBUG
	std::cout << "size_t CApp::Rectangle::getPointCount() const" << std::endl;
#endif
	return 	__rectangle->getPointCount();
}

sf::Vector2f CApp::Rectangle::getPoint(std::size_t index) const
{
#ifdef _DEBUG
	std::cout << "sf::Vector2f CApp::Rectangle::getPoint(std::size_t index) const" << std::endl;
#endif
	return 	__rectangle->getPoint(index);
}

void* CApp::Rectangle::getDrawable() const
{
#ifdef _DEBUG
	std::cout << "void* CApp::Rectangle::getDrawable() const" << std::endl;
#endif
	return	__rectangle;
}

void CApp::Rectangle::update(const sf::Vector2i& curr, ShapeProperities* p)
{
	// TO DO
#ifdef _DEBUG
	std::cout << "void CApp::Rectangle::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
	__rectangle->setSize(sf::Vector2f(static_cast<float>(curr.x - _startXY.x), static_cast<float>(curr.y - _startXY.y)));
	__rectangle->setFillColor(p->fillColor);
	__rectangle->setOutlineColor(p->outlineColor);
}