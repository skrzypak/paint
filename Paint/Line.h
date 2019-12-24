#pragma once
#include "Rectangle.h"

namespace Shapes
{
	/**Klasa obiektu graficznego Line*/
	class Line: public Rectangle
	{
	public:
		Line() = delete;
		
		/**Konstruktor klasy Line
	    * @param const sf::Vector2i& wspolrzedne punktu myszy
	    */
		explicit Line(const sf::Vector2i&);

		virtual void update(const sf::Vector2i&, ShapeProperities*) override;
	};
}

