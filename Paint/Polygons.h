#pragma once
#include "Shape.h"

namespace Shapes
{
    /**Klasa abstrakcyjna sluzaca do tworzenia wielokatow*/
	class Polygons: public Shape, protected sf::Shape
	{
        /**Prywatny wskaznik na zmienna ktory zawiera informacje na temat promieni*/
        sf::Vector2f* __radius;

        /**Zmienna prywatna zawierajaca ilosc punktow figury*/
        unsigned int __pointCount;
    public:
        Polygons() = delete;

        /**Konstruktor klasy Polygons
        * @param unsigned int ilosc wierzcholkow
        */
        explicit Polygons(unsigned int);

        /**Destruktor wirtualny klasy Polygons*/
        virtual ~Polygons() = 0;

        /** Metoda wirtualna z klasy sf::Shape ktora zwraca ilosc punktow figury geometycznej */
        virtual std::size_t getPointCount() const override;

        /** Metoda wirtualna z klasy sf::Shape ktora zwraca wspolrzedne punktu o podanym indeksie
        * @param std::size_t numer indeksu
        * @retun sf::Vector2f zwraca wspolrzedne x, y punku
        */
        virtual sf::Vector2f getPoint(std::size_t) const override;

        virtual void update(const sf::Vector2i&, ShapeProperities*) override;
        virtual void draw(sf::RenderWindow*) const override;
        virtual void draw(sf::RenderTexture*) const override;      

        /** Metoda ktora sluzy do pobrania wartosci z prywatnej zmiennej __radius
        @return sf::Vector2f wskaznik na strukture ktora zawiera dlugosic promieni
        */
        sf::Vector2f* getRadius() const;

        /** Metoda ktora sluzy do zapisu wartosci promeini w prywatnej zmiennej __radius
        * *param sf::Vector2f wartosci promieni x, y
        */
        void setRadius(const sf::Vector2f&);
	};
}