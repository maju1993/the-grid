#include "stdafx.h"
#include "mapObject.h"


MapObject* MapObject::createObject(MapObjectTypes type,int x,int y,int speed, int angle)
{
	MapObject *tmp;
	switch(type)
	{
	case MapObjectTypeCreep:
		tmp = new Creep();
		break;
	case MapObjectTypePlayer:
		tmp = new Player();
		break;
	case MapObjectTypeBullet:
		tmp = new Bullet();
		break;
	}

	return tmp;
}