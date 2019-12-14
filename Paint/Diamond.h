#pragma once
#include "Polygons.h"

namespace Shapes
{
    class Diamond: public Polygons
    {
    public:
        Diamond() = delete;
        explicit Diamond(const sf::Vector2i&);
    };
}