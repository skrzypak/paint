#pragma once
#include "Polygons.h"

namespace CApp
{
    class Pentagon: public Polygons
    {
    public:
        Pentagon() = delete;
        explicit Pentagon(const sf::Vector2i&);
    };
}