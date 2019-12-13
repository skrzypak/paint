#include "Line.h"
#include <cmath>

CApp::Line::~Line()
{
#ifdef _DEBUG
	std::cout << "CApp::Line::~Line()" << std::endl;
#endif
}

CApp::Line::Line(const sf::Vector2i& s): CApp::Rectangle(s)
{
#ifdef _DEBUG
	std::cout << "CApp::Line::Line(const sf::Vector2i& s): CApp::Rectangle(s)" << std::endl;
#endif
}

void CApp::Line::update(const sf::Vector2i& curr, ShapeProperities* p)
{
#ifdef _DEBUG
	std::cout << "void CApp::Line::update(const sf::Vector2i& curr, ShapeProperities* p)" << std::endl;
#endif
	_rectangle->setFillColor(p->fillColor);
	
	const sf::Vector2f
		VA = { static_cast<float>(curr.x - _startXY.x), 0 },
		VB = { static_cast<float>(curr.x - _startXY.x), static_cast<float>(curr.y - _startXY.y) };

	float
		lenLine = sqrt(powf(VA.x, 2.0) + powf(VB.y, 2.0)),
		lenVA = sqrt(VA.x * VA.x + VA.y * VA.y),
		lenVB = sqrt(VB.x * VB.x + VB.y * VB.y),
		VAoVB = VA.x * VB.x + VA.y * VB.y,
		cosVAVB = lenVA * lenVB == 0 ? 0 : VAoVB / (lenVA * lenVB),
		angle = acos(cosVAVB) * (180 / _PI);
	
	if (curr.x > _startXY.x&& curr.y < _startXY.y) angle = -angle;
	else if (curr.x <= _startXY.x && curr.y <= _startXY.y) angle += 180;
	else if (curr.x < _startXY.x && curr.y > _startXY.y) angle = -angle + 180;

	_rectangle->setRotation(angle);
	_rectangle->setSize(sf::Vector2f(lenLine, static_cast<float>(p->outlineSize == 0 ? 1 : p->outlineSize)));
}