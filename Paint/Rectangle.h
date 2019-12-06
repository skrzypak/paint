#pragma once
#include "Shape.h"

namespace CApp
{
	class Rectangle: 
		public Shape 
	{
	public:
		Rectangle();
		virtual void update();
		~Rectangle();
	};
}

