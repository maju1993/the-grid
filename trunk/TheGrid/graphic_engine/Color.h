#pragma once
#include "stdafx.h"
#ifndef __COLOR_H__
#define __COLOR_H__

class Color
{
public:
	float r, g, b, a;
	Color(float r, float g, float b, float a):r(r),g(g),b(b),a(a)
	{}
	float* toArray()
	{
		float *col = new float[4];
		col[0] = r;
		col[0] = g;
		col[0] = b;
		col[0] = a;
		return col;
	}
};
#endif