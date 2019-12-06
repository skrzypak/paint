#include "Ellipse.h"
#include <iostream>
#include <cmath>

CApp::Ellipse::Ellipse(const sf::Vector2f& radius = sf::Vector2f(0, 0)): __radius(radius)
{
	std::cout << "CApp::Ellipse::Ellipse(const sf::Vector2f& _radius = sf::Vector2f(0, 0)): radius(_radius)" << std::endl;
	update();
}

CApp::Ellipse* CApp::Ellipse::generate()
{
	std::cout << "CApp::Ellipse* CApp::Ellipse::generate()" << std::endl;
    return new CApp::Ellipse({0.f, 0.f});
}

void CApp::Ellipse::update()
{
	std::cout << "void CApp::Ellipse::update()" << std::endl;
}

CApp::Ellipse::~Ellipse()
{
	std::cout << "CApp::Ellipse::~Ellipse()" << std::endl;
}

void CApp::Ellipse::setRadius(const sf::Vector2f& r)
{
    std::cout << "void CApp::Ellipse::setRadius(const sf::Vector2f& r)" << std::endl;
    __radius = r;
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
    std::cout << "sf::Vector2f CApp::Ellipse::getPoint(unsigned int index) const" << std::endl;
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * __radius.x;
    float y = std::sin(angle) * __radius.y;

    return sf::Vector2f(__radius.x + x, __radius.y + y);
}