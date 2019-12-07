#include "Ellipse.h"
#include <iostream>

CApp::Ellipse::Ellipse(const sf::Vector2i& s):
    __radius(new sf::Vector2f(0.f, 0.f))
{
    std::cout << "CApp::Ellipse::Ellipse(const sf::Vector2i& s): _radius(sf::Vector2f(0.f, 0.f))" << std::endl;
    __shape = this;
    _startPixel = s;
    _pointCount = 25;
    __shape->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

CApp::Ellipse::~Ellipse()
{
    std::cout << "CApp::Ellipse::~Ellipse()" << std::endl;
    delete __radius;
    __radius = nullptr;
}

void CApp::Ellipse::updateShape(const sf::Vector2i& curr)
{
	std::cout << "void CApp::Ellipse::updateShape(const sf::Vector2i& curr)" << std::endl;
    *__radius = sf::Vector2f(static_cast<float>((curr.x - _startPixel.x)/2), static_cast<float>((curr.y - _startPixel.y)/2));
    sf::Shape::update();
}

void* CApp::Ellipse::getDrawable() const
{
	std::cout << "void* CApp::Ellipse::getDrawable() const" << std::endl;
	return __shape;
}

sf::Vector2f CApp::Ellipse::getPoint(std::size_t index) const
{
    std::cout << "sf::Vector2f CApp::Ellipse::getPoint(std::size_t index) const" << std::endl;
    static const float pi = 3.141592654f;
    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * (*__radius).x;
    float y = std::sin(angle) * (*__radius).y;
    return sf::Vector2f((*__radius).x + x, (*__radius).y + y);
}

std::size_t CApp::Ellipse::getPointCount() const
{
    std::cout << "std::size_t CApp::Ellipse::getPointCount() const" << std::endl;
    return _pointCount;
}
