#pragma once
#include "Shape.h"

namespace CApp
{
	class Polygons: public Shape
	{
        sf::Vector2f* __radius;
        unsigned int __pointCount;
    
    public:
        Polygons() = delete;
        explicit Polygons(unsigned int);
        
        virtual ~Polygons();
        virtual std::size_t getPointCount() const override;
        virtual sf::Vector2f getPoint(std::size_t) const override;
        virtual void* getDrawable() const = 0;
        
        sf::Vector2f* getRadius() const;
        void setRadius(const sf::Vector2f&);
        void update(const sf::Vector2i&, ShapeProperities*);
	};
}