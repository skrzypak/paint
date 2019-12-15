#include "Polygons.h"

Shapes::Polygons::Polygons(unsigned int p): __radius(new sf::Vector2f(0.f, 0.f)), __pointCount(p), Shapes::Shape()
{
#ifdef _DEBUG
    std::cout << "Shapes::Polygons::Polygons(unsigned int p): __radius(new sf::Vector2f(0.f, 0.f)), __pointCount(p), Shapes::Shape()" << std::endl;
#endif
}

Shapes::Polygons::~Polygons()
{
#ifdef _DEBUG
    std::cout << "Shapes::Polygons::~Polygons()" << std::endl;
#endif
    delete __radius;
    __radius = nullptr;
}

std::size_t Shapes::Polygons::getPointCount() const
{
#ifdef _DEBUG
    std::cout << "std::size_t Shapes::Polygons::getPointCount() const" << std::endl;
#endif
    return __pointCount;
}

sf::Vector2f Shapes::Polygons::getPoint(std::size_t index) const
{
#ifdef _DEBUG
    std::cout << "sf::Vector2f Shapes::Polygons::getPoint(std::size_t index) const" << std::endl;
#endif
    float 
        a = index * 2 * _PI / getPointCount() - _PI / 2,
        x = std::cos(a) * (*__radius).x,
        y = std::sin(a) * (*__radius).y;
    return sf::Vector2f((*__radius).x + x, (*__radius).y + y);
}

void Shapes::Polygons::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
    std::cout << "void Shapes::Polygons::draw(sf::RenderWindow* w) const" << std::endl;
#endif
    w->draw(*const_cast<Polygons*>(this));
}

sf::Vector2f* Shapes::Polygons::getRadius() const
{
#ifdef _DEBUG
    std::cout << "sf::Vector2f* Shapes::Polygons::getRadius() const" << std::endl;
#endif
    return __radius;
}

void Shapes::Polygons::setRadius(const sf::Vector2f& r)
{
#ifdef _DEBUG
    std::cout << "void Shapes::Polygons::setRadius(const sf::Vector2f& r)" << std::endl;
#endif
    *__radius = r;
}

void Shapes::Polygons::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void Shapes::Polygons::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    setRadius(sf::Vector2f(static_cast<float>((curr.x - _originPixel.x - p->outlineSize) / 2), static_cast<float>((curr.y - _originPixel.y - p->outlineSize) / 2)));
    sf::Shape::setFillColor(p->fillColor);
    sf::Shape::setOutlineColor(p->outlineColor);
    sf::Shape::setOutlineThickness(p->outlineSize);
    *_texture = (*p->texture);
    sf::Shape::setTexture(_texture);
    sf::Shape::update();
}