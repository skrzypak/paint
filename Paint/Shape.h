#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeProperities.h"

#ifdef _DEBUG
#include <iostream>
#endif

namespace CApp
{ 
	class Shape: protected sf::Shape
	{
	protected:
		static const float _PI;
		sf::Vector2i _startXY;
		sf::Texture* _texture;
	public:
		Shape();

		// Polymorphism - polimorfistyczne zaktualizowanie figury geometrycznej
		virtual void update(const sf::Vector2i&, ShapeProperities*) = 0;
		virtual void draw(sf::RenderWindow*) const = 0;

		// Funkcje wirtualne sf::Shape potrzebne do generowania niestandardowych figur geometrycznych
		virtual size_t getPointCount() const = 0;
		virtual sf::Vector2f getPoint(std::size_t) const = 0;
		virtual ~Shape();
	};
}

