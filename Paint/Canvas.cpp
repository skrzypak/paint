#include "Canvas.h"
#include <iostream>

CApp::Canvas::Canvas()
{
	std::cout << "CApp::Canvas::Canvas()" << std::endl;
}

CApp::Canvas::~Canvas()
{
	std::cout << "CApp::Canvas::~Canvas()" << std::endl;
	for (auto el : __shapes)
	{
		delete el;
		el = nullptr;
	}
}

void CApp::Canvas::generateShape(Shape* s)
{
	std::cout << "void CApp::Canvas::generate(Shape* s)" << std::endl;
	__shapes.push_back(s);
}

CApp::Shape* CApp::Canvas::getLastShape()
{
	std::cout << "CApp::Shape* CApp::Canvas::getLastShape()" << std::endl;
	return __shapes.back();
}

std::vector<CApp::Shape*> CApp::Canvas::getShapes()
{
	std::cout << "std::vector<CApp::Shape*> CApp::Canvas::getShapes()" << std::endl;
	return __shapes;
}

