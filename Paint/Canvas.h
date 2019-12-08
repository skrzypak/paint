#pragma once
#include "Shape.h"
#include <TGUI/TGUI.hpp>
#include <vector>

#ifdef _DEBUG
#include <iostream>
#endif

class Shape;

namespace CApp
{
	class Canvas
	{
		std::vector<Shape*> __vecShapes;
	public:
		Canvas();
		~Canvas();

		// Polymorphism
		void refresh(sf::RenderWindow*, tgui::Gui*, sf::Color = sf::Color::Black);
		Shape* generateShape(Shape*);
	};
}


