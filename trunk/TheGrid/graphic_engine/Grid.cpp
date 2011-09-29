#include "StdAfx.h"
#include "Grid.h"


Grid::Grid(GLfloat minX, GLfloat maxX, GLfloat minY, GLfloat maxY, GLfloat lineZ, GLfloat groundZ)
{
	this->minX = minX;
	this->minY = minY;
	this->maxX = maxX;
	this->maxY = maxY;
	this->lineZ = lineZ;
	this->groundZ = groundZ;
	this->fieldW = (abs(minX) + abs(maxX))/GROUND_GRID_W;
	this->fieldH = (abs(minY) + abs(maxY))/GROUND_GRID_H;
	
}

Grid::~Grid(void)
{
}
