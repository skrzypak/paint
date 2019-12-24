#include "Convex.h"

Shapes::Convex::Convex() : _convex(new sf::ConvexShape), Shapes::Shape()
{
#ifdef _DEBUG
    std::cout << "Shapes::Convex::Convex(): _convex(new sf::ConvexShape), Shapes::Shape()" << std::endl;
#endif
}

Shapes::Convex::~Convex()
{
#ifdef _DEBUG
    std::cout << "Shapes::Convex::~Convex()" << std::endl;
#endif
    if (_convex != nullptr)
    {
        delete _convex;
        _convex = nullptr;
    }
}

void* Shapes::Convex::getDrawable() const
{
#ifdef _DEBUG
    std::cout << "void* Shapes::Convex::getDrawable() const" << std::endl;
#endif
    return _convex;
}

inline void Shapes::Convex::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
    std::cout << "inline void Shapes::Convex::draw(sf::RenderWindow* w) const" << std::endl;
#endif
    w->draw(*_convex);
}
