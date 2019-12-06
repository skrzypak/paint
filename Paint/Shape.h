#pragma once
#include <SFML/Graphics.hpp>

namespace CApp
{ 
	class Shape:
		public sf::Shape
	{
	public:
		Shape() = default;
		virtual ~Shape();

		// Polymorphism - polimorfistyczne zaktualizowanie figury geometrycznej
		virtual void updateShape() = 0;

		// Funkcje wirtualne sf::Shape potrzebne do generowania niestandardowych figur geometrycznych
		virtual size_t getPointCount() const = 0;
		virtual sf::Vector2f getPoint(std::size_t) const = 0;
	};
}

