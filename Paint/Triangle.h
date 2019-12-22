#pragma once
#include "Convex.h"

namespace Shapes
{
    /**Klaa obiektu graficznego Triangle*/
    class Triangle: public Convex
    {
    public:
        Triangle() = delete;

        /**Konstruktor klasy Triangle
        * @param const sf::Vector2i& wspolrzedne punktu myszy
        */
        explicit Triangle(const sf::Vector2i&);

        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
    };
}