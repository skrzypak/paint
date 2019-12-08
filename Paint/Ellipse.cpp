#include "Ellipse.h"
#include <iostream>

CApp::Ellipse::Ellipse(const sf::Vector2i& s):
    Polygons(30)
{
    std::cout << "CApp::Ellipse::Ellipse(const sf::Vector2i& s): _radius(sf::Vector2f(0.f, 0.f))" << std::endl;
    __shape = this;
    _startPixel = s;
    __shape->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

void* CApp::Ellipse::getDrawable() const
{
	std::cout << "void* CApp::Ellipse::getDrawable() const" << std::endl;
	return __shape;
}
