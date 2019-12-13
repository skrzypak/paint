#include "Triangle.h"

CApp::Triangle::Triangle(const sf::Vector2i& s): Polygons(3)
{
#ifdef _DEBUG
	std::cout << "CApp::Triangle::Triangle(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_startXY = s;
	this->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}