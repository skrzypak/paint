#pragma once
#include "Shape.h"

namespace CApp
{
	class Ellipse :
		public Shape
	{
        sf::Vector2f __radius;
    public:
        Ellipse();
        ~Ellipse();

        void setRadius(const sf::Vector2f&);
        const sf::Vector2f& getRadius() const;
        virtual size_t getPointCount() const override;
        virtual sf::Vector2f getPoint(std::size_t) const override;

        virtual void updateShape();
	};
}
