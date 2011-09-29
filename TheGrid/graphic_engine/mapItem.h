#pragma once

enum MapItemType
{
	creep = 0,
	player = 1
};

struct Point2D
{
	int x,y;
	Point2D(int a,int b)
	{
		x = a;
		y = b;
	}
};

class mapItem
{
private:
	Point2D mapPos;			// 0...maxMapX/Y
	Point2D offset;	// -10...10
	MapItemType type;	

	// movement data
	Point2D destination;  	// destination  position
	int speed;				// overall speed

	// interpolation data ?

public:
	mapItem(MapItemType typ, int posX,int posY,int speed);	

	Point2D getPosition();
	Point2D getOffset();
	float getAngle();


	void moveTo(int posX,int posY);
	void teleportTo(int x,int y);
};