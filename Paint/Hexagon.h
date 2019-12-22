#pragma once
#include "Polygons.h"

namespace Shapes
{
	/**Klasa obiektu graficznego Hexagon*/
	class Hexagon: public Polygons
	{
    public:
        Hexagon() = delete;

		/**Konstruktor klasy Hexagon
	    * @param const sf::Vector2i& wspolrzedne punktu myszy
	    */
        explicit Hexagon(const sf::Vector2i&);
	};
}