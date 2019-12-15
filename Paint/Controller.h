#pragma once
#include "Canvas.h"
#include "ShapesHeader.h"
#include "ShapeProperities.h"
#include "AppSettings.h"
#include <SFML/Graphics.hpp>

#ifdef DEBUG
#include <iostream>
#endif

class Controller
{
	class Shape
	{
	public:
		virtual Shapes::Shape* generate(Canvas*, const sf::Vector2i&) const = 0;
	};

	template <class SHAPE>
	class Type: public Shape
	{
		virtual Shapes::Shape* generate(Canvas* c, const sf::Vector2i& v) const override;
	};

	Controller::Shape* __activeShape;
	ShapeProperities* __activeProperites;
	Canvas* __canvas;

public:
	Controller();
	~Controller();
	Controller::Shape* getShapeController();
	ShapeProperities* getShapeProperites();
	Canvas* getActiveCanvas();
	template <class SHAPE> void setShape();
	void setFillColor(sf::Color);
	void setOutlineColor(sf::Color);
	void setOutlineSize(float);
	void reverseColors();
	void setTexture(std::string = "");
	void clearTexture();
	void refreshView(sf::RenderWindow*, tgui::Gui*, sf::Color = DEFAULT_CANVAS_COLOR);
	void resetCanvas();
	void saveToFile();
	void loadFromFile();
};

template<class SHAPE>
inline void Controller::setShape()
{
	delete __activeShape;
	__activeShape = new Controller::Type<SHAPE>;
};

template<class SHAPE>
inline Shapes::Shape* Controller::Type<SHAPE>::generate(Canvas* c, const sf::Vector2i& v) const
{
	return c->generateShape(new SHAPE(v));
};
