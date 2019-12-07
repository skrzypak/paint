#pragma once
#include "Shape.h"
#include <SFML/Window.hpp>
#include <vector>

class Shape;

namespace CApp
{
	struct WindowSettings
	{
		sf::VideoMode videoMode;
		std::string title;
		sf::ContextSettings contextSettings;
		WindowSettings() = delete;
		WindowSettings(sf::VideoMode vm, std::string t, sf::ContextSettings cs):
			videoMode(vm),
			title(t),
			contextSettings(cs)
		{}
	};

	class Canvas
	{
		sf::RenderWindow* __window;
		std::vector<Shape*> __shapes;
		std::vector<Shape*> __getShapes();
	public:
		Canvas() = delete;
		Canvas(const WindowSettings&);
		~Canvas();

		// Polymorphism - polimorfistyczne stworzenie nowej figury geometrycznej
		void generateShape(Shape*);

		Shape* getLastShape();
		void refresh();
		sf::RenderWindow* getWindow();
	};
}


