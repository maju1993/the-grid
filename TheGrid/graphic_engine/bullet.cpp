#include "stdafx.h"
#include "bullet.h"

bool Bullet::doStep() // ruch liniowy z podzialem szybkosci dwukierunkowej zaleznie od sily.
{
	float speedX,speedY;
	float wsp;

	if ((mapPos.x == destination.x) &&(mapPos.y == destination.y)&&(offset.x == destinationOffset.x)&&(offset.y == destinationOffset.y))
		return true;

	speedX = bulletSpeed;// * wsp;
	speedY = bulletSpeed;//(speed - speed*wsp);

	

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
	
	if ((mapPos.x<0) || (mapPos.x>LogicLayer::getI()->gridWidth-1)||(mapPos.y<0)||(mapPos.y>LogicLayer::getI()->gridHeight-1))
	{
		return true;
	}
	return false;
};