#include "Controller.h"

Controller::Controller(): __activeShape(new Controller::Type<DEFAULT_MODE>), __activeProperites(new ShapeProperities), __canvas(new Canvas)
{
#ifdef DEBUG
	std::cout << "Controller::Controller(): __shape(new Controller::Type<DEFAULT_MODE>), __properites(new Controller::ShapeProperities), __canvas(new Canvas)" << std::endl;
#endif 
};

Controller::~Controller()
{
#ifdef DEBUG
	std::cout << "Controller::~Controller()" << std::endl;
#endif 
	delete __activeShape;
	delete __activeProperites;
	delete __canvas;
	__activeShape = nullptr;
	__activeProperites = nullptr;
	__canvas = nullptr;
};

Controller::Shape* Controller::getShapeController()
{
#ifdef DEBUG
	std::cout << "Controller::Shape* Controller::getShapeController() " << std::endl;
#endif 
	return __activeShape;
};

ShapeProperities* Controller::getShapeProperites()
{
#ifdef DEBUG
	std::cout << "Controller::Color Controller::getShapeProperites()" << std::endl;
#endif 
	return __activeProperites;
}

Canvas* Controller::getActiveCanvas()
{
#ifdef DEBUG
	std::cout << "Canvas* Controller::getActiveCanvas()" << std::endl;
#endif 
	return __canvas;
}

void Controller::setFillColor(sf::Color c)
{
#ifdef DEBUG
	std::cout << "void Controller::setFillColor(sf::Color c)" << std::endl;
#endif 
	__activeProperites->fillColor = c;
};

void Controller::setOutlineColor(sf::Color c)
{
#ifdef DEBUG
	std::cout << "void Controller::setOutlineColor(sf::Color c)" << std::endl;
#endif
	__activeProperites->outlineColor = c;
}

void Controller::setOutlineSize(float s)
{
#ifdef DEBUG
	std::cout << "void Controller::setOutlineSize(float s)" << std::endl;
#endif
	__activeProperites->outlineSize = s;
}

void Controller::reverseColors()
{
#ifdef DEBUG
	std::cout << "void Controller::reverseColors()" << std::endl;
#endif
	auto tmp = __activeProperites->fillColor;
	__activeProperites->fillColor = __activeProperites->outlineColor;
	__activeProperites->outlineColor = tmp;
}

void Controller::setTexture(std::string path)
{
#ifdef DEBUG
	std::<< "void Controller::setTexture(std::string path)" << std::endl;
#endif
	__activeProperites->texture->loadFromFile(path);
	__activeProperites->texture->setSmooth(true);
}

void Controller::clearTexture()
{
#ifdef DEBUG
	std:: << "void Controller::clearTexture()" << std::endl;
#endif
	delete __activeProperites->texture;
	__activeProperites->texture = new sf::Texture;
}

void Controller::refreshView(sf::RenderWindow* w, tgui::Gui* g, sf::Color c)
{
#ifdef DEBUG
	std:: << "void Controller::refreshView(sf::RenderWindow* w, tgui::Gui* g, sf::Color c)" << std::endl;
#endif
	__canvas->refresh(w, g, c);
}

void Controller::resetCanvas()
{
#ifdef DEBUG
	std:: << "void Controller::resetCanvas()" << std::endl;
#endif
	delete __canvas;
	__canvas = new Canvas;
}

void Controller::saveToFile()
{
#ifdef DEBUG
	std:: << "void Controller::saveToFile()" << std::endl;
#endif
	// TO DO
	
}

void Controller::loadFromFile()
{
#ifdef DEBUG
	std:: << "void Controller::loadFromFile()" << std::endl;
#endif
	// TO DO
}
