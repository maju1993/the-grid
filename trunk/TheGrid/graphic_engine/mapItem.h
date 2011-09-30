#pragma once

enum MapItemType
{
	MapItemTypeCreep = 0,
	MapItemTypePlayer = 1
};

struct Point2D
{
	int x,y;
	Point2D(int a,int b)
	{
		x = a;
		y = b;
	}

	Point2D()
	{
		x = y = 0;
	}
};

class mapItem
{
private:
	Point2D mapPos;			// 0...maxMapX/Y
	Point2D offset;	// -10...10

	// movement data
	Point2D destination;  	// destination  position
	Point2D destinationOffset; // destination offset
	int speed;				// overall speed
	
	// interpolation data ?

public:
	int angle;
	MapItemType type;	
	mapItem(MapItemType typ, int posX,int posY, int speed);

	Point2D getPosition();
	Point2D getOffset();
	Point2D getAngleVec();

	bool doStep(); // automated move func

	void moveTo(int posX,int posY,int destoX=0,int destoY=0);
	void teleportTo(int x,int y);
	void teleportBy(int offsetx,int offsety);
	inline int getSpeed(){return speed;}
};