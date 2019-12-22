#pragma once
#include "Polygons.h"

namespace Shapes
{
    /**Klasa obiektu graficznego Pentagon*/
    class Pentagon: public Polygons
    {
    public:
        Pentagon() = delete;

        /**Konstruktor klasy Pentagon
        * @param const sf::Vector2i& wspolrzedne punktu myszy
        */
        explicit Pentagon(const sf::Vector2i&);
    };
}