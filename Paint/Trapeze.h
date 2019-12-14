#pragma once
#include "Convex.h"

namespace Shapes
{
    class Trapeze: public Convex
    {
    public:
        Trapeze() = delete;
        explicit Trapeze(const sf::Vector2i&);
       
        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
    };
}