#include "Canvas.h"

CApp::Canvas::Canvas()
{
}

CApp::Canvas::~Canvas()
{
	for (auto el : __shapes)
	{
		delete el;
		el = nullptr;
	}
}

void CApp::Canvas::generate(std::string s)
{
	Shape* shape;
	if (s == "Rectangle") {
		shape = new Rectangle;
		__shapes.push_back(shape);
	}	
}

std::vector<CApp::Shape*> CApp::Canvas::getShapes()
{
	return __shapes;
}

