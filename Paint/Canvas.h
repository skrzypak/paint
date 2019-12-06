#pragma once
#include "Shape.h"
#include <vector>
#include <string>

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
		void generateShape(Shape*);

		std::vector<CApp::Shape*> getShapes();
	};
}


