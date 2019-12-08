#pragma once
#include "Polygons.h"

namespace CApp
{
	class Hexagon: public Polygons
	{
    public:
        Hexagon() = delete;
        explicit Hexagon(const sf::Vector2i&);
        virtual void* getDrawable() const override;
	};
}