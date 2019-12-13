#include "Custom.h"

CApp::Custom::Custom(const sf::Vector2i& s): __vec(new sf::VertexArray(sf::LineStrip))
{
#ifdef _DEBUG
    std::cout << "CApp::Custom::Custom(const sf::Vector2i& s): __vec(new sf::VertexArray(sf::LineStrip))" << std::endl;
#endif
    _startXY = s;
}

CApp::Custom::~Custom()
{
#ifdef _DEBUG
    std::cout << "CApp::Custom::~Custom()" << std::endl;
#endif
    delete __vec;
    __vec = nullptr;
}

std::size_t CApp::Custom::getPointCount() const
{
#ifdef _DEBUG
    std::cout << "std::size_t CApp::Custom::getPointCount() const" << std::endl;
#endif
    return 4;
}

sf::Vector2f CApp::Custom::getPoint(std::size_t index) const
{
#ifdef _DEBUG
    std::cout << "sf::Vector2f CApp::Custom::getPoint(std::size_t index) const" << std::endl;
#endif
    return sf::Vector2f();
}

void CApp::Custom::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
    std::cout << "void CApp::Custom::draw(sf::RenderWindow* w) const" << std::endl;
#endif
    w->draw(*__vec);
}

void CApp::Custom::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
    std::cout << "void CApp::Custom::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
    __vec->append(sf::Vertex(sf::Vector2f(static_cast<float>(curr.x), static_cast<float>(curr.y)), p->fillColor));
}