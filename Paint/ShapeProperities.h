#pragma once

class ShapeProperities
{
public:
	sf::Color fillColor;
	sf::Color outlineColor;
	ShapeProperities(): fillColor(sf::Color::White), outlineColor(sf::Color::White)
	{
#ifdef DEBUG
		std::cout << "Controller::ShapeProperities::ShapeProperities(): fillColor(sf::Color::White), outlineColor(sf::Color::White)" << std::endl;
#endif 
	};
};

