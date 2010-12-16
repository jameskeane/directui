#pragma once


#include <objbase.h>
#include <initguid.h>
#include <oleacc.h>
#pragma comment(lib, "Oleacc.lib")


typedef struct tagGMSG 
{
} GMSG, *LPGMSG;

#include <directui/types.h>
#include <directui/element.h>
#include <directui/base.h>
#include <directui/event.h>
#include <directui/layout.h>
#include <directui/host.h>
#include <directui/accessibility.h>
#include <directui/misc.h>


#include <directui/provider.h>
#include <directui/parser.h>


namespace DirectUI {

	HRESULT WINAPI InitProcessPriv(int duiVersion, unsigned short *unk1, char unk2, bool bEnableUIAutomationProvider);
	HRESULT WINAPI UnInitProcessPriv(unsigned short *unk1);
	HRESULT WINAPI InitThread(int iDontKnow);
	void WINAPI UnInitThread();

	// These might be wrong, disassemble and check if it is DirectUI::XProvider * or DirectUI::XProvider **
	int WINAPI CreateDUIWrapper(DirectUI::Element *, DirectUI::XProvider *);
	int WINAPI CreateDUIWrapperEx(DirectUI::Element *, DirectUI::IXProviderCP *, DirectUI::XProvider *);
	int WINAPI CreateDUIWrapperFromResource(HINSTANCE, unsigned short*, unsigned short*, unsigned short*, DirectUI::XResourceProvider *);
	
	int WINAPI GetScreenDPI();

	int WINAPI RegisterAllControls();
	int WINAPI RegisterBaseControls();
	int WINAPI RegisterBrowserControls();
	int WINAPI RegisterCommonControls();
	int WINAPI RegisterExtendedControls();
	int WINAPI RegisterMacroControls();
	int WINAPI RegisterMiscControls();
	int WINAPI RegisterStandardControls();
	int WINAPI RegisterXControls();

	int WINAPI StartMessagePump();
	int WINAPI StopMessagePump();


	ATOM WINAPI StrToID(LPCWSTR resId);
	
	
	int WINAPI UnicodeToMultiByte(LPCWSTR lpWideCharStr, int cchWideChar, int unk);
	int WINAPI MultiByteToUnicode(LPCSTR lpMultiByteStr, int cbMultiByte, int unk);
	
	BOOL WINAPI IsAnimationsEnabled();
	int WINAPI IsPalette(HWND hWnd);
	BOOL WINAPI IsUIAutomationProviderEnabled();
	

	HRESULT WINAPI InitProcess(int duiVersion, bool bEnableUIAutomationProvider)
	{
		return InitProcessPriv(duiVersion, NULL, 1, bEnableUIAutomationProvider);
	}

	HRESULT WINAPI UnInitProcess()
	{
		return UnInitProcessPriv(NULL);
	}

	/*
	int WINAPI DUI_CreateParserWithCallbackFromResource(HLOCAL hMem, LPCSTR pszSrc, HMODULE hLibModule, GetSheetCallback cb, void *cbParam)
	{
		HINSTANCE hLibModule = GetShellStyleHInstance(NULL);

		//DUI_LoadUIFileFromResources();
		//DirectUI::DUIXmlParser
		//DirectUI::DUIXmlParser::Create(

		::FreeLibrary(hLibModule);
	}
	/*
	int WINAPI DUI_CreateParserFromResource(HLOCAL hMem, LPCSTR pszSrc, HMODULE hLibModule, DUIXmlParser **)
	{

	}
	
	int WINAPI DUI_CreateElementFromResource(HLOCAL hMem, LPCSTR pszSrc, unsigned short const *, Element *, Element *, unsigned long *, Element **, DUIXmlParser ** )
	{
		// Create parser


	}
	*/
	/*
	int WINAPI CreateDUIWrapperFromResource( HINSTANCE hInst, unsigned short* s1, unsigned short *s2, unsigned short *s3, DirectUI::XResourceProvider **xp)
	{
	    *xp = NULL;
	    long ret = DirectUI::XResourceProvider::Create(hInst, s1, s2, s3, xp);
		if( ret < 0 ) 
			return ret;

		int r = CreateDUIWrapperEx(NULL, (DirectUI::IXProviderCP *)*xp, (DirectUI::XProvider **)xp);
		if( r >= 0 )
			return r;

		(*xp)->AddRef();
		return r;
	}*/







	/* haven't reversed
	BlurBitmap
	BrushFromEnumI
	ColorFromEnumI
	DUIDrawShadowText
	DisableAnimations
	DrawShadowTextEx
	ElementFromGadget
	EnableAnimations
	FlushThemeHandles
	ForceDebugBreak
	GetElementDataEntry
	GetElementMacro
	GetFontCache
	GetThemeHandle
	HStrDup
	HrSysAllocString
	InitPreprocessor
	NotifyAccessibilityEvent
	PreprocessBuffer
	ProcessAlphaBitmapI
	PurgeThemeHandles
	SetDefAction
	UiaHideOnGetObject
	UiaOnDestroySink
	UiaOnGetObject
	UiaOnToolTip
	*/
}