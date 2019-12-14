#pragma once
#include "Shape.h"

namespace Shapes
{
    class Trapeze: public Shape
    {
        sf::ConvexShape* __convex;
    public:
        Trapeze() = delete;
        explicit Trapeze(const sf::Vector2i&);
        ~Trapeze();
       
        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
        virtual void draw(sf::RenderWindow*) const override;
    };
}