#pragma once
#include "Shape.h"

namespace Shapes
{
    class Convex: public Shape
    {
    protected:
        sf::ConvexShape* _convex;
    public:
        Convex();
        virtual ~Convex();

        virtual void update(const sf::Vector2i&, ShapeProperities*) = 0;
        virtual void draw(sf::RenderWindow*) const override;
    };
}