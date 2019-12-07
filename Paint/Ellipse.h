#pragma once
#include "Shape.h"
#include "SFML/Graphics.hpp"

namespace CApp
{
    class Ellipse: 
        public Shape
    {
        sf::Vector2f* __radius;
        Ellipse* __shape;
    protected:
        unsigned int _pointCount;
    public:
        Ellipse() = delete;
        ~Ellipse();
        explicit Ellipse(const sf::Vector2i&);
        virtual std::size_t getPointCount() const override;
        virtual sf::Vector2f getPoint(std::size_t) const override;
        virtual void updateShape(const sf::Vector2i&) override;
        virtual void* getDrawable() const override;
    };
}