#include "Trapeze.h"

Shapes::Trapeze::Trapeze(const sf::Vector2i& s): __convex(new sf::ConvexShape), Shapes::Shape()
{
#ifdef _DEBUG
    std::cout << "CApp::Trapeze::Trapeze(const sf::Vector2i& s): __radius(new sf::Vector2f(0.f, 0.f)), CApp::Shape()" << std::endl;
#endif
    _originPixel = s;
    __convex->setPointCount(4);
}

Shapes::Trapeze::~Trapeze()
{
#ifdef _DEBUG
    std::cout << "CApp::Trapeze::~Trapeze()" << std::endl;
#endif
    delete __convex;
    __convex = nullptr;
}

void Shapes::Trapeze::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
    std::cout << "void CApp::Trapeze::draw(sf::RenderWindow* w) const" << std::endl;
#endif
    w->draw(*__convex);
}

void Shapes::Trapeze::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void CApp::Trapeze::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    __convex->setFillColor(p->fillColor);
    __convex->setOutlineColor(p->outlineColor);
    __convex->setOutlineThickness(p->outlineSize);
    *_texture = (*p->texture);
    __convex->setTexture(_texture);

    auto len = (curr.x - _originPixel.x) / 3;
    __convex->setPoint(0, sf::Vector2f(static_cast<float>(_originPixel.x), static_cast<float>(curr.y)));
    __convex->setPoint(1, sf::Vector2f(static_cast<float>(_originPixel.x + len), static_cast<float>(_originPixel.y)));
    __convex->setPoint(2, sf::Vector2f(static_cast<float>(curr.x - len), static_cast<float>(_originPixel.y)));
    __convex->setPoint(3, sf::Vector2f(static_cast<float>(curr.x), static_cast<float>(curr.y)));
}