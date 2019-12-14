#pragma once
#include "Convex.h"

namespace Shapes
{
    class Triangle: public Convex
    {
    public:
        Triangle() = delete;
        explicit Triangle(const sf::Vector2i&);

        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
    };
}