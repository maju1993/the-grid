#pragma once
#include "stdafx.h"

class Color
{
public:
	float r, g, b, a;
	Color(float r, float g, float b, float a):r(r),g(g),b(b),a(a)
	{}
	float* toArray()
	{
		float col[]= {r, g, b, a};
		return col;
	}
};