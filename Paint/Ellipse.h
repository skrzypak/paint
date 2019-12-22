#pragma once
#include "Polygons.h"

namespace Shapes
{
    /**Klasa obiektu graficznego Ellipse*/
    class Ellipse: public Polygons
    {
    public:
        Ellipse() = delete;
        
        /**Konstruktor klasy Ellipse
        * @param const sf::Vector2i& wspolrzedne punktu myszy
        */
        explicit Ellipse(const sf::Vector2i&);
    };
}