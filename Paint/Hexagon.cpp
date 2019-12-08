#include "Hexagon.h"

CApp::Hexagon::Hexagon(const sf::Vector2i& s): Polygons(6)
{
#ifdef _DEBUG
    std::cout << "CApp::Hexagon::Hexagon(const sf::Vector2i& s): Polygons(6)" << std::endl;
#endif
    _startXY = s;
    this->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

void* CApp::Hexagon::getDrawable() const
{
#ifdef _DEBUG
    std::cout << "CApp::Hexagon::Hexagon(const sf::Vector2i& s): Polygons(6)" << std::endl;
#endif
    return const_cast<Hexagon*>(this);
}
