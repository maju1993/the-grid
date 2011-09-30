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
			
			if (bullets.size()>0)
			{
				moveBullets();
				graphicsShouldRefreshBullets = true;
			}

			doSteering();
	}

	void LogicLayer::moveBullets()
	{
		/*
		std::vector<Bullet*>::iterator it,tmp;
		for (it = bullets.begin();it<bullets.end();it++)
		{
			if ((*it)->doStep())
			{	
				if (it != bullets.begin())
					tmp = it--;
				else 
					tmp = NULL;
				// wyszlo poza zakres
				bullets.erase(it);				
				if (bullets.size()>0)
					it = bullets.begin();
			}
		}*/
		for (int i=0;i<bullets.size();i++)
		{
			if (bullets[i]->doStep())
			{
				bullets.erase(bullets.begin()+i);
				i--;
			}
			else
			{
				// sprawdzanie zderzen
				for (int j=0;j<creepy.size();j++)
				{
					// sprawdzanie odleglosci
					int distX = abs(creepy[j]->getPosition().x - bullets[i]->mapPos.x) * 20 + creepy[j]->getOffset().x + bullets[i]->offset.x;
					int distY = abs(creepy[j]->getPosition().y - bullets[i]->mapPos.y) * 20 + creepy[j]->getOffset().y + bullets[i]->offset.y;

					int realDist = sqrtf(distX*distX + distY*distY);
					if (realDist < 10)
					{
						// zderzenie
						
						bullets.erase(bullets.begin()+i);
						creepy.erase(creepy.begin()+j);
						j--;
						
					}

				}
			}
		}
	}


	void LogicLayer::deinit()
	{
		for (int i=0;i<gridWidth;i++)
			delete [] *grid;
		delete [] grid;
		delete player;
	};


	void LogicLayer::doSteering()
	{
		if (keyStates[GLUT_KEY_UP])
			LogicLayer::getI()->MovePlayer(0,-1);
		

		if (keyStates[GLUT_KEY_DOWN])
			LogicLayer::getI()->MovePlayer(0,1);
		
		if (keyStates[GLUT_KEY_LEFT])
			LogicLayer::getI()->MovePlayer(-5,0);
		

		if (keyStates[GLUT_KEY_RIGHT])
			LogicLayer::getI()->MovePlayer(5,0);		
		if (keyStates[32])
			shot();
	};

	void LogicLayer::shot()
	{
		int dscx,dscy;

		dscx = player->destination.x - player->getPosition().x;
		dscy = player->destination.y - player->getPosition().y;
		dscx*=50;
		dscy*=50;

		Bullet *bullet = new Bullet(
			player->getPosition(),
			player->getOffset(),
			Point2D(dscx,dscy));

		bullets.push_back(bullet);
	};