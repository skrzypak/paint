#include "Rectangle.h"

Shapes::Rectangle::Rectangle(const sf::Vector2i& s): _rectangle(new sf::RectangleShape), Shapes::Shape()
{
#ifdef _DEBUG
	std::cout << "Shapes::Rectangle::Rectangle(const sf::Vector2i& s): __rectangle(new sf::RectangleShape), shapes::Shape()" << std::endl;
#endif
	_originPixel = s;
	_rectangle->setPosition(sf::Vector2f(_originPixel));
}

Shapes::Rectangle::~Rectangle()
{
#ifdef _DEBUG
	std::cout << "Shapes::Rectangle::~Rectangle()" << std::endl;
#endif
	if (_rectangle != nullptr)
	{
		delete 	_rectangle;
		_rectangle = nullptr;
	}
}

void Shapes::Rectangle::draw(sf::RenderWindow* w) const
{
#ifdef _DEBUG
	std::cout << "void Shapes::Rectagnle::draw(sf::RenderWindow* w) const" << std::endl;
#endif
	w->draw(*_rectangle);
}

void* Shapes::Rectangle::getDrawable() const
{
#ifdef _DEBUG
	std::cout << "void* Shapes::Rectangle::getDrawable() const" << std::endl;
#endif
	return _rectangle;
}

void Shapes::Rectangle::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
	std::cout << "void Shapes::Rectangle::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
	_rectangle->setSize(sf::Vector2f(static_cast<float>(curr.x - _originPixel.x - p->outlineSize), static_cast<float>(curr.y - _originPixel.y - p->outlineSize)));
	_rectangle->setFillColor(p->primaryColor);
	_rectangle->setOutlineColor(p->secondaryColor);
	_rectangle->setOutlineThickness(p->outlineSize);
	*_texture = (*p->texture);
	_rectangle->setTexture(_texture);
}