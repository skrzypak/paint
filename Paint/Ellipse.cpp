#include "Ellipse.h"

Shapes::Ellipse::Ellipse(const sf::Vector2i& s): Polygons(30)
{
#ifdef _DEBUG
	std::cout << "Shapes::Ellipse::Ellipse(const sf::Vector2i& s): Polygons(30)" << std::endl;
#endif
    _originPixel = s;
    this->setPosition(sf::Vector2f(_originPixel));
}