#include "StdAfx.h"
#include "Grid.h"

GLBatch *Grid::generateBashGrid(GLfloat minX, GLfloat maxX, GLfloat minY, GLfloat maxY, GLfloat zLines, GLfloat z)
{
	int totalLines = 2*(GRID_HEIGHT+1)*(GRID_WIDTH+1);
	GLfloat *ver = new GLfloat[totalLines*2*3];
	
	GLfloat offsetX = (abs(minX) + abs(maxX))/GRID_WIDTH;
	GLfloat offsetY = (abs(minY) + abs(maxY))/GRID_HEIGHT;
	this->minX = minX;
	this->minY = minY;
	this->z = z;
	this->offsetX = offsetX;
	this->offsetY = offsetY;
	GLBatch *bach = new GLBatch();
	bach->Begin(GL_LINES, totalLines);

	for(int i=0; i<=GRID_HEIGHT; i++)
	{
		bach->Color4f(1,1,1,1);
		bach->Vertex3f(minX, minY+i*offsetY, zLines);
		bach->Color4f(1,1,1,1);
		bach->Vertex3f(maxX, minY+i*offsetY, zLines);
	}
	for(int i=0; i<=GRID_WIDTH; i++)
	{
		bach->Color4f(1,1,1,1);
		bach->Vertex3f(minX+i*offsetX, minY, zLines);
		bach->Color4f(1,1,1,1);
		bach->Vertex3f(minX+i*offsetX, maxY, zLines);
	}
	for(int i=0; i<GRID_HEIGHT; i++)
	{
		for(int j=0; j<GRID_WIDTH; j++)
		{
			gridFieldBatch[j][i].Begin(GL_TRIANGLE_FAN, 4);
			gridFieldBatch[j][i].Color4f(0,1,0,1);
			gridFieldBatch[j][i].Vertex3f(minX+i*offsetX, minY+j*offsetY, z); 
			gridFieldBatch[j][i].Color4f(0,1,0,1);
			gridFieldBatch[j][i].Vertex3f(minX+(i+1)*offsetX, minY+j*offsetY, z);
			gridFieldBatch[j][i].Color4f(0,1,0,1);
			gridFieldBatch[j][i].Vertex3f(minX+(i+1)*offsetX, minY+(j+1)*offsetY, z);
			gridFieldBatch[j][i].Color4f(0,1,0,1);
			gridFieldBatch[j][i].Vertex3f(minX+i*offsetX, minY+(j+1)*offsetY, z);

			gridFieldBatch[j][i].End();
		}
	}

	//for(int i=0; i<=this->GRID_HEIGHT; i++)
	//{
	//	for(int j=0; j<=this->GRID_WIDTH; j++)
	//	{
	//		bashLines[j][i][0][0] = minX+i*offsetX;
	//		bashLines[j][i][0][1] = minY+j*offsetY;
	//		bashLines[j][i][0][2] = z;
	//		if(i%2==0)	//pozioma
	//		{
	//			bashLines[j][i][1][0] = minX+(i+1)*offsetX;
	//			bashLines[j][i][1][1] = minY+j*offsetY;
	//			bashLines[j][i][1][2] = z;
	//		}else	 //pionowa
	//		{
	//			
	//			bashLines[j][i][1][0] = minX+i*offsetX;
	//			bashLines[j][i][1][1] = minY+(j+1)*offsetY;
	//			bashLines[j][i][1][2] = z;
	//		}
	//	}
	//}
	//bach->CopyVertexData3f((GLfloat*)bashLines);
	gridBach = bach;
	gridBach->End();

	return gridBach;
}


Grid::Grid(void)
{
	gridBach = 0;
	for(int i=0; i<GRID_HEIGHT; i++)
	{
		for(int j=0; j<GRID_WIDTH; j++)
		{
			gridTable[j][i] = 0;
		}

	}
}


Grid::~Grid(void)
{
}
