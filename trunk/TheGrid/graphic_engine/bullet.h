#pragma once


class Bullet
{
public:
	static const int bulletSpeed = 10;
	Point2D mapPos;
	Point2D offset;
	Point2D destination;
	Point2D destinationOffset;
	Bullet(int posX,int posY,int offsetX,int offsetY,int destX,int destY)
	{
		mapPos =  Point2D(posX,posY);
		offset = Point2D(offsetX,offsetY);
		destination = Point2D(destX,destY);
		destinationOffset = Point2D(0,0);
	}
	Bullet(Point2D pos,Point2D off,Point2D dest)
	{
		destination = dest;
		mapPos = pos;
		offset = off;
		destinationOffset = Point2D(0,0);
	}

// true == wyszlo poza zakres
// false = siedzi w zakresie, ma dalej istniec
bool doStep();

};