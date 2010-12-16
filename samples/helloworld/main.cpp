#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <directui.h>
using namespace DirectUI;


class HelloWorldWindow : public NativeHWNDHost
{
public:
	HelloWorldWindow() {	
		Initialize(L"Hello from DiirectUI !!", NULL, NULL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, WS_EX_TOOLWINDOW, WS_OVERLAPPEDWINDOW, 0);
	}
};




const int g_DUIVersion = 8;
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{ 
	InitProcess(g_DUIVersion, true);
	RegisterAllControls();
	
	
	HelloWorldWindow wnd;

	wnd.ShowWindow(SW_SHOW);
	StartMessagePump();
	
	UnInitProcess();
	return 0;
}