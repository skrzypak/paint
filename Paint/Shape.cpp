#include "Shape.h"

const float Shapes::Shape::_PI = 3.141592654f;

Shapes::Shape::Shape(): _texture(new sf::Texture)
{
#ifdef _DEBUG
	std::cout << "Shapes::Shape::Shape(): _texture(new sf::Texture)" << std::endl;
#endif
}

Shapes::Shape::~Shape()
{
#ifdef _DEBUG
	std::cout << "Shapes::Shape::~Shape()" << std::endl;
#endif
	if (_texture != nullptr)
	{
		delete _texture;
		_texture = nullptr;
	}
}
