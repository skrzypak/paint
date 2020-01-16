#include "Canvas.h"
#include <windows.h>

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
		if (el != nullptr)
		{
			delete el;
			el = nullptr;
		}
	}
}

Shapes::Shape* Canvas::putGenerateShape(Shapes::Shape* s)
{
#ifdef _DEBUG
	std::cout << "Shape* Canvas::putGenerateShape(Shape* s)" << std::endl;
#endif
	__vecOfShapes.push_back(s);
	return s;
}

Canvas& Canvas::operator+=(Shapes::Shape* s)
{
#ifdef _DEBUG
	std::cout << "Canvas& Canvas::operator+=(const Shapes::Shape * s)" << std::endl;
#endif
	this->__vecOfShapes.push_back(s);
	return *this;
}

void Canvas::refresh(sf::RenderWindow* w, tgui::Gui* g)
{
#ifdef _DEBUG
	std::cout << "void Canvas::refresh(sf::RenderWindow* w,  tgui::Gui* g)" << std::endl;
#endif
	w->clear(DEFAULT_CANVAS_COLOR);
	for (const auto& s : __vecOfShapes) s->draw(w);
	g->draw();
	w->display();
}

std::string Canvas::saveToImage(sf::RenderWindow* w, const std::string& path)
{
#ifdef _DEBUG
	std::cout << "std::string Canvas::saveToFile(sf::RenderWindow* w, const std::string& path, const std::string& ext)" << std::endl;
#endif
	sf::RenderTexture tmp;
	tmp.create(w->getSize().x, w->getSize().y);
	sf::RectangleShape background;
	background.setFillColor(DEFAULT_CANVAS_COLOR);
	background.setSize({static_cast<float>(w->getSize().x), static_cast<float>(w->getSize().y)});

	tmp.draw(background);
	for (const auto& s : __vecOfShapes) s->draw(&tmp);

	const sf::Texture& texture = tmp.getTexture();
	
	sf::Image img = texture.copyToImage();
	img.flipVertically();
	img.saveToFile(path);
	
	return path;
}

void Canvas::removeLast()
{
#ifdef _DEBUG
	std::cout << "void Canvas::removeLast()" << std::endl;
#endif
	if (!__vecOfShapes.empty())
	{
		auto el = __vecOfShapes.back();
		delete el;
		el = nullptr;
		__vecOfShapes.pop_back();
	}
}

void Canvas::operator-- (int)
{
#ifdef _DEBUG
	std::cout << "void Canvas::operator-- (int)" << std::endl;
#endif
	Canvas::removeLast();
}

Canvas& Canvas::operator-- ()
{
#ifdef _DEBUG
	std::cout << "Canvas& Canvas::operator-- ()" << std::endl;
#endif
	Canvas::removeLast();
	return *this;
}