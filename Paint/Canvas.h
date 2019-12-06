#pragma once
#include "Shape.h"
#include <vector>
#include <string>
#include "Rectangle.h"

class Shape;

namespace CApp
{
	class Canvas
	{
		std::vector<CApp::Shape*> __shapes;
	public:
		Canvas();
		~Canvas();
		// Polymorphism - polimorfistyczne stworzenie nowej figury geometrycznej
		void generate(Shape*);
		std::vector<CApp::Shape*> getShapes();
	};
}


