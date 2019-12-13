#pragma once
#include "Shape.h"

namespace CApp
{
	class Rectangle: 
		public Shape,
		protected sf::RectangleShape
	{
	protected:
		sf::RectangleShape* _rectangle;

	public:
		Rectangle();
		~Rectangle();
		explicit Rectangle(const sf::Vector2i&);
		
		virtual size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t) const override;
		virtual void draw(sf::RenderWindow*) const override;
		virtual void update(const sf::Vector2i&, ShapeProperities*) override;
	};
}

