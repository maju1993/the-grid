#pragma once

const int GROUND_GRID_H = 10;
const int GROUND_GRID_W = 10;

class Grid
{
public:
	GLfloat minX, minY;
	GLfloat maxX, maxY;
	GLfloat fieldW, fieldH;
	GLfloat lineZ;
	GLfloat groundZ;

	int gridTable[GROUND_GRID_H][GROUND_GRID_W];

	//
	GLfloat *getPosition(int gridX, int gridY, int offsetX, int offsetY)
	{
		GLfloat *pos = new GLfloat[3];
		pos[0] = minX+gridX*this->fieldW + fieldW*(this->fieldW/20);
		pos[1] = minY+gridY*this->fieldH + fieldH*(this->fieldH/20);
		pos[2] = groundZ;
		return pos;
	}


	Grid(GLfloat minX, GLfloat maxX, GLfloat minY, GLfloat maxY, GLfloat lineZ, GLfloat groundZ);
	~Grid(void);
};

