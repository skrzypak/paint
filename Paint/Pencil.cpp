#include "Pencil.h"

Shapes::Pencil::Pencil(const sf::Vector2i& s): __vecOfPixels(new sf::VertexArray(sf::LineStrip))
{
#ifdef _DEBUG
    std::cout << "CApp::Pencil::Pencil(const sf::Vector2i& s): __vec(new sf::VertexArray(sf::LineStrip))" << std::endl;
#endif
    _originPixel = s;
}

Shapes::Pencil::~Pencil()
{
#ifdef _DEBUG
    std::cout << "CApp::Pencil::~Pencil()" << std::endl;
#endif
    delete __vecOfPixels;
    __vecOfPixels = nullptr;
}

void Shapes::Pencil::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
    std::cout << "void CApp::Pencil::draw(sf::RenderWindow* w) const" << std::endl;
#endif
    w->draw(*__vecOfPixels);
}

void Shapes::Pencil::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void CApp::Pencil::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    __vecOfPixels->append(sf::Vertex(sf::Vector2f(static_cast<float>(curr.x), static_cast<float>(curr.y)), p->fillColor));
}