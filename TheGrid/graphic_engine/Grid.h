#pragma once

const int GROUND_GRID_H = GRID_START_H;
const int GROUND_GRID_W = GRID_START_W;

class Grid
{
public:
	GLfloat minX, minY;
	GLfloat maxX, maxY;
	GLfloat fieldW, fieldH;
	GLfloat lineZ;
	GLfloat groundZ;

	int gridTable[GROUND_GRID_H][GROUND_GRID_W];

	//pobierania pozycji na wspolrzednych grafiki w zaleznosci od podanych wspolrzednych logiki
	GLfloat *getPosition(int gridX, int gridY, int offsetX, int offsetY)
	{
		GLfloat *pos = new GLfloat[3];
		pos[0] = minX+gridX*this->fieldW + fieldW/2 + offsetX*(this->fieldW/20);
		pos[1] = maxY-gridY*this->fieldH - fieldH/2 + offsetY*(this->fieldH/20);
		pos[2] = groundZ;

		return pos;
	}

	Grid(GLfloat minX, GLfloat maxX, GLfloat minY, GLfloat maxY, GLfloat lineZ, GLfloat groundZ);
	~Grid(void);
};

