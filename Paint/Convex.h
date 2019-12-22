#pragma once
#include "Shape.h"

namespace Shapes
{
    /**Klasa abstrakcyjna posredniczaca medzy klasa Shapes::Shape a figura utworzona za pomoca sf::ConvexShape*/
    class Convex: public Shape
    {
    protected:
        /**Chroniony wskaznik na obiekt sf::ConvexShape*/
        sf::ConvexShape* _convex;
    public:
        Convex();
        virtual ~Convex();

        virtual void update(const sf::Vector2i&, ShapeProperities*) = 0;
        virtual void draw(sf::RenderWindow*) const override;
        virtual void* getDrawable() const override;
    };
}