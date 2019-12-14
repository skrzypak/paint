#pragma once
#include "Shape.h"
#include <TGUI/TGUI.hpp>

#ifdef _DEBUG
#include <iostream>
#endif

class Canvas
{
	std::vector<Shapes::Shape*> __vecOfShapes;
public:
	Canvas();
	~Canvas();

	Shapes::Shape* generateShape(Shapes::Shape*);
	void refresh(sf::RenderWindow*, tgui::Gui*, sf::Color = sf::Color::Black);
};