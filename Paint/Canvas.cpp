#include "Canvas.h"

CApp::Canvas::Canvas()
{
#ifdef _DEBUG
	std::cout << "CApp::Canvas::Canvas()" << std::endl;
#endif
}

CApp::Canvas::~Canvas()
{
#ifdef _DEBUG
	std::cout << "CApp::Canvas::~Canvas()" << std::endl;
#endif
	for (auto& el : __vecShapes)
	{
		delete el;
		el = nullptr;
	}
}

CApp::Shape* CApp::Canvas::generateShape(Shape* s)
{
#ifdef _DEBUG
	std::cout << "CApp::Shape* CApp::Canvas::generateShape(Shape* s)" << std::endl;
#endif
	__vecShapes.push_back(s);
	return s;
}

void CApp::Canvas::refresh(sf::RenderWindow* w, tgui::Gui* g, sf::Color c)
{
#ifdef _DEBUG
	std::cout << "void CApp::Canvas::refresh(sf::RenderWindow* w,  tgui::Gui* g, sf::Color c)" << std::endl;
#endif
	w->clear(c);
	for (const auto& s : __vecShapes) s->draw(w);
	g->draw();
	w->display();
}
