#pragma once
#include "Polygons.h"

namespace CApp
{
    class Triangle: public Polygons
    {
    public:
        Triangle() = delete;
        explicit Triangle(const sf::Vector2i&);
    };
}