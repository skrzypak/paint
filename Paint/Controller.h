#pragma once
#include <iostream>
#include "Canvas.h"
#include "Shape.h"

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
		virtual CApp::Shape* generate(CApp::Canvas* c, const sf::Vector2i& v) const override {
			return c->generateShape(new SHAPE(v));
		};
	};

	Controller::Shape* __shape;

public:

	Controller() : __shape(new Controller::Type<CApp::Rectangle>) {};
	
	~Controller() {
		delete __shape;
		__shape = nullptr;
	};

	template <class SHAPE>
	void changeShapeController() {
		delete __shape;
		__shape = new Controller::Type<SHAPE>;
	};

	Controller::Shape* getShapeController() {
		return __shape;
	};
};