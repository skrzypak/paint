#include "Canvas.h"
#include <windows.h>
#include <shlobj.h>

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

std::string Canvas::saveToImage(sf::RenderWindow* w, const std::string& ext)
{
#ifdef _DEBUG
	std::cout << "std::string Canvas::saveToFile(sf::RenderWindow* w, const std::string& ext)" << std::endl;
#endif

	CHAR userPicturePath[MAX_PATH];
	SHGetFolderPath(NULL, CSIDL_MYPICTURES, NULL, SHGFP_TYPE_CURRENT, userPicturePath);

	std::string path = static_cast<std::string>(userPicturePath) + "\\SFML-APP" + ext;

	sf::RenderTexture tmp;
	tmp.create(w->getSize().x, w->getSize().y);
	sf::RectangleShape background;
	background.setFillColor(DEFAULT_CANVAS_COLOR);
	background.setSize({static_cast<float>(w->getSize().x), static_cast<float>(w->getSize().y)});

	tmp.draw(background);
	
	for (const auto& s : __vecOfShapes)
		tmp.draw(*static_cast<sf::Drawable*>(s->getDrawable()));

	const sf::Texture& texture = tmp.getTexture();
	

	sf::Image img = texture.copyToImage();
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