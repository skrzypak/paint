#pragma once
#include "Shape.h"

namespace Shapes
{
    class Vertex: public Shape
    {
    protected:
        sf::VertexArray* _vecOfPixels;
    public:
        Vertex() = delete;
        explicit Vertex(sf::PrimitiveType);
        virtual ~Vertex();

        virtual void update(const sf::Vector2i&, ShapeProperities*) = 0;
        virtual void draw(sf::RenderWindow*) const override;
        virtual void* getDrawable() const override;
    };
}