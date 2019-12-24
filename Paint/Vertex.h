#pragma once
#include "Shape.h"

namespace Shapes
{
    /**Klasa abstrakcyjna posredniczaca medzy klasa Shapes::Shape a figura utworzona za pomoca sf::Vertex*/
    class Vertex: public Shape
    {
    protected:
        /* wektor ktory posiada wszystkie wierzcholki figury geometrycznej od danym sf::PrimitiveType */
        sf::VertexArray* _vecOfPixels;
    public:
        Vertex() = delete;

        /**Konstruktor klasy Vertex
        * @param sf::PrimitiveType - tryb w jaki sposob maja byc laczone punkty - patrz dokumentacja SFML
        */
        explicit Vertex(sf::PrimitiveType);
        virtual ~Vertex();

        virtual void update(const sf::Vector2i&, ShapeProperities*) = 0;
        virtual void draw(sf::RenderWindow*) const override;
        virtual void* getDrawable() const override;
    };
}