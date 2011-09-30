#pragma once
#include "stdafx.h"
#include "Grid.h"

class DrawHelper
{
public:
	//generuje wroga badü playera w odpowiednim kolorze
	static void drawTriangle(GLBatch &batch, GLfloat r, GLfloat g, GLfloat b, GLfloat a, Grid &grid)
	{
		Color col(r, g, b, a);
		batch.Begin(GL_TRIANGLE_FAN, 5);
		batch.Color4fv(col.toArray());
		batch.Vertex3f(0, 0, -2*grid.fieldW);
		batch.Color4fv(col.toArray());
		batch.Vertex3f(-grid.fieldW/2, -grid.fieldH/4, grid.groundZ);
		batch.Color4fv(col.toArray());
		batch.Vertex3f(0, grid.fieldH/2, grid.groundZ);
		batch.Color4fv(col.toArray());
		batch.Vertex3f(grid.fieldW/2, -grid.fieldH/4, grid.groundZ);
		batch.Color4fv(col.toArray());
		batch.Vertex3f(-grid.fieldW/2, -grid.fieldH/4, grid.groundZ);
		batch.End();
	}

	//generuje posick w ospowiednim kolorze
	static void drawBullet(GLBatch &batch, GLfloat r, GLfloat g, GLfloat b, GLfloat a, Grid &grid)
	{
		Color col(r, g, b, a);
		batch.Begin(GL_POINTS, 1);
		batch.Color4fv(col.toArray());
		batch.Vertex3f(0, 0, -0.1f);
		batch.End();
	}
};