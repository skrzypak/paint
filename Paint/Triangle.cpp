#include "Triangle.h"

Shapes::Triangle::Triangle(const sf::Vector2i& s): Shapes::Convex()
{
#ifdef _DEBUG
    std::cout << "Shapes::Triangle::Triangle(const sf::Vector2i& s): Shapes::Convex()" << std::endl;
#endif
    _originPixel = s;
    _convex->setPointCount(3);
}

void Shapes::Triangle::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void Shapes::Trapeze::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    _convex->setFillColor(p->fillColor);
    _convex->setOutlineColor(p->outlineColor);
    _convex->setOutlineThickness(p->outlineSize);
    *_texture = (*p->texture);
    _convex->setTexture(_texture);

    auto len = (curr.x - _originPixel.x) / 2;
    _convex->setPoint(0, sf::Vector2f(static_cast<float>(_originPixel.x - p->outlineSize), static_cast<float>(curr.y - p->outlineSize)));
    _convex->setPoint(1, sf::Vector2f(static_cast<float>(_originPixel.x + len - p->outlineSize), static_cast<float>(_originPixel.y - p->outlineSize)));
    _convex->setPoint(2, sf::Vector2f(static_cast<float>(curr.x - p->outlineSize), static_cast<float>(curr.y - p->outlineSize)));
  
}