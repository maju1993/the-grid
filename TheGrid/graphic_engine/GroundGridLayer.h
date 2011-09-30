#pragma once
#include "ILayer.h"

//Warstwa odpowiedzialna za wyswietlanie podloza
class GroundGridLayer :
	public ILayer
{
private:
	//shader manager
	GLShaderManager* shaderMaganer;
	//konternet z liniami do renderowania
	GLBatch *lineBash;
	//konternery z kwadratami do renderowania
	GLBatch *groundBatch[GROUND_GRID_H][GROUND_GRID_W];
	//tablica stanow poszczegolnych pól
	int stateTable[GROUND_GRID_H][GROUND_GRID_W];
public:
	//informacje o siatce
	Grid* grid;
	//zmienia kolor pola w gridzie
	void changeFieldColor(int x, int y, int state)
	{
		Color *col;
		switch(state)
		{
		case 1:
			col = new Color(1, 0, 0, 1);
		case 0:
		default:
			col = new Color(0.9f, 0.9f, 0.9f, 1);
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

