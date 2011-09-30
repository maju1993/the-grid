#pragma once
#include "stdafx.h"

//Interfejs odpowiedzialny za obs³uge warstw
class ILayer
{
public:
	//inicjalizacja
	virtual void Init() = 0;
	//renderowanie
	virtual void Render(M3DMatrix44f modelViewMatrix) = 0;
	//zwalnianie
	virtual void Dispose() = 0;
};