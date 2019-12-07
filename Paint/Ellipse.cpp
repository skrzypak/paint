#include "Ellipse.h"
#include <iostream>
#include <cmath>

CApp::Ellipse::Ellipse() : __radius({0.f, 0.f})
{
    std::cout << "CApp::Ellipse::Ellipse()" << std::endl;
    update();
}

void CApp::Ellipse::updateShape(const sf::Vector2i& curr)
{
	std::cout << "void CApp::Ellipse::updateShape(const sf::Vector2i& curr)" << std::endl;
}

CApp::Ellipse::~Ellipse()
{
	std::cout << "CApp::Ellipse::~Ellipse()" << std::endl;
}

void CApp::Ellipse::setRadius(const sf::Vector2f& radius)
{
    std::cout << "void CApp::Ellipse::setRadius(const sf::Vector2f& r)" << std::endl;
    __radius = radius;
    update();
}

const sf::Vector2f& CApp::Ellipse::getRadius() const
{
    std::cout << "const sf::Vector2f& CApp::Ellipse::getRadius() const" << std::endl;
    return __radius;
}

size_t CApp::Ellipse::getPointCount() const 
{
    std::cout << "size_t CApp::Ellipse::getPointCount() const" << std::endl;
    return 30; // fixed, but could be an attribute of the class if needed
}

sf::Vector2f CApp::Ellipse::getPoint(std::size_t index) const
{
    std::cout << "sf::Vector2f CApp::Ellipse::getPoint(std::size_t index) const" << std::endl;
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * __radius.x;
    float y = std::sin(angle) * __radius.y;

    return sf::Vector2f(__radius.x + x, __radius.y + y);
}