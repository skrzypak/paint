#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeProperities.h"

#ifdef _DEBUG
#include <iostream>
#endif

namespace Shapes
{ 
	/**Abstrakcyjna klasa potrzebna do zastosowania polimorficznego aktualizowania i rysowania figur geometrycznych na ekranie*/
	class Shape
	{
	protected:
		static const float _PI;

		/*Zawiera wspolrzedne x i y pixela od ktorego bedzie rozpoczete tworzenie obiektu geometrycznego*/
		sf::Vector2i _originPixel;

		/*Zmienna sluzaca do zapietania textury obiektu geometrycznego*/
		sf::Texture* _texture;

	public:
		Shape();
		virtual ~Shape();

		/** Metoda wirtualna aktualizujaca wlasnosci obiektu geometycznego
		* @param const sf::Vector2i& wspolrzedne pixela na ktory wskazuje mysz  
		* @param ShapeProperities* obiekt zawierajacy wszystkie cechy obiektu geometrycznego wybrane z menu
		*/
		virtual void update(const sf::Vector2i&, ShapeProperities*) = 0;
		
		/** Metoda wirtualna dodajaca obiekt geometryczny do obiektu sf::RenderWindow  
		* @param sf::RenderWindow* wskaznik na okno aplikacji
		*/
		virtual void draw(sf::RenderWindow*) const = 0;
		
		/** Metoda wirtualna dodajaca obiekt geometryczny do obiektu sf::RenderTexture
		* @param sf::RenderTexture* wskaznik na texture
		*/
		virtual void draw(sf::RenderTexture*) const = 0;
	};
}

