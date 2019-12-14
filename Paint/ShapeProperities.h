#pragma once

struct ShapeProperities
{
	sf::Color fillColor;
	sf::Color outlineColor;
	sf::Texture* texture;
	float outlineSize;

	ShapeProperities() : fillColor(sf::Color::White), outlineColor(sf::Color::Black), outlineSize(1), texture(new sf::Texture)
	{
#ifdef DEBUG
		std::cout << "Controller::ShapeProperities::ShapeProperities(): fillColor(sf::Color::White), outlineColor(sf::Color::Black), outlineSize(1), texture(new sf::Texture)" << std::endl;
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

