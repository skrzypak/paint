#pragma once
#include "Polygons.h"

namespace CApp
{
    class Ellipse: public Polygons
    {
    public:
        Ellipse() = delete;
        explicit Ellipse(const sf::Vector2i&);
    };
}