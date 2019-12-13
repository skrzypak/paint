#pragma once
#include "Polygons.h"

namespace CApp
{
    class Diamond: public Polygons
    {
    public:
        Diamond() = delete;
        explicit Diamond(const sf::Vector2i&);
        virtual void* getDrawable() const override;
    };
}