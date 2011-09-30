#include "stdafx.h"
#include "LogicLayer.h"

//graphicsShouldRefreshPlayer
//	bool graphicsShouldRefreshCreeps;
//	bool graphicsShouldRefreshBullets;

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

	void LogicLayer::MovePlayer(int x,int y) // wersja relatywna
	{
		if (x == 1)
			player->teleportTo(player->getPosition().x+player->getSpeed(),player->getPosition().y);
		if (x == -1)
			player->teleportTo(player->getPosition().x-player->getSpeed(),player->getPosition().y);
		if (y == 1)
			player->teleportTo(player->getPosition().x,player->getPosition().y+player->getSpeed());
		if (y == -1)
			player->teleportTo(player->getPosition().x,player->getPosition().y-player->getSpeed());
		if ((x!=0) ||(y!=0))
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