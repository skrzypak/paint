#pragma once
#include "Rectangle.h"

namespace CApp
{
	class Line: public Rectangle
	{
	public:
		Line() = delete;
		~Line();
		explicit Line(const sf::Vector2i&);

		virtual void update(const sf::Vector2i&, ShapeProperities*) override;
	};
}

