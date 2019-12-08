#pragma once
#include <SFML/Graphics.hpp>

#ifdef _DEBUG
#include <iostream>
#endif

namespace CApp
{ 
	class Shape: protected sf::Shape
	{
	protected:
		sf::Vector2i _startXY;
	public:
		Shape() = default;

		// Polymorphism - polimorfistyczne zaktualizowanie figury geometrycznej
		virtual void update(const sf::Vector2i&) = 0;
		virtual void* getDrawable() const = 0;

		// Funkcje wirtualne sf::Shape potrzebne do generowania niestandardowych figur geometrycznych
		virtual size_t getPointCount() const = 0;
		virtual sf::Vector2f getPoint(std::size_t) const = 0;
	};
}

