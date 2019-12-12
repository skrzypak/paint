#pragma once

class ShapeProperities
{
public:
	sf::Color fillColor;
	sf::Color outlineColor;
	sf::Texture* texture;
	float outlineSize;
	ShapeProperities(): fillColor(sf::Color::White), outlineColor(sf::Color::White), outlineSize(1), texture(new sf::Texture)
	{
#ifdef DEBUG
		std::cout << "Controller::ShapeProperities::ShapeProperities(): fillColor(sf::Color::White), outlineColor(sf::Color::White), outlineSize(0), texture(new sf::Texture)" << std::endl;
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

