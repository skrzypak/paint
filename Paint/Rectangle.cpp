#include "Rectangle.h"
#include <iostream>

CApp::Rectangle::Rectangle()
{
	std::cout << "CApp::Rectangle::Rectangle()" << std::endl;
}

CApp::Rectangle* CApp::Rectangle::generate()
{
	std::cout << "CApp::Rectangle* CApp::Rectangle::generate()" << std::endl;
	return new CApp::Rectangle;
}

void CApp::Rectangle::update()
{
	std::cout << "void CApp::Rectangle::update()" << std::endl;
}

CApp::Rectangle::~Rectangle()
{
	std::cout << "CApp::Rectangle::~Rectangle()" << std::endl;
}
