#pragma once
#include <SFML/Graphics.hpp>

namespace CApp
{ 
	class Shape
	{
	public:
		Shape() = default;
		virtual ~Shape();
		// Polymorphism - polimorfistyczne zaktualizowanie figury geometrycznej
		virtual void update() = 0;
	};
}

