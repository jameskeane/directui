#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <directui.h>
using namespace DirectUI;


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE /*hPrevInstance*/,
                     LPSTR    /*lpCmdLine*/,
                     int       /*nCmdShow*/)
{    
	//OleInitialize(NULL);
	
	NativeHWNDHost host;
	host.Initialize(L"Hello from DiirectUI !!", NULL, NULL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, WS_EX_TOOLWINDOW, WS_OVERLAPPEDWINDOW, 0);
	
	host.ShowWindow(SW_SHOW);
	StartMessagePump();
	
	return 0;
}