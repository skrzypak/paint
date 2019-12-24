#pragma once
#include "AppSettings.h"

/**Struktura zawierajaca parametry figury wybrane przez uzytownia z menu*/
struct ShapeProperities
{
	/**Glowny kolor - najczesciej kolor wypelnienia figury*/
	sf::Color primaryColor;

	/**Drugorzedny kolor - najczesciej kolor obramowania figury*/
	sf::Color secondaryColor;

	/**Wskaznik na texture
	* @param NULLPTR - textura nie zostal wybrana
	*/
	sf::Texture* texture;

	/**Rozmiar obramowania figury geometrycznej*/
	float outlineSize;

	ShapeProperities() : primaryColor(DEFAULT_PRIMARY_COLOR), secondaryColor(DEFAULT_SECONDARY_COLOR), outlineSize(DEFAULT_OUTLINE_SIZE), texture(new sf::Texture)
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

