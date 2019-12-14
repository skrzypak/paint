#include "Triangle.h"

Shapes::Triangle::Triangle(const sf::Vector2i& s): Shapes::Convex()
{
#ifdef _DEBUG
    std::cout << "CApp::Triangle::Triangle(const sf::Vector2i& s): Shapes::Convex()" << std::endl;
#endif
    _originPixel = s;
    _convex->setPointCount(3);
}

void Shapes::Triangle::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void CApp::Trapeze::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    _convex->setFillColor(p->fillColor);
    _convex->setOutlineColor(p->outlineColor);
    _convex->setOutlineThickness(p->outlineSize);
    *_texture = (*p->texture);
    _convex->setTexture(_texture);

    auto len = (curr.x - _originPixel.x) / 2;
    _convex->setPoint(0, sf::Vector2f(static_cast<float>(_originPixel.x), static_cast<float>(curr.y)));
    _convex->setPoint(1, sf::Vector2f(static_cast<float>(_originPixel.x + len), static_cast<float>(_originPixel.y)));
    _convex->setPoint(2, sf::Vector2f(static_cast<float>(curr.x), static_cast<float>(curr.y)));
  
}