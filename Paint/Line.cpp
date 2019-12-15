#include "Line.h"

Shapes::Line::Line(const sf::Vector2i& s): Shapes::Rectangle(s)
{
#ifdef _DEBUG
	std::cout << "Shapes::Line::Line(const sf::Vector2i& s): CApp::Rectangle(s)" << std::endl;
#endif
}

void Shapes::Line::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
	std::cout << "void Shapes::Line::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
	_rectangle->setFillColor(p->fillColor);
	
	const sf::Vector2f
		VA = { static_cast<float>(curr.x - _originPixel.x), 0 },
		VB = { static_cast<float>(curr.x - _originPixel.x), static_cast<float>(curr.y - _originPixel.y) };

	float
		lenLine = sqrt(powf(VA.x, 2.0) + powf(VB.y, 2.0)),
		lenVA = sqrt(VA.x * VA.x + VA.y * VA.y),
		lenVB = sqrt(VB.x * VB.x + VB.y * VB.y),
		VAoVB = VA.x * VB.x + VA.y * VB.y,
		cosVAVB = lenVA * lenVB == 0 ? 0 : VAoVB / (lenVA * lenVB),
		angle = acos(cosVAVB) * (180 / _PI);
	
	if (curr.x > _originPixel.x&& curr.y < _originPixel.y) angle = -angle;
	else if (curr.x <= _originPixel.x && curr.y <= _originPixel.y) angle += 180;
	else if (curr.x < _originPixel.x && curr.y > _originPixel.y) angle = -angle + 180;

	_rectangle->setRotation(angle);
	_rectangle->setSize(sf::Vector2f(lenLine, static_cast<float>(p->outlineSize == 0 ? 1 : p->outlineSize)));
}