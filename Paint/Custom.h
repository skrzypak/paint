#pragma once
#include "Shape.h"

namespace CApp
{
    class Custom: public Shape
    {
        sf::VertexArray* __vec;

    public:
        Custom() = delete;
        explicit Custom(const sf::Vector2i&);
        ~Custom();
       
        virtual void update(const sf::Vector2i&, ShapeProperities*) override;

        virtual std::size_t getPointCount() const override;
        virtual sf::Vector2f getPoint(std::size_t) const override;
        virtual void draw(sf::RenderWindow*) const override;
    };
}