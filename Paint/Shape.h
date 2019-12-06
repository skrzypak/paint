#pragma once
#include <SFML/Graphics.hpp>

namespace CApp
{ 
	class Shape
	{
	public:
		Shape() = default;
		virtual ~Shape();
		virtual void update() = 0;
	};
}

