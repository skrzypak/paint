#pragma once
#include "Vertex.h"

namespace Shapes
{
    /**Klasa obiektu graficznego Pencil*/
    class Pencil: public Vertex
    {
    public:
        Pencil() = delete;

        /**Konstruktor klasy Pencil
        * @param const sf::Vector2i& wspolrzedne punktu myszy
        */
        explicit Pencil(const sf::Vector2i&);
       
        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
    };
}