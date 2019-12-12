#include "Shape.h"

CApp::Shape::Shape(): _texture(new sf::Texture)
{
#ifdef _DEBUG
	std::cout << "CApp::Shape::Shape(): _texture(new sf::Texture)" << std::endl;
#endif
}

CApp::Shape::~Shape()
{
#ifdef _DEBUG
	std::cout << "CApp::Shape::~Shape()" << std::endl;
#endif
	if (_texture != nullptr)
	{
		delete _texture;
		_texture = nullptr;
	}
}
