#include "Ellipse.h"

CApp::Ellipse::Ellipse(const sf::Vector2i& s): Polygons(30)
{
#ifdef _DEBUG
	std::cout << "CApp::Ellipse::Ellipse(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
    _startXY = s;
    this->setPosition(sf::Vector2f(_startXY));
}