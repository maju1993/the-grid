#include "StdAfx.h"
#include "GroundGridLayer.h"


GroundGridLayer::GroundGridLayer(Grid* _grid)
{
	lineBash = 0;
	this->grid = _grid;
	for(int i=0; i<GROUND_GRID_H; i++)
		for(int j=0; j<GROUND_GRID_W; j++)
			groundBatch[j][i] = 0;
	
}

void GroundGridLayer::Init()
{
	//rysowanie lini
	delete lineBash;
	GLfloat* color = (GLfloat*)clWhiteSmoke; 
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
	
	color = (GLfloat*)clLimeGreen; 
	for(int i=0; i<GROUND_GRID_H; i++)
	{
		for(int j=0; j<GROUND_GRID_W; j++)
		{
			groundBatch[j][i] = new GLBatch();
			groundBatch[j][i]->Begin(GL_TRIANGLE_FAN, 4);
			groundBatch[j][i]->Color4fv(color);
			groundBatch[j][i]->Vertex3f(grid->minX+i*grid->fieldW, grid->minY+j*grid->fieldH, grid->groundZ); 
			groundBatch[j][i]->Color4fv(color);
			groundBatch[j][i]->Vertex3f(grid->minX+(i+1)*grid->fieldW, grid->minY+j*grid->fieldH, grid->groundZ);
			groundBatch[j][i]->Color4fv(color);
			groundBatch[j][i]->Vertex3f(grid->minX+(i+1)*grid->fieldW, grid->minY+(j+1)*grid->fieldH, grid->groundZ);
			groundBatch[j][i]->Color4fv(color);
			groundBatch[j][i]->Vertex3f(grid->minX+i*grid->fieldW, grid->minY+(j+1)*grid->fieldH, grid->groundZ);
			groundBatch[j][i]->End();
		}
	}
}
void GroundGridLayer::setFieldColor(int x, int y, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	GLfloat color[] = {r, g, b, a}; 
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
GLfloat* GroundGridLayer::getPosition(int gridX, int gridY, int offsetX, int offsetY)
{
	GLfloat *pos = new GLfloat[3];

	pos[0] = grid->minX+gridX*this->grid->fieldW + grid->fieldW/2 + offsetX*(this->grid->fieldW/20);
	pos[1] = grid->maxY-gridY*this->grid->fieldH - grid->fieldH/2 + offsetY*(this->grid->fieldH/20);
	pos[2] = grid->groundZ;
	return pos;
}
void GroundGridLayer::Render(M3DMatrix44f modelViewMatrix)
{
	for(int i=0; i<GROUND_GRID_H; i++)
		for(int j=0; j<GROUND_GRID_W; j++)
			groundBatch[j][i]->Draw();
	lineBash->Draw();
}

void GroundGridLayer::Dispose()
{
	delete lineBash;
	for(int i=0; i<GROUND_GRID_H; i++)
		for(int j=0; j<GROUND_GRID_W; j++)
			delete groundBatch[j][i];
	
}

GroundGridLayer::~GroundGridLayer(void)
{
	Dispose();
}
