#include "StdAfx.h"
#include "GroundGridLayer.h"


GroundGridLayer::GroundGridLayer(GLShaderManager* shaderMaganer, Grid* _grid)
{
	this->shaderMaganer = shaderMaganer;
	lineBash = 0;
	this->grid = _grid;
	for(int i=0; i<GROUND_GRID_H; i++)
		for(int j=0; j<GROUND_GRID_W; j++)
			groundBatch[i][j] = 0;
	for(int i=0; i<GROUND_GRID_H; i++)
		for(int j=0; j<GROUND_GRID_W; j++)
			stateTable[i][j] = 0;
	
}
void GroundGridLayer::rescanState(int **stateTable)
{
	for(int i=0; i<GROUND_GRID_H; i++)
	{
		for(int j=0; j<GROUND_GRID_W; j++)
		{
			if(this->stateTable[i][j] != stateTable[i][j])
			{
				this->changeFieldColor(j, i, stateTable[i][j]);
				this->stateTable[i][j] = stateTable[i][j];
			}
		}
	}
}
void GroundGridLayer::Init()
{
	//rysowanie lini
	delete lineBash;
	Color defCol(0, 1, 0, 0.9);
	GLfloat* color = defCol.toArray(); 
	lineBash = new GLBatch();
	lineBash->Begin(GL_LINES, 2*(GROUND_GRID_H+GROUND_GRID_W+2));
	for(int i=0; i<=GROUND_GRID_H; i++)
	{
		lineBash->Color4fv(color);
		lineBash->Vertex3f(grid->minX, grid->minY+i*grid->fieldH, grid->lineZ);
		lineBash->Color4fv(color);
		lineBash->Vertex3f(grid->maxX, grid->minY+i*grid->fieldH, grid->lineZ);
	}
	for(int i=0; i<=GROUND_GRID_W; i++)
	{
		lineBash->Color4fv(color);
		lineBash->Vertex3f(grid->minX+i*grid->fieldW, grid->minY, grid->lineZ);
		lineBash->Color4fv(color);
		lineBash->Vertex3f(grid->minX+i*grid->fieldW, grid->maxY, grid->lineZ);
	}
	lineBash->End();
	
	defCol = Color(0.9f, 0.9f, 0.9f, 0.3);
	color = defCol.toArray(); 
	for(int i=0; i<GROUND_GRID_H; i++)
	{
		for(int j=0; j<GROUND_GRID_W; j++)
		{
			groundBatch[i][j] = new GLBatch();
			groundBatch[i][j]->Begin(GL_TRIANGLE_FAN, 4);
			groundBatch[i][j]->Color4fv(color);
			groundBatch[i][j]->Vertex3f(grid->minX+i*grid->fieldW, grid->minY+j*grid->fieldH, grid->groundZ); 
			groundBatch[i][j]->Color4fv(color);
			groundBatch[i][j]->Vertex3f(grid->minX+(i+1)*grid->fieldW, grid->minY+j*grid->fieldH, grid->groundZ);
			groundBatch[i][j]->Color4fv(color);
			groundBatch[i][j]->Vertex3f(grid->minX+(i+1)*grid->fieldW, grid->minY+(j+1)*grid->fieldH, grid->groundZ);
			groundBatch[i][j]->Color4fv(color);
			groundBatch[i][j]->Vertex3f(grid->minX+i*grid->fieldW, grid->minY+(j+1)*grid->fieldH, grid->groundZ);
			groundBatch[i][j]->End();
		}
	}
}
void GroundGridLayer::setFieldColor(int x, int y, Color col)
{
	
	GLfloat* color = col.toArray();
	groundBatch[y][x]->Reset();
	groundBatch[y][x]->Color4fv(color);
	groundBatch[y][x]->Vertex3f(grid->minX+x*grid->fieldW, grid->minY+y*grid->fieldH, grid->groundZ); 
	groundBatch[y][x]->Color4fv(color);
	groundBatch[y][x]->Vertex3f(grid->minX+(x+1)*grid->fieldW, grid->minY+y*grid->fieldH, grid->groundZ);
	groundBatch[y][x]->Color4fv(color);
	groundBatch[y][x]->Vertex3f(grid->minX+(x+1)*grid->fieldW, grid->minY+(y+1)*grid->fieldH, grid->groundZ);
	groundBatch[y][x]->Color4fv(color);
	groundBatch[y][x]->Vertex3f(grid->minX+x*grid->fieldW, grid->minY+(y+1)*grid->fieldH, grid->groundZ);
	groundBatch[y][x]->End();
}
void GroundGridLayer::Render(M3DMatrix44f modelViewMatrix)
{
	shaderMaganer->UseStockShader(GLT_SHADER_SHADED, modelViewMatrix);
	for(int i=0; i<GROUND_GRID_H; i++)
		for(int j=0; j<GROUND_GRID_W; j++)
			groundBatch[i][j]->Draw();
	lineBash->Draw();
}

void GroundGridLayer::Dispose()
{
	delete lineBash;
	for(int i=0; i<GROUND_GRID_H; i++)
		for(int j=0; j<GROUND_GRID_W; j++)
			delete groundBatch[i][j];
	
}

GroundGridLayer::~GroundGridLayer(void)
{
	Dispose();
}
