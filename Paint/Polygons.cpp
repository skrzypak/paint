#include "Polygons.h"
#include <iostream>

CApp::Polygons::Polygons(unsigned int p):
    __radius(new sf::Vector2f(0.f, 0.f))

{
    std::cout << "CApp::Polygons::Polygons() : __radius(new sf::Vector2f(0.f, 0.f))" << std::endl;
    __pointCount = p;
}

CApp::Polygons::~Polygons()
{
    std::cout << "CApp::Polygons::~Polygons()" << std::endl;
    delete __radius;
    __radius = nullptr;
}

sf::Vector2f CApp::Polygons::getPoint(std::size_t index) const
{
    std::cout << "sf::Vector2f CApp::Polygons::getPoint(std::size_t index) const" << std::endl;
    static const float pi = 3.141592654f;
    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * (*__radius).x;
    float y = std::sin(angle) * (*__radius).y;
    return sf::Vector2f((*__radius).x + x, (*__radius).y + y);
}

sf::Vector2f* CApp::Polygons::getRadius() const
{
    std::cout << "sf::Vector2f* CApp::Polygons::getRadius() const" << std::endl;
    return __radius;
}

void CApp::Polygons::setRadius(const sf::Vector2f& r)
{
    std::cout << "void CApp::Polygons::setRadius(const sf::Vector2f& r)" << std::endl;
    *__radius = r;
}

void CApp::Polygons::updateShape(const sf::Vector2i& curr)
{
    std::cout << "void CApp::Polygons::updateShape(const sf::Vector2i& curr)" << std::endl;
    setRadius(sf::Vector2f(static_cast<float>((curr.x - _startPixel.x) / 2), static_cast<float>((curr.y - _startPixel.y) / 2)));
    sf::Shape::update();
}

std::size_t CApp::Polygons::getPointCount() const
{
    std::cout << "std::size_t CApp::Polygons::getPointCount() const" << std::endl;
    return __pointCount;
}
