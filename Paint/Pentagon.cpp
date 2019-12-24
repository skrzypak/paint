#include "Pentagon.h"

Shapes::Pentagon::Pentagon(const sf::Vector2i& s) : Polygons(5)
{
#ifdef _DEBUG
	std::cout << "Shapes::Pentagon::Pentagon(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_originPixel = s;
	this->setPosition(sf::Vector2f(_originPixel));
}