#include "Pentagon.h"

CApp::Pentagon::Pentagon(const sf::Vector2i& s) : Polygons(5)
{
#ifdef _DEBUG
	std::cout << "CApp::Pentagon::Pentagon(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_startXY = s;
	this->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

void* CApp::Pentagon::getDrawable() const
{
#ifdef _DEBUG
	std::cout << "void* CApp::Pentagon::getDrawable() const" << std::endl;
#endif
	return const_cast<Pentagon*>(this);
}
