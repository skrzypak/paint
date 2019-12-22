#pragma once
#include "Convex.h"

namespace Shapes
{
    /**Klasa obiektu graficznego Trapeze*/
    class Trapeze: public Convex
    {
    public:
        Trapeze() = delete;

        /**Konstruktor obiektu Trapeze
        * @param const sf::Vector2i& wspolrzedne punktu myszy
        */
        explicit Trapeze(const sf::Vector2i&);
       
        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
    };
}