#include "Trapeze.h"

CApp::Trapeze::Trapeze(const sf::Vector2i& s): __radius(new sf::Vector2f(0.f, 0.f)), CApp::Shape()
{
#ifdef _DEBUG
    std::cout << "CApp::Trapeze::Trapeze(const sf::Vector2i& s): __radius(new sf::Vector2f(0.f, 0.f)), CApp::Shape()" << std::endl;
#endif
    _startXY = s;
    this->setPosition(sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y)));
}

CApp::Trapeze::~Trapeze()
{
#ifdef _DEBUG
    std::cout << "CApp::Trapeze::~Trapeze()" << std::endl;
#endif
    delete __radius;
    __radius = nullptr;
}

std::size_t CApp::Trapeze::getPointCount() const
{
#ifdef _DEBUG
    std::cout << "std::size_t CApp::Trapeze::getPointCount() const" << std::endl;
#endif
    return 4;
}

sf::Vector2f CApp::Trapeze::getPoint(std::size_t index) const
{
#ifdef _DEBUG
    std::cout << "sf::Vector2f CApp::Trapeze::getPoint(std::size_t index) const" << std::endl;
#endif
    float angle = index * 2 * _PI / getPointCount() - _PI / 2;
    float x = std::cos(angle) * (*__radius).x;
    float y = std::sin(angle) * (*__radius).y;
    return sf::Vector2f((*__radius).x + x, (*__radius).y + y);
}

void CApp::Trapeze::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
    std::cout << "void CApp::Trapeze::draw(sf::RenderWindow* w) const" << std::endl;
#endif
    w->draw(*const_cast<Trapeze*>(this));
}

sf::Vector2f* CApp::Trapeze::getRadius() const
{
#ifdef _DEBUG
    std::cout << "sf::Vector2f* CApp::Trapeze::getRadius() const" << std::endl;
#endif
    return __radius;
}

void CApp::Trapeze::setRadius(const sf::Vector2f& r)
{
#ifdef _DEBUG
    std::cout << "void CApp::Trapeze::setRadius(const sf::Vector2f& r)" << std::endl;
#endif
    * __radius = r;
}

void CApp::Trapeze::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void CApp::Trapeze::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    setRadius(sf::Vector2f(static_cast<float>((curr.x - _startXY.x) / 2), static_cast<float>((curr.y - _startXY.y) / 2)));
    sf::Shape::setFillColor(p->fillColor);
    sf::Shape::setOutlineColor(p->outlineColor);
    sf::Shape::setOutlineThickness(p->outlineSize);
    *_texture = (*p->texture);
    sf::Shape::setTexture(_texture);
    sf::Shape::update();
}