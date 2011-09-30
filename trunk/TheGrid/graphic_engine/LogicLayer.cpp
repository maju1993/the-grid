#include "stdafx.h"
#include "LogicLayer.h"


	void LogicLayer::MovePlayer(Point2D newPos)
	{
		player->moveTo(newPos.x,newPos.y);
	}

	void LogicLayer::TeleportPlayer(Point2D newPos)
	{
		player->teleportTo(newPos.x,newPos.y);
	}

	void LogicLayer::addCreep(Point2D pos,int speed)
	{
		creepy.push_back(new mapItem(MapItemTypeCreep,pos.x,pos.y,speed));
	}

	// funkcja do testow dla getoxa!	
	void LogicLayer::siCreepFollowPlayer()
	{
		std::vector<mapItem*>::iterator it;  
		for ( it=creepy.begin() ; it < creepy.end(); it++ )
		{
			(*it)->moveTo(player->getPosition().x,player->getPosition().y);
		}
	}

	void LogicLayer::MovePlayer(float x,float y) // wersja relatywna - rotation, move
	{	
		//player->teleportBy(player->getSpeed()*x, player->getSpeed() *y);//player->getPosition().x,player->getPosition().y-player->getSpeed());
		
		player->angle -= x;
		//jest ruch do przodu
		if(y!=0)
		{
			player->teleportBy(player->getSpeed() * sinf(player->angle * 3.14/180.0) *y , player->getSpeed() * cosf(player->angle* 3.14/180.0)*y);
			player->destination = Point2D(player->getSpeed()*2 * sinf(player->angle * 3.14/180.0) *y , player->getSpeed()*2 * cosf(player->angle* 3.14/180.0)*y);
			Point2D destPos;
			player->destination.x += player->getPosition().x;
			player->destination.y += player->getPosition().y;
		}
		else
		{


		}
		
		

		graphicsShouldRefreshPlayer = true;
	}

	// funkcja
	void LogicLayer::doLogic()
	{
		// wpierw creepy potem player - spowoduje to pewna 'glupote creepow', na dodatek creepy wpierw ruch potem przeliczenie
		std::vector<mapItem*>::iterator it;  
		for ( it=creepy.begin() ; it < creepy.end(); it++ )
		{
			if ((*it)->doStep()) 
				;
				graphicsShouldRefreshCreeps = true;
		}
		siCreepFollowPlayer();

		//if (player->doStep())
			graphicsShouldRefreshPlayer = true;

	}


	void LogicLayer::deinit()
	{
		for (int i=0;i<gridWidth;i++)
			delete [] *grid;
		delete [] grid;
		delete player;
	};