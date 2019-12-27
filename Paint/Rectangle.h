#pragma once
#include "Shape.h"

namespace Shapes
{
	/**Klasa obiektu graficznego Rectangle*/
	class Rectangle: public Shape, protected sf::RectangleShape
	{
	protected:
		/**Wskaznik na obiekt utworzony za pomoca sf::RectangleShape*/
		sf::RectangleShape* _rectangle;
	public:
		Rectangle() = delete;
		~Rectangle();

		/**Konstruktor klasy Rectangle
	    * @param const sf::Vector2i& wspolrzedne punktu myszy
		*/
		explicit Rectangle(const sf::Vector2i&);

		virtual void update(const sf::Vector2i&, ShapeProperities*) override;
		virtual void draw(sf::RenderWindow*) const override;
		virtual void draw(sf::RenderTexture*) const override;
	};
}

