#pragma once
#include "Polygons.h"

namespace Shapes
{
    /**Klasa obiektu graficznego Diamond*/
    class Diamond: public Polygons
    {
    public:
        Diamond() = delete;

        /**Konstruktor klasy Diamond
        * @param const sf::Vector2i& wspolrzedne punktu myszy
        */
        explicit Diamond(const sf::Vector2i&);
    };
}