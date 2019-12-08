#include "Hexagon.h"
#include <iostream>

CApp::Hexagon::Hexagon(const sf::Vector2i& s) :
    Polygons(6)
{
    std::cout << "CApp::Hexagon::Hexagon(const sf::Vector2i& s): _radius(sf::Vector2f(0.f, 0.f))" << std::endl;
    __shape = this;
    _startPixel = s;
    __shape->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

void* CApp::Hexagon::getDrawable() const
{
    std::cout << "void* CApp::Hexagon::getDrawable() const" << std::endl;
    return __shape;
}
