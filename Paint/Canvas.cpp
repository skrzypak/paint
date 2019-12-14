#include "Canvas.h"

Canvas::Canvas()
{
#ifdef _DEBUG
	std::cout << "Canvas::Canvas()" << std::endl;
#endif
}

Canvas::~Canvas()
{
#ifdef _DEBUG
	std::cout << "Canvas::~Canvas()" << std::endl;
#endif
	for (auto& el : __vecOfShapes)
	{
		delete el;
		el = nullptr;
	}
}

Shapes::Shape* Canvas::generateShape(Shapes::Shape* s)
{
#ifdef _DEBUG
	std::cout << "Shape* Canvas::generateShape(Shape* s)" << std::endl;
#endif
	__vecOfShapes.push_back(s);
	return s;
}

void Canvas::refresh(sf::RenderWindow* w, tgui::Gui* g, sf::Color c)
{
#ifdef _DEBUG
	std::cout << "void Canvas::refresh(sf::RenderWindow* w,  tgui::Gui* g, sf::Color c)" << std::endl;
#endif
	w->clear(c);
	for (const auto& s : __vecOfShapes) s->draw(w);
	g->draw();
	w->display();
}
