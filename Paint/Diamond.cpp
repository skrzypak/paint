#include "Diamond.h"

CApp::Diamond::Diamond(const sf::Vector2i& s) : Polygons(4)
{
#ifdef _DEBUG
	std::cout << "CApp::Diamond::Diamond(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_startXY = s;
	this->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

void* CApp::Diamond::getDrawable() const
{
#ifdef _DEBUG
	std::cout << "void* CApp::Diamond::getDrawable() const" << std::endl;
#endif
	return const_cast<Diamond*>(this);
}
