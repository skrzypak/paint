#pragma once
#include "AppSettings.h"

struct ShapeProperities
{
	sf::Color fillColor;
	sf::Color outlineColor;
	sf::Texture* texture;
	float outlineSize;

	ShapeProperities() : fillColor(DEFAULT_FILL_COLOR), outlineColor(DEFAULT_OUTLINE_COLOR), outlineSize(DEFAULT_OUTLINE_SIZE), texture(new sf::Texture)
	{
#ifdef DEBUG
		std::cout << "Controller::ShapeProperities::ShapeProperities(): fillColor(DEFAULT_FILL_COLOR), outlineColor(DEFAULT_OUTLINE_COLOR), outlineSize(DEFAULT_OUTLINE_SIZE), texture(new sf::Texture)" << std::endl;
#endif 
	};

	~ShapeProperities()
	{
#ifdef DEBUG
		std::cout << "~ShapeProperities()" << std::endl;
#endif 
		if (texture != nullptr)
		{
			delete texture;
			texture = nullptr;
		}
	}
};

