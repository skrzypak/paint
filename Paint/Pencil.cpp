#include "Pencil.h"

Shapes::Pencil::Pencil(const sf::Vector2i& s): Vertex(sf::LineStrip)
{
#ifdef _DEBUG
    std::cout << "Shapes::Pencil::Pencil(const sf::Vector2i& s): Vertex()" << std::endl;
#endif
    _originPixel = s;
}

void Shapes::Pencil::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void Shapes::Pencil::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    _vecOfPixels->append(sf::Vertex(sf::Vector2f(static_cast<float>(curr.x), static_cast<float>(curr.y)), p->primaryColor));
}