#include "stdafx.h"
#include "mapItem.h"

mapItem::mapItem(MapItemType typ, int posX,int posY,int speed)
{
	mapPos = Point2D(posX,posY);
	offset = Point2D(0,0);
	this->speed = speed;
	this->type = typ;
}

Point2D mapItem::getPosition()
{
	return mapPos;
}

Point2D mapItem::getOffset()
{
	return offset;
}
	
Point2D mapItem::getAngleVec()
{
	return Point2D(destination.x-mapPos.x,destination.y-mapPos.y);
}

// zwraca true jesli wykonal ruch
bool mapItem::doStep() // ruch liniowy z podzialem szybkosci dwukierunkowej zaleznie od sily.
{
	float speedX,speedY;
	float wsp;

	if ((mapPos.x == destination.x) &&(mapPos.y == destination.y)&&(offset.x == destinationOffset.x)&&(offset.y == destinationOffset.y))
		return false;

	if (destination.x>mapPos.x)
	{
		speedX = destination.x - mapPos.x;
	}
	else
		if (destination.x<mapPos.x)
		{
			speedX = mapPos.x-destination.x;
		}
		else
			speedX = 0;
	if (destination.y>mapPos.y)
	{
		speedY = destination.y - mapPos.y;
	}
	else
		if (destination.y<mapPos.y)
		{
			speedY = mapPos.y-destination.y;
		}
		else
		{
			speedY=0;
		}
	wsp = speedX/speedY;
	// mozliwe ze trzeba na odwrot to napisac.
	speedX = speed;// * wsp;
	speedY = speed;//(speed - speed*wsp);

	

	if (destination.x < mapPos.x)
	{
		offset.x-=speedX;
		//mapPos.x -=speedX;
	}
	else
		if (destination.x > mapPos.x)
			offset.x +=speedX;
		else
		{
			if (offset.x > destinationOffset.x)
			{
				if (offset.x - speedX < destinationOffset.x)
					offset.x = destinationOffset.x;
				else
					offset.x -= speedX;
			}
			else
			{
				if (offset.x + speedX > destinationOffset.x)
					offset.x = destinationOffset.x;
				else
					offset.x += speedX;
			}

		}

	if (destination.y < mapPos.y)
		offset.y -=speedY;
	else
		if (destination.y > mapPos.y)
			offset.y +=speedY;
		else
		{
			if (offset.y > destinationOffset.y)
			{
				if (offset.y - speedY < destinationOffset.y)
					offset.y = destinationOffset.y;
				else
					offset.y -= speedY;
			}
			else
			{
				if (offset.y + speedY > destinationOffset.y)
					offset.y = destinationOffset.y;
				else
					offset.y += speedY;
			}

		}
	// normalizacja ruchu
	while (offset.x >10)
	{
		mapPos.x ++;
		offset.x -= 20;
	}
	while (offset.x <-10)
	{
		mapPos.x --;
		offset.x += 20;
	}

	while (offset.y >10)
	{
		mapPos.y ++;
		offset.y -= 20;
	}
	while (offset.y <-10)
	{
		mapPos.y --;
		offset.y += 20;
	}
	
	if (mapPos.x<0)
	{
		mapPos.x = 0;
		offset.x = -10;
	}
	if (mapPos.x>LogicLayer::getI()->gridWidth-1)
	{
		mapPos.x = LogicLayer::getI()->gridWidth-1;
		offset.x = 10;
	}

	if (mapPos.y<0)
	{
		mapPos.y = 0;
		offset.y = -10;
	}
	if (mapPos.y>LogicLayer::getI()->gridHeight-1)
	{
		mapPos.y = LogicLayer::getI()->gridHeight-1;
		offset.y = 10;
	}
	return true;
}

void mapItem::moveTo(int posX,int posY,int destoX,int destoY)
{
	this->destination = Point2D(posX,posY);
	this->destinationOffset = Point2D(destoX,destoY);
}
	
void mapItem::teleportTo(int x,int y)
{
	this->mapPos = Point2D(x,y);
	this->offset = Point2D(0,0);
}