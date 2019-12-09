#pragma once
#include <iostream>
#include "Canvas.h"
#include "Shape.h"

namespace CMenu
{
	class Controller
	{
	public:
		virtual ~Controller() = 0;
	};
	class Shape
	{
	public:
		virtual CApp::Shape* generate(CApp::Canvas*, const sf::Vector2i&) const = 0;
	};
	template <class T>
	class Type: public Shape
	{
		virtual CApp::Shape* generate(CApp::Canvas* c, const sf::Vector2i& v) const override {
			return c->generateShape(new T(v));
		};
	};
}
