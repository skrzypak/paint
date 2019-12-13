#include "Pentagon.h"

CApp::Pentagon::Pentagon(const sf::Vector2i& s) : Polygons(5)
{
#ifdef _DEBUG
	std::cout << "CApp::Pentagon::Pentagon(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_startXY = s;
	this->setPosition(sf::Vector2f(_startXY));
}