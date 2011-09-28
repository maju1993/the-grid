#pragma once

const int GRID_HEIGHT = 10;
const int GRID_WIDTH = 10;

class Grid
{
public:
	GLfloat z, minX, minY, offsetX, offsetY;
	int gridTable[GRID_HEIGHT][GRID_WIDTH];
	GLBatch *gridBach;
	GLfloat bashLines[GRID_HEIGHT+1][GRID_WIDTH+1][2][3];
	GLfloat bashLinesColor[GRID_HEIGHT+1][GRID_WIDTH+1][2][4];
	GLBatch gridFieldBatch[GRID_HEIGHT][GRID_WIDTH];

	void setFieldColor(int x, int y, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
	{
		gridFieldBatch[y][x].Reset();
		gridFieldBatch[y][x].Color4f(r,g,b,a);
		gridFieldBatch[y][x].Vertex3f(minX+x*offsetX, minY+y*offsetY, z); 
		gridFieldBatch[y][x].Color4f(r,g,b,a);
		gridFieldBatch[y][x].Vertex3f(minX+(x+1)*offsetX, minY+y*offsetY, z);
		gridFieldBatch[y][x].Color4f(r,g,b,a);
		gridFieldBatch[y][x].Vertex3f(minX+(x+1)*offsetX, minY+(y+1)*offsetY, z);
		gridFieldBatch[y][x].Color4f(r,g,b,a);
		gridFieldBatch[y][x].Vertex3f(minX+x*offsetX, minY+(y+1)*offsetY, z);
		gridFieldBatch[y][x].End();
	}

	GLBatch *generateBashGrid(GLfloat minX, GLfloat maxX, GLfloat minY, GLfloat maxY, GLfloat zLines, GLfloat z);

	void renderFields()
	{
		for(int i=0; i<GRID_HEIGHT; i++)
			for(int j=0; j<GRID_WIDTH; j++)
				gridFieldBatch[j][i].Draw();
		gridBach->Draw();
	}

	GLfloat *getColorField(int x, int y)
	{
		return (GLfloat *)clBlack;
	}
	GLfloat *getPosition(int gridX, int gridY, int offsetX, int offsetY)
	{
		GLfloat *pos = new GLfloat[3];
		pos[0] = minX+gridX*this->offsetX + offsetX*(this->offsetX/20);
		pos[1] = minY+gridY*this->offsetY + offsetY*(this->offsetY/20);
		pos[2] = z;
		return pos;
	}


	Grid(void);
	~Grid(void);
};
class Field
{
	int content;
	GLfloat *vertex;
};

