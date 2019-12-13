#pragma once
#include "Canvas.h"
#include "Shape.h"
#include "Custom.h"
#include "ShapeProperities.h"
#include <SFML/Graphics.hpp>

#ifdef DEBUG
#include <iostream>
#endif

class Controller
{
	class Shape
	{
	public:
		virtual CApp::Shape* generate(CApp::Canvas*, const sf::Vector2i&) const = 0;
	};

	template <class SHAPE>
	class Type: public Shape
	{
		virtual CApp::Shape* generate(CApp::Canvas* c, const sf::Vector2i& v) const override;
	};

	Controller::Shape* __shape;
	ShapeProperities* __properites;

public:
	Controller();
	~Controller();
	template <class SHAPE> void setShape();
	Controller::Shape* getShapeController();
	ShapeProperities* getProperites();
	void setFillColor(sf::Color);
	void setOutlineColor(sf::Color);
	void setOutlineSize(float);
	void reverseColors();
	void setTexture(std::string = "");
	void clearTexture();
};

template<class SHAPE>
inline void Controller::setShape()
{
	delete __shape;
	__shape = new Controller::Type<SHAPE>;
};

template<class SHAPE>
inline CApp::Shape* Controller::Type<SHAPE>::generate(CApp::Canvas* c, const sf::Vector2i& v) const
{
	return c->generateShape(new SHAPE(v));
};
