#pragma once
#include "Shape.h"

namespace Shapes
{
	class Rectangle: public Shape, protected sf::RectangleShape
	{
	protected:
		sf::RectangleShape* _rectangle;
	public:
		Rectangle() = delete;
		~Rectangle();
		explicit Rectangle(const sf::Vector2i&);

		virtual void update(const sf::Vector2i&, ShapeProperities*) override;
		virtual void draw(sf::RenderWindow*) const override;
		virtual void* getDrawable() const override;
	};
}

