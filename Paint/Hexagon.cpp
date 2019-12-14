#include "Hexagon.h"

Shapes::Hexagon::Hexagon(const sf::Vector2i& s): Polygons(6)
{
#ifdef _DEBUG
    std::cout << "CApp::Hexagon::Hexagon(const sf::Vector2i& s): Polygons(6)" << std::endl;
#endif
    _originPixel = s;
    this->setPosition(sf::Vector2f(_originPixel));
}