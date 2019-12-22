#pragma once
#include "Shape.h"
#include "AppSettings.h"
#include <TGUI/TGUI.hpp>

#ifdef _DEBUG
#include <iostream>
#endif

/**Klasa zawierajca informacje na temat narysowanych obiektow przez uzytkownika na ekranie*/
class Canvas
{
	/**Wektor zawierajacy wskazniki na figury geometryczne*/
	std::vector<Shapes::Shape*> __vecOfShapes;
public:

	/**Konstruktor klasy Canvas*/
	Canvas();
	~Canvas();

	/** Metoda ktora dodaje wskaznik na wygenerowany obiekt geometryczny do wektora __vecOfShapes 
	* @param Shapes::Shape* wskaznik na wygenerowany obiekt geometryczny
	* @return Shapes::Shpae* zwraca wskaznik na wygenerowany obiekt geometryczny
	*/
	Shapes::Shape* putGenerateShape(Shapes::Shape*);

	/** Metoda ktora odswieza zawartosc ekranu aplikacji
	* @param sf::RenderWindow* wskaznik na obiekt sf::RenderWindow
	* @param tgui::Gui* wskaznik na gui, zawiera widgety z biblioteki TGui 
	*/
	void refresh(sf::RenderWindow*, tgui::Gui*);

	/** Metoda ktora zapisuje ksztalty do pliku o rozszerzeniu .png, .jpg lub .bmp
	* @param sf::RenderWindow* wskaznik na obiekt sf::RenderWindow
	* @param const std::string& nazwa rozszerzenia pliku: ".png", ".jpg" lub ".bmp"
	* @return sciezke gdzie zostal zapisany plik
	* @warning jesli rozszerzenie jest inne niz .png, .jpg lub .bmp plik nie zostanie utworzony
	*/
	std::string saveToImage(sf::RenderWindow*, const std::string&);
	
	/** Metoda ktora usuwa ostani dodany obiekt graficzny do canvasu
	* @warning nie odswiaza ekranu
	*/
	void removeLast();
};