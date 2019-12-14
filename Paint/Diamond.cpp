#include "Diamond.h"

Shapes::Diamond::Diamond(const sf::Vector2i& s) : Polygons(4)
{
#ifdef _DEBUG
	std::cout << "CApp::Diamond::Diamond(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
	_originPixel = s;
	this->setPosition(sf::Vector2f(_originPixel));
}