#pragma once
#include "Vertex.h"

namespace Shapes
{
    class Pencil: public Vertex
    {
    public:
        Pencil() = delete;
        explicit Pencil(const sf::Vector2i&);
       
        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
    };
}