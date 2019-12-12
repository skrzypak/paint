#include "Controller.h"

Controller::Controller(): __shape(new Controller::Type<CApp::Rectangle>), __properites(new ShapeProperities)
{
#ifdef DEBUG
	std::cout << "Controller::Controller(): __shape(new Controller::Type<CApp::Rectangle>), __properites(new Controller::ShapeProperities)" << std::endl;
#endif 
};

Controller::~Controller()
{
#ifdef DEBUG
	std::cout << "Controller::~Controller()" << std::endl;
#endif 
	delete __shape;
	delete __properites;
	__shape = nullptr;
	__properites = nullptr;
};

Controller::Shape* Controller::getShapeController()
{
#ifdef DEBUG
	std::cout << "Controller::Shape* Controller::getShapeController() " << std::endl;
#endif 
	return __shape;
};

ShapeProperities* Controller::getProperites()
{
#ifdef DEBUG
	std::cout << "Controller::Color Controller::getProperites()" << std::endl;
#endif 
	return __properites;
};

void Controller::setFillColor(sf::Color c)
{
#ifdef DEBUG
	std::cout << "void Controller::setFillColor(sf::Color c)" << std::endl;
#endif 
	__properites->fillColor = c;
};

void Controller::setOutlineColor(sf::Color c)
{
#ifdef DEBUG
	std::cout << "void Controller::setOutlineColor(sf::Color c)" << std::endl;
#endif
	__properites->outlineColor = c;
}

void Controller::setOutlineSize(float s)
{
#ifdef DEBUG
	std::cout << "void Controller::setOutlineSize(float s)" << std::endl;
#endif
	__properites->outlineSize = s;
}

void Controller::reverseColors()
{
#ifdef DEBUG
	std::cout << "void Controller::reverseColors()" << std::endl;
#endif
	auto tmp = __properites->fillColor;
	__properites->fillColor = __properites->outlineColor;
	__properites->outlineColor = tmp;
}

void Controller::setTexture(std::string path)
{
#ifdef DEBUG
	std::<< "void Controller::setTexture(std::string path)" << std::endl;
#endif
	(*__properites->texture).loadFromFile(path);
}

void Controller::clearTexture()
{
#ifdef DEBUG
	std:: << "void Controller::clearTexture()" << std::endl;
#endif
	delete __properites->texture;
	__properites->texture = new sf::Texture;
}
