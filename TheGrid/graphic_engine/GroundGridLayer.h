#pragma once
#include "ILayer.h"


class GroundGridLayer :
	public ILayer
{
private:
	GLBatch *lineBash;
	GLBatch *groundBatch[GROUND_GRID_H][GROUND_GRID_W];
	int **stateTable;
public:
	Grid* grid;

	void changeFieldColor(int x, int y, int state)
	{
		Color *col;
		switch(state)
		{
		case 0:
		default:
			col = new Color(0, 1, 0, 1);
			break;
		}
		setFieldColor(x, y, *col);
	}
	
	void rescanState(int **stateTable);
	void setFieldColor(int x, int y, Color col);
	inline GLfloat *getPosition(int gridX, int gridY, int offsetX, int offsetY);

	void Init();
	void Render(M3DMatrix44f modelViewMatrix);
	void Dispose();
	GroundGridLayer(Grid* _grid);
	virtual ~GroundGridLayer(void);
};

