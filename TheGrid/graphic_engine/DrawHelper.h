#pragma once
#include "stdafx.h"
#include "Grid.h"

class DrawHelper
{
public:
	static void drawTriangle(GLBatch &batch,
		GLfloat r, GLfloat g, GLfloat b, GLfloat a, Grid &grid)
	{
		batch.Begin(GL_TRIANGLES, 3);
		batch.Vertex3f(-grid.fieldW/2, 0, -0.1f);
		batch.Color4f(r, g, b, a);
		batch.Vertex3f(grid.fieldW/2, 0, -0.1f);
		batch.Color4f(r, g, b, a);
		batch.Vertex3f(0, grid.fieldH/2, -0.5f);
		batch.Color4f(r, g, b, a);
		batch.End();
	}
};