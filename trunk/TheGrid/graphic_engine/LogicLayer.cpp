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
		//std::vector<mapItem*>::iterator it;  
		//for ( it=creepy.begin() ; it < creepy.end(); it++ )
		for (int i=0;i<creepy.size();i++)
		{
			//(*it)->moveTo(player->getPosition().x,player->getPosition().y);
			creepy[i]->moveTo(player->getPosition().x,player->getPosition().y);
		}

		// check zderzenia
		for (int i=0;i<creepy.size();i++)
		{
					// sprawdzanie odleglosci
					int distX = abs(creepy[i]->getPosition().x - player->getPosition().x) * 20 + creepy[i]->getOffset().x + player->getOffset().x;
					int distY = abs(creepy[i]->getPosition().y - player->getPosition().y) * 20 + creepy[i]->getOffset().y + player->getOffset().y;

					int realDist = sqrtf(distX*distX + distY*distY);
					if (realDist < 10)
					{
						// zderzenie												
						creepy.erase(creepy.begin()+i);
						player->hp--;						
						i--;						
					}

			
		}
		if (player->hp<=0)
		{
			player->hp = 0;
			gameover = true;
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
		if (gameover)
		{
			doSteering();
			return;
		}
		creepRespawnCounter++;
		if (creepRespawnCounter > 30 - (creepHardcore <20 ? creepHardcore:20))
		{
			int proposed_x;
			int proposed_y;
			do
			{
			proposed_x = rand() % gridWidth;
			proposed_y = rand() % gridHeight;
			} while ((proposed_x>player->getPosition().x-4)&&(proposed_x<player->getPosition().x+4) && (proposed_y>player->getPosition().y-4) && (proposed_y<player->getPosition().y+4));

			addCreep(Point2D(proposed_x,proposed_y),rand()%3+1);
			creepRespawnCounter = 0;
			creepHardcore++;
		}

		// wpierw creepy potem player - spowoduje to pewna 'glupote creepow', na dodatek creepy wpierw ruch potem przeliczenie
		//std::vector<mapItem*>::iterator it;  
		for (int i=0;i<creepy.size();i++)// it=creepy.begin() ; it < creepy.end(); it++ )
		{
			creepy[i]->doStep();
			//if ((*it)->doStep()) 
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
		for (int i=bullets.size()-1;i>0;i--)
		{
			if (bullets[i]->doStep())
			{
				bullets.erase(bullets.begin()+i);
				//i--;
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
						points++;
						break;
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
		if (gameover)
		{
			if (keyStates[13] || keyStates[27])
				glutExit();
			return;
		}

		if (specialKeystates[GLUT_KEY_UP])
			LogicLayer::getI()->MovePlayer(0,-1);
		

		if (specialKeystates[GLUT_KEY_DOWN])
			LogicLayer::getI()->MovePlayer(0,1);
		
		if (specialKeystates[GLUT_KEY_LEFT])
			LogicLayer::getI()->MovePlayer(-5,0);
		

		if (specialKeystates[GLUT_KEY_RIGHT])
			LogicLayer::getI()->MovePlayer(5,0);		

		if (keyStates[32])
			shot();

		if (keyStates['f'] || keyStates['F'])
			showFPSinfo = !showFPSinfo;

		if (keyStates[27])
		{
			gameover = true;
			//glutExit();
		}
	};

	void LogicLayer::shot()
	{
	
		int dscx,dscy;
		//dscx = -100* sinf(player->angle * 3.14/180.0);// + player->getPosition().x;
		//dscy = -100 * cosf(player->angle* 3.14/180.0);// + player->getPosition().y;

		dscx = player->destination.x - player->getPosition().x;
		dscy = player->destination.y - player->getPosition().y;
		dscx*=50;
		dscy*=50;
		dscx += player->getPosition().x;
		dscy += player->getPosition().y;

		Bullet *bullet = new Bullet(
			player->getPosition(),
			player->getOffset(),
			Point2D(dscx,dscy));

		bullets.push_back(bullet);
	};