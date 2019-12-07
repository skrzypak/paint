#pragma once
#include "Shape.h"
#include <SFML/Window.hpp>
#include <vector>

class Shape;

namespace CApp
{
	class Canvas
	{
		sf::RenderWindow* __window;
		std::vector<Shape*> __shapes;
		std::vector<Shape*> __getShapes();
	public:
		Canvas();
		~Canvas();

		// Polymorphism - polimorfistyczne stworzenie nowej figury geometrycznej
		void generateShape(Shape*);

		Shape* getLastShape();
		void refresh();
		sf::RenderWindow* getWindow();
	};
}


