#pragma once
#include "Shape.h"

namespace CApp
{
    class Triangle: public Shape
    {
        sf::ConvexShape* __convex;

    public:
        Triangle() = delete;
        explicit Triangle(const sf::Vector2i&);
        ~Triangle();

        virtual void update(const sf::Vector2i&, ShapeProperities*) override;

        virtual std::size_t getPointCount() const override;
        virtual sf::Vector2f getPoint(std::size_t) const override;
        virtual void draw(sf::RenderWindow*) const override;
    };
}