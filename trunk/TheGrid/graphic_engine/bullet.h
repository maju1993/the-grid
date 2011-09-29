#pragma once


class Bullet
{
public:
	Point2D position;
	Point2D offset;
	Bullet(int posX,int posY,int offsetX,int offsetY);
	Bullet(Point2D pos,Point2D off);
};