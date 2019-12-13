#include "Diamond.h"

CApp::Diamond::Diamond(const sf::Vector2i& s) : Polygons(4)
{
#ifdef _DEBUG
	std::cout << "CApp::Diamond::Diamond(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_startXY = s;
	this->setPosition(sf::Vector2f(_startXY));
}