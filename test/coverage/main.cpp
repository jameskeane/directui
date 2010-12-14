#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <directui.h>
using namespace DirectUI;

int main(int argc, char **argv)
{

	InitProcessPriv(0, NULL, 0, false);
	UnInitProcessPriv(NULL);
	InitThread(0);
	UnInitThread();

	CreateDUIWrapper(NULL, NULL);
	CreateDUIWrapperEx(NULL, NULL, NULL);
	CreateDUIWrapperFromResource(NULL, NULL, NULL, NULL, NULL);
	GetScreenDPI();

	RegisterAllControls();
	RegisterBaseControls();
	RegisterBrowserControls();
	RegisterCommonControls();
	RegisterExtendedControls();
	RegisterMacroControls();
	RegisterMiscControls();
	RegisterStandardControls();
	RegisterXControls();

	StartMessagePump();
	StopMessagePump();

	StrToID(NULL);
	
	UnicodeToMultiByte(NULL, 0, 0);
	MultiByteToUnicode(NULL, 0, 0);
	
	
	IsAnimationsEnabled();
	IsPalette(NULL);
	IsUIAutomationProviderEnabled();
	

	return 0;
}