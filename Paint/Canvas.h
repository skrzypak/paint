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
		void generate(std::string);
		std::vector<CApp::Shape*> getShapes();
	};
}


