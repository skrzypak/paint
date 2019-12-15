#include "Vertex.h"

Shapes::Vertex::Vertex(sf::PrimitiveType t): _vecOfPixels(new sf::VertexArray(t))
{
#ifdef _DEBUG
    std::cout << "Shapes::Vertex::Vertex(sf::PrimitiveType t): _vecOfPixels(new sf::VertexArray(t))" << std::endl;
#endif
}

Shapes::Vertex::~Vertex()
{
#ifdef _DEBUG
    std::cout << "Shapes::Vertex::~Vertex()" << std::endl;
#endif
    if (_vecOfPixels != nullptr)
    {
        delete _vecOfPixels;
        _vecOfPixels = nullptr;
    }
}

void Shapes::Vertex::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
    std::cout << "void Shapes::Vertex::draw(sf::RenderWindow* w) const" << std::endl;
#endif
    w->draw(*_vecOfPixels);
}