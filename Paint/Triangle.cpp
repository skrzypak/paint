#include "Triangle.h"

CApp::Triangle::Triangle(const sf::Vector2i& s): Polygons(3)
{
#ifdef _DEBUG
	std::cout << "CApp::Triangle::Triangle(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_startXY = s;
	this->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

void* CApp::Triangle::getDrawable() const
{
#ifdef _DEBUG
	std::cout << "void* CApp::Triangle::getDrawable() const" << std::endl;
#endif
	return const_cast<Triangle*>(this);
}
