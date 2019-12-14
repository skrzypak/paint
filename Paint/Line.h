#pragma once
#include "Rectangle.h"

namespace Shapes
{
	class Line: public Rectangle
	{
	public:
		Line() = delete;
		explicit Line(const sf::Vector2i&);
		~Line();

		virtual void update(const sf::Vector2i&, ShapeProperities*) override;
	};
}

