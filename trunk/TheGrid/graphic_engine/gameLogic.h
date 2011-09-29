#pragma once

class GameLogic
{
private:
  static GameLogic *instance;
	GameLogic()
    {
        //private constructor
		
    }

public:

	
	
	//std::vector<
	

	static GameLogic* getI()
	{
		if(instance == NULL)
		{
			instance = new GameLogic();
			return instance;
		}
		else
		{
			return instance;
		}
	}

	
	
};