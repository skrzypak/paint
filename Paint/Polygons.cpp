#include "Polygons.h"

CApp::Polygons::Polygons(unsigned int p):
    __radius(new sf::Vector2f(0.f, 0.f)),
    __pointCount(p)
{
#ifdef _DEBUG
    std::cout << "CApp::Polygons::Polygons(unsigned int p): __radius(new sf::Vector2f(0.f, 0.f)), __pointCount(p)" << std::endl;
#endif
}

CApp::Polygons::~Polygons()
{
#ifdef _DEBUG
    std::cout << "CApp::Polygons::~Polygons()" << std::endl;
#endif
    delete __radius;
    __radius = nullptr;
}

std::size_t CApp::Polygons::getPointCount() const
{
#ifdef _DEBUG
    std::cout << "std::size_t CApp::Polygons::getPointCount() const" << std::endl;
#endif
    return __pointCount;
}

sf::Vector2f CApp::Polygons::getPoint(std::size_t index) const
{
#ifdef _DEBUG
    std::cout << "sf::Vector2f CApp::Polygons::getPoint(std::size_t index) const" << std::endl;
#endif
    static const float pi = 3.141592654f;
    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * (*__radius).x;
    float y = std::sin(angle) * (*__radius).y;
    return sf::Vector2f((*__radius).x + x, (*__radius).y + y);
}

sf::Vector2f* CApp::Polygons::getRadius() const
{
#ifdef _DEBUG
    std::cout << "sf::Vector2f* CApp::Polygons::getRadius() const" << std::endl;
#endif
    return __radius;
}

void CApp::Polygons::setRadius(const sf::Vector2f& r)
{
#ifdef _DEBUG
    std::cout << "void CApp::Polygons::setRadius(const sf::Vector2f& r)" << std::endl;
#endif
    *__radius = r;
}

void CApp::Polygons::update(const sf::Vector2i& curr)
{
    // TO DO
#ifdef _DEBUG
    std::cout << "void CApp::Polygons::update(const sf::Vector2i& curr)" << std::endl;
#endif
    setRadius(sf::Vector2f(static_cast<float>((curr.x - _startXY.x) / 2), static_cast<float>((curr.y - _startXY.y) / 2)));
    sf::Shape::update();
}