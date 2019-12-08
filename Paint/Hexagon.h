#pragma once
#include "Polygons.h"
#include <SFML/Graphics.hpp>

namespace CApp
{
	class Hexagon:
		public Polygons
	{
        Hexagon* __shape;
    public:
        Hexagon() = delete;
        explicit Hexagon(const sf::Vector2i&);
        virtual void* getDrawable() const override;
	};
}