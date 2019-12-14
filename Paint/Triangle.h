#pragma once
#include "Shape.h"

namespace Shapes
{
    class Triangle: public Shape
    {
        sf::ConvexShape* __convex;
    public:
        Triangle() = delete;
        explicit Triangle(const sf::Vector2i&);
        ~Triangle();

        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
        virtual void draw(sf::RenderWindow*) const override;
    };
}