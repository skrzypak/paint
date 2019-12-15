#pragma once
#include "Shape.h"
#include "AppSettings.h"
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
	void refresh(sf::RenderWindow*, tgui::Gui*);
	std::string saveToImage(sf::RenderWindow*, const std::string&);
	void removeLast();
};