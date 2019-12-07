#pragma once
#include "Shape.h"

namespace CApp
{
	class Rectangle: 
		public Shape,
		protected sf::RectangleShape
	{
		sf::RectangleShape* __shape;
	public:
		Rectangle() = delete;
		explicit Rectangle(const sf::Vector2i&);
		~Rectangle();
		virtual void* getDrawable() const override;
		virtual void updateShape(const sf::Vector2i&) override;
		virtual size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t) const override;
	};
}

