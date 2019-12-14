#pragma once
#include "Polygons.h"

namespace Shapes
{
    class Pentagon: public Polygons
    {
    public:
        Pentagon() = delete;
        explicit Pentagon(const sf::Vector2i&);
    };
}