#pragma once
#include "Shape.h"

namespace CApp
{
	class Rectangle: 
		public Shape 
	{
	public:
		Rectangle();
		~Rectangle();
		virtual void updateShape();
		virtual size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t) const override;
	};
}

