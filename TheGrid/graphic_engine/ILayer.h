#pragma once
#include "stdafx.h"

class ILayer
{
public:
	virtual void Init() = 0;
	virtual void Render(M3DMatrix44f modelViewMatrix) = 0;
	virtual void Dispose() = 0;
};