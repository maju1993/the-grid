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
	GLShaderManager	shaderManager;

	bool showFpsInfo;

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
		showFpsInfo = true;
  }

	//OpenGL funkcje
	void DisplayScene();
	void InitScene();
	void Reshape( int width, int height );
	void DeleteScene();
};