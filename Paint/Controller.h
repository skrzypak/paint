#pragma once
#include "Canvas.h"
#include "ShapesHeader.h"
#include "ShapeProperities.h"
#include "AppSettings.h"
#include <SFML/Graphics.hpp>

#ifdef _DEBUG
#include <iostream>
#endif

/**Klasa bedca warstwa posredniczaca miedzy menu aplikacji a klasa canvas*/
class Controller
{
	/** Klasa abstrakcyjna ktory sluzy do utworzenie kontrolera Controller::Shape*/
	class Shape
	{
	public:
		virtual Shapes::Shape* generate(Canvas*, const sf::Vector2i&) const = 0;
	};

	/**Klasa zapamietujaca wybrany typ obiektu z menu - sluzy w razie potrzeby do wygenerowania tego obiektu na ekranie*/
	template <class SHAPE>
	class Type: public Shape
	{
		virtual Shapes::Shape* generate(Canvas* c, const sf::Vector2i& v) const override;
	};

	/**Wskaznik sluzacy do zapamietania wybranej figury z menu*/
	Controller::Shape* __activeShape;

	/**Wskaznik sluzaca do zapamietania wybranych parametrow figury z menu */
	ShapeProperities* __activeProperites;

	/**Wskaznik na obiekt canvas */
	Canvas* __canvas;

	/**Wskaznik na okieno aplikacji*/
	sf::RenderWindow* __window;

	/**Wskaznik na obiekt zawierajacy widgety z TGui*/
	tgui::Gui* __gui;

public:
	Controller() = delete;

	/** Konstruktor klasy Controller
	* @param sf::RenderWindow* wskaznik na okienko aplikacji
	* @param tgui::Gui* wskaznik na obiekt ktory zawiera widgety z biblioteki TGui
	*/
	Controller(sf::RenderWindow*, tgui::Gui*);
	~Controller();

	/** Metoda ktory sluzy do pobrania aktywnej figury wybranej przez urzytkownika w menu
	*@return Controller::Shape* zwraca wskaznik na kontroler figury
	*/
	Controller::Shape* getShapeController();

	/** Metoda ktory sluzy do pobrania aktwynych cech figury wybranych przez urzytkownika z menu
	*@return ShapeProperities* zwraca wskaznik na obiekt zawierajacy wybrane parametry figury geometrycznej przez urzytkownika z menu
	*/
	ShapeProperities* getShapeProperites();

	/** Metoda sluzaca do pobrania wskaznika na obiekt klasy Canvas
	* @return zwraca wskaznik na obiekt Canvas
	*/
	Canvas* getActiveCanvas();

	/**Metoda ustawiajaca  kontroler Shape na odpowidni obiket geometryczny*/
	template <class SHAPE> void setShape();
	
	/** Metoda ktora sluzy do ustawiania parametru - primaryColor (kolor wypelnienia figury) w ShapeProperites wybranego z menu
	* @param sf::Color - kolor
	*/
	void setFillColor(sf::Color);
	
	/** Metoda ktora sluzy do ustawiania parametru - secondaryColor (kolor obramowania figury) w ShapeProperites wybranego z menu
	* @param sf::Color - kolor
	*/
	void setOutlineColor(sf::Color);

	/** Metoda ktora sluzy do ustawiania parametru - outlineSize (grubosci obramowania) w ShapeProperites wybranego z menu
	* @param sf::Color - kolor
	*/
	void setOutlineSize(float);

	/**Metoda zamieniajaca kolor wypelninia i obramowania figury geometycznej*/
	void reverseColors();

	/**Metoda sluzaca do ustawinia wybranej textury przez uzytkownia z menu
	* @parm std::string = "" - sciezka do textury - pliku graficznego
	*/
	void setTexture(std::string = "");

	/** Metoda ktory sluzy do wykonia opcji 'Textutre/-' z menu*/
	void clearTexture();

	/** Metoda sluzaca do odswierzenia zawartosci ekranu zdefiniowanego w czasie tworzenia obiektu*/
	void refreshView();

	/** Metoda sluzaca do odswierzenia zawartosci ekranu
	* @param sf::RenderWindow* wskaznik na obiekt ekranu aplikacji
	* @parm tgui::Gui* wskaznik na obiekt zawierajacy widgety z biblioteki TGui
	*/
	void refreshView(sf::RenderWindow*, tgui::Gui*);

	/** Metoda ktory sluzy do wykonia opcji 'Clear' z menu*/
	void resetCanvas();
	
	/**Metoda ktora sluzy do wykonia opcji 'Save' z menu*/
	void saveToFile();

	/**Metoda ktora sluzy do wykonania opcji 'Undo' z menu*/
	void removeLastShape();
};

template<class SHAPE>
inline void Controller::setShape()
{
#ifdef _DEBUG
	std::cout << "template<class SHAPE> inline void Controller::setShape()" << std::endl;
#endif
	delete __activeShape;
	__activeShape = new Controller::Type<SHAPE>;
};

template<class SHAPE>
inline Shapes::Shape* Controller::Type<SHAPE>::generate(Canvas* c, const sf::Vector2i& v) const
{
#ifdef _DEBUG
	std::cout << "template<class SHAPE> inline Shapes::Shape * Controller::Type<SHAPE>::generate(Canvas * c, const sf::Vector2i & v) const" << std::endl;
#endif
	return c->putGenerateShape(new SHAPE(v));
};
