#pragma once

class GraphicEng
{
private:
  static GraphicEng *instance;
	GraphicEng()
    {
        //private constructor

    }
public:
  static GraphicEng* getI()
	{
		if(instance == NULL)
		{
			instance = new GraphicEng();
			return instance;
		}
		else
		{
			return instance;
		}
	}
  void method();
  ~GraphicEng()
  {
  }

	//OpenGL funkcje
	void DisplayScene();
	void InitScene();
	void Reshape( int width, int height );
	void DeleteScene();
};