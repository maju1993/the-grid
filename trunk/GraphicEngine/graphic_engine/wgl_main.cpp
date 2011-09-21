// Defines the entry point for the application.
//
#include "stdafx.h"

#include "graphic_engine.h"
#include "wgl_main.h"

//extern class GraphicEng;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
char szTitle[MAX_LOADSTRING] = "The Grid";					// The title bar text
char szWindowClass[MAX_LOADSTRING] = "Main frame";			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	//HACCEL hAccelTable;

	// Initialize global strings
	//LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//LoadString(hInstance, IDC_GRAPHIC_ENGINE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	//hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAPHIC_ENGINE));

	//// Main message loop:
	//while (GetMessage(&msg, NULL, 0, 0))
	//{
	//	if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//	{
	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	}
	//}
	
	MSG msg = { 0 };
	// przetwarzanie pêtli komunikatów
	while( WM_QUIT != msg.message )
	{
			if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
			{
					TranslateMessage( &msg );
					DispatchMessage( &msg );
			}
			else
					SendMessage( msg.hwnd, WM_PAINT, 0, 0 );
	}

	// wyrejestrowania okna i zakoñczenie dzia³ania programu
	UnregisterClass(szWindowClass, hInst );
	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_SMALL);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH );
	//wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GRAPHIC_ENGINE);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}




//   FUNCTION: InitInstance(HINSTANCE, int)
//   PURPOSE: Saves instance handle and creates main window
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   //hWnd = CreateWindowEx(NULL, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
   //   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	 hWnd = CreateWindowEx( NULL, szWindowClass, szTitle, 
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 500, 500, NULL, NULL, hInstance, NULL );
    
   if (!hWnd)
   {
      return FALSE;
   }
   //ShowWindow(hWnd, nCmdShow);
   //UpdateWindow(hWnd);
   return TRUE;
}

// uchwyt kontekstu renderingu OpenGL
HGLRC hRC = NULL;
// uchwyt urz¹dzenia
HDC hDC = NULL;
// wartoœæ FPS
int framesPerSecond = 0;
// licznik ramek
int frames = 0;
// licznik czasu
long startTime = 0;

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		// utworzenie deskryptora pikseli
    GLuint PixelFormat;
    PIXELFORMATDESCRIPTOR pfd;
    memset( &pfd, 0, sizeof( PIXELFORMATDESCRIPTOR ) );
    pfd.nSize = sizeof( PIXELFORMATDESCRIPTOR );
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;

    // utworzenie uchwytu urz¹dzenia
    hDC = GetDC( hWnd );
    PixelFormat = ChoosePixelFormat( hDC, &pfd );
    SetPixelFormat( hDC, PixelFormat, &pfd );

    // utworzenie kontekstu renderingu OpenGL
    hRC = wglCreateContext( hDC );
    wglMakeCurrent( hDC, hRC );

    // utworzenie kontekstu renderingu OpenGL 3.2
    wglCreateContextAttribsARB = reinterpret_cast < PFNWGLCREATECONTEXTATTRIBSARBPROC > ( wglGetProcAddress( "wglCreateContextAttribsARB" ) );
    if( wglCreateContextAttribsARB )
    {
        int attribs[] =
        {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
            WGL_CONTEXT_MINOR_VERSION_ARB, 2,
            WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
            0
        };
        HGLRC hRC3 = wglCreateContextAttribsARB( hDC, hRC, attribs);
        wglMakeCurrent( hDC, hRC3 );
        wglDeleteContext( hRC );
        hRC = hRC3;
    }
    else
    {
        MessageBox( NULL, "Nie mo¿na utworzyæ kontekstu OpenGL 3.2", "B³¹d", MB_OK | MB_ICONEXCLAMATION );
        PostQuitMessage( 0 );
    }

    // konfiguracja niezbêdnych rozszerzeñ
    OpenGL30();
    OpenGL31();

    // inicjacja maszyny stanów i elementów sceny
		GraphicEng::getI()->InitScene();
    
    InvalidateRect( hWnd, NULL, TRUE );
    break;
  // zmiana rozmiaru okna
  case WM_SIZE:
    GraphicEng::getI()->Reshape( LOWORD( lParam ), HIWORD( lParam ) );
    InvalidateRect( hWnd, NULL, TRUE );
    break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		/*switch (wmId)
		{
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}*/
		break;
	case WM_PAINT:
		
    // licznik czasu
    if( !frames++ )
      startTime = clock();

    // rysowanie sceny
    GraphicEng::getI()->DisplayScene();

		// zliczanie iloœci ramek rysowanych na sekundê (FPS)
    if( clock() - startTime >= 0.5 * CLOCKS_PER_SEC )
    {
      framesPerSecond = static_cast <int> ( frames * CLOCKS_PER_SEC/static_cast<float>( clock() - startTime ) );
      frames = 0;
    }

    // zamiana buforów
    SwapBuffers( hDC );
    ValidateRect( hWnd, NULL );

		break;

	case WM_DESTROY:
    GraphicEng::getI()->DeleteScene();

    wglMakeCurrent( hDC, NULL );
    wglDeleteContext( hRC );
    ReleaseDC( hWnd, hDC );
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
