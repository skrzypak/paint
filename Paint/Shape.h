#pragma once
#include <SFML/Graphics.hpp>

namespace CApp
{ 
	class Shape:
		protected virtual sf::Shape
	{
	protected:
		sf::Vector2i _startPixel;
	public:
		sf::RectangleShape* __shape; // Do testu

		Shape() = default;
		virtual ~Shape();

		// Polymorphism - polimorfistyczne zaktualizowanie figury geometrycznej i obiektu windows
		virtual void updateShape(const sf::Vector2i&) = 0;

		// Funkcje wirtualne sf::Shape potrzebne do generowania niestandardowych figur geometrycznych
		virtual size_t getPointCount() const = 0;
		virtual sf::Vector2f getPoint(std::size_t) const = 0;
	};
}

