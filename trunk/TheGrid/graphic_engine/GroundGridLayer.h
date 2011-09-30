#pragma once
#include "ILayer.h"


class GroundGridLayer :
	public ILayer
{
private:
	GLShaderManager* shaderMaganer;
	GLBatch *lineBash;
	GLBatch *groundBatch[GROUND_GRID_H][GROUND_GRID_W];
	int stateTable[GROUND_GRID_H][GROUND_GRID_W];
public:
	Grid* grid;
	//zmienia kolor pola w gridzie
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
	//Przeskanowanie tebali stanów i odpowiednie ustawienie kolorów
	void rescanState(int **stateTable);
	//ustawia kolor odpowiedniego pola w gridzie
	void setFieldColor(int x, int y, Color col);

	void Init();
	void Render(M3DMatrix44f modelViewMatrix);
	void Dispose();
	GroundGridLayer(GLShaderManager *shaderMaganer, Grid* _grid);
	virtual ~GroundGridLayer(void);
};

