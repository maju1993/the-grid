// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define FREEGLUT_STATIC
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
//#include <tchar.h>

#include "time.h"
#include <iostream>
#include <sstream>
#include <vector>


// TODO: reference additional headers your program requires here
#include <GLTools.h>	// OpenGL toolkit
#include <GLShaderManager.h>
#include "GL\freeglut.h"
#include <GLFrustum.h>
#include <GLMatrixStack.h>

#include "colors.h"
#include "Grid.h"
//#include "common\extensions3.h"
//#include "common\shaders.h"
//#include "common\vecmatquat.h"
//#include "text.h"
