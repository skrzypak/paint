#pragma once
#include "Polygons.h"
#include <SFML/Graphics.hpp>

namespace CApp
{
    class Ellipse: 
        public Polygons
    {
        Ellipse* __shape;
    public:
        Ellipse() = delete;
        explicit Ellipse(const sf::Vector2i&);
        virtual void* getDrawable() const override;
    };
}