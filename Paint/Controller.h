#pragma once
#include "Canvas.h"
#include "ShapesHeader.h"
#include "ShapeProperities.h"
#include "AppSettings.h"
#include <SFML/Graphics.hpp>

#ifdef _DEBUG
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
	sf::RenderWindow* __window;
	tgui::Gui* __gui;

public:
	Controller() = delete;
	Controller(sf::RenderWindow*, tgui::Gui*);
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
	void refreshView();
	void refreshView(sf::RenderWindow*, tgui::Gui*);
	void resetCanvas();
	void saveToFile(const std::string&);
	void removeLastShape();
};

template<class SHAPE>
inline void Controller::setShape()
{
#ifdef _DEBUG
	std::cout << "template<class SHAPE> inline void Controller::setShape()" << std::endl;
#endif
	delete __activeShape;
	__activeShape = new Controller::Type<SHAPE>;
};

template<class SHAPE>
inline Shapes::Shape* Controller::Type<SHAPE>::generate(Canvas* c, const sf::Vector2i& v) const
{
#ifdef _DEBUG
	std::cout << "template<class SHAPE> inline Shapes::Shape * Controller::Type<SHAPE>::generate(Canvas * c, const sf::Vector2i & v) const" << std::endl;
#endif
	return c->generateShape(new SHAPE(v));
};
