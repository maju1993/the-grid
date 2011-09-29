#pragma once
#include "ILayer.h"


class GroundGridLayer :
	public ILayer
{
private:
	GLBatch *lineBash;
	GLBatch *groundBatch[GROUND_GRID_H][GROUND_GRID_W];
public:
	Grid* grid;

	GroundGridLayer(Grid* _grid);
	void setFieldColor(int x, int y, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	inline GLfloat *getPosition(int gridX, int gridY, int offsetX, int offsetY);

	void Init();
	void Render(M3DMatrix44f modelViewMatrix);
	void Dispose();
	virtual ~GroundGridLayer(void);
};

