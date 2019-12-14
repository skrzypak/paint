#pragma once
#include "Shape.h"

namespace Shapes
{
    class Pencil: public Shape
    {
        sf::VertexArray* __vecOfPixels;
    public:
        Pencil() = delete;
        explicit Pencil(const sf::Vector2i&);
        ~Pencil();
       
        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
        virtual void draw(sf::RenderWindow*) const override;
    };
}