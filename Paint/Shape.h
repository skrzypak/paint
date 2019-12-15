#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeProperities.h"

#ifdef _DEBUG
#include <iostream>
#endif

namespace Shapes
{ 
	class Shape
	{
	protected:
		static const float _PI;
		sf::Vector2i _originPixel;
		sf::Texture* _texture;
	public:
		Shape();
		virtual ~Shape();

		virtual void update(const sf::Vector2i&, ShapeProperities*) = 0;
		virtual void draw(sf::RenderWindow*) const = 0;
		virtual void* getDrawable() const = 0;
	};
}

