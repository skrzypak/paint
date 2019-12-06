#include "Rectangle.h"
#include <iostream>

CApp::Rectangle::Rectangle()
{
	std::cout << "CApp::Rectangle::Rectangle()" << std::endl;
}

void CApp::Rectangle::update()
{
	std::cout << "void CApp::Rectangle::update()" << std::endl;
}

CApp::Rectangle::~Rectangle()
{
}
