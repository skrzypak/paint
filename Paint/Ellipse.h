#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

namespace CApp
{
	class Ellipse :
		public Shape,
		virtual sf::Shape

	{
        sf::Vector2f __radius;
    public:
        Ellipse() = default;
        explicit Ellipse(const sf::Vector2f&);
        void setRadius(const sf::Vector2f&);
        const sf::Vector2f& getRadius() const;
        virtual size_t getPointCount() const override;
        virtual sf::Vector2f getPoint(std::size_t) const override;

        Ellipse* generate();
        virtual void update();
        ~Ellipse();
	};
}
