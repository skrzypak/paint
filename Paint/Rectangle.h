#pragma once
#include "Shape.h"

namespace CApp
{
	class Rectangle: 
		public Shape 
	{
	public:
		Rectangle();
		Rectangle* generate();
		virtual void update();
		~Rectangle();
	};
}

