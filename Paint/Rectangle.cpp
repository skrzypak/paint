#include "Rectangle.h"

CApp::Rectangle::Rectangle(const sf::Vector2i& s): 
	_rectangle(new sf::RectangleShape),
	CApp::Shape()
{
#ifdef _DEBUG
	std::cout << "CApp::Rectangle::Rectangle(const sf::Vector2i& s): __rectangle(new sf::RectangleShape)" << std::endl;
#endif
	_startXY = s;
	_rectangle->setPosition(sf::Vector2f(_startXY));
}

CApp::Rectangle::~Rectangle()
{
#ifdef _DEBUG
	std::cout << "CApp::Rectangle::~Rectangle()" << std::endl;
#endif
	delete 	_rectangle;
	_rectangle = nullptr;
}

size_t CApp::Rectangle::getPointCount() const
{
#ifdef _DEBUG
	std::cout << "size_t CApp::Rectangle::getPointCount() const" << std::endl;
#endif
	return 	_rectangle->getPointCount();
}

sf::Vector2f CApp::Rectangle::getPoint(std::size_t index) const
{
#ifdef _DEBUG
	std::cout << "sf::Vector2f CApp::Rectangle::getPoint(std::size_t index) const" << std::endl;
#endif
	return 	_rectangle->getPoint(index);
}

void* CApp::Rectangle::getDrawable() const
{
#ifdef _DEBUG
	std::cout << "void* CApp::Rectangle::getDrawable() const" << std::endl;
#endif
	return	_rectangle;
}

void CApp::Rectangle::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
	std::cout << "void CApp::Rectangle::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
	_rectangle->setSize(sf::Vector2f(static_cast<float>(curr.x - _startXY.x), static_cast<float>(curr.y - _startXY.y)));
	_rectangle->setFillColor(p->fillColor);
	_rectangle->setOutlineColor(p->outlineColor);
	_rectangle->setOutlineThickness(p->outlineSize);
	*_texture = (*p->texture);
	_rectangle->setTexture(_texture);
}