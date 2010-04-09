#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <strsafe.h>
#include "resource.h"

#include <directui.h>
using namespace DirectUI;

#ifdef _WIN64 
#pragma comment(lib, "..\\lib\\64bit\\dui70.lib")
#else
#pragma comment(lib, "..\\lib\\32bit\\dui70.lib")
#endif

#include <uxtheme.h>
#pragma comment(lib, "uxtheme.lib")
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")


// don't know what this does yet
wchar_t *g_DUIGlobalGUID = (wchar_t*)0x1AF20000;		/* in ExplorerFrame this is: IMM32_NULL_THUNK_DATA */
//GUID IMM32_NULL_THUNK_DATA = {0x905A4D, 0x00003, 0x0000, {0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00}};

HRESULT WINAPI InitProcess(int duiVersion, bool bEnableUIAutomationProvider)
{
	return InitProcessPriv(duiVersion, g_DUIGlobalGUID, 1, bEnableUIAutomationProvider);
}

HRESULT WINAPI UnInitProcess()
{
	return UnInitProcessPriv(g_DUIGlobalGUID);
}

HINSTANCE WINAPI GetShellStyleHInstance(wchar_t **outFileName)
{
	wchar_t LibFileName[260];
	wchar_t colorChars[100];
	HRESULT ret = ::GetCurrentThemeName(LibFileName, 260, colorChars, 100, NULL, 0);

	::PathRemoveFileSpec(LibFileName);
	::PathAppend(LibFileName, L"Shell");
	::PathAppend(LibFileName, colorChars);
	::PathAppend(LibFileName, L"shellstyle.dll");

	HINSTANCE hLib = ::LoadLibraryEx(LibFileName, NULL, LOAD_LIBRARY_AS_DATAFILE);
	if( hLib == NULL ) 
	{
		::ExpandEnvironmentStrings(L"%SystemRoot%\\System32\\ShellStyle.dll", LibFileName , 260);
		hLib = ::LoadLibraryEx(LibFileName, NULL, LOAD_LIBRARY_AS_DATAFILE);
	}
		
	if( hLib != NULL && outFileName != NULL) {
		// copy the file name out
		SHStrDup(LibFileName, outFileName);
	}

	return hLib;
}

void WINAPI DUI_ParserErrorCallback(const unsigned short *szErrorMessage, const unsigned short *className, int iDontKnow, void *lpParam)
{

	MessageBox(NULL, (LPCWSTR)szErrorMessage, (LPCWSTR)className, 0);
}

DirectUI::Value * WINAPI DUI_GetSheetCallback(unsigned short const *className, void *lpParam)
{
	DirectUI::Value *v = NULL;
	//DirectUI::DUIXmlParser::GetSheet(	
	return NULL;
}

HRESULT WINAPI ResultFromLastError()
{
	return HRESULT_FROM_WIN32(::GetLastError());
}

HRESULT WINAPI DUI_LoadUIFileFromResources(HMODULE hModule, LPCWSTR pszSrc, LPWSTR *out)
{
		HRSRC hResInfo = ::FindResource(hModule, (LPCWSTR)pszSrc, L"UIFILE");
		if( hResInfo == NULL ) 
			return ResultFromLastError();

		HGLOBAL hResData = ::LoadResource(hModule, hResInfo);
		if( hResInfo == NULL )
			return ResultFromLastError();

		pszSrc = (LPCWSTR)::LockResource(hResData);
		if( pszSrc == NULL )
			return ResultFromLastError();
		
		DWORD size = ::SizeofResource(hModule, hResInfo);

		*out = (LPWSTR)::LocalAlloc(LPTR, (size+1)*sizeof(WCHAR));
		if( *out == NULL)
			return ResultFromLastError();

		memcpy(*out, pszSrc, size);
		//SHAnsiToUnicode(pszSrc, *out, size+1);
		return S_OK;
}


HRESULT DUI_CreateElementFromResource(HINSTANCE hInst, UINT resstr, unsigned short const *resId, Element *el1,  Element *el2, unsigned long *ul1, Element **pOut) 
{
	HINSTANCE hLibModule = ::LoadLibraryEx(L"Shell32.dll", NULL, LOAD_LIBRARY_AS_DATAFILE); //GetShellStyleHInstance(NULL);

	LPWSTR res = NULL;
	DUI_LoadUIFileFromResources(hInst, MAKEINTRESOURCE(resstr), &res);

	DUIXmlParser *xp = NULL;
	HRESULT hRes = DUIXmlParser::Create(&xp, &DUI_GetSheetCallback, 0, &DUI_ParserErrorCallback, 0);
	
	
	//HINSTANCE hLib = ::LoadLibraryEx(L"Shell32.dll", NULL, LOAD_LIBRARY_AS_DATAFILE);

	hRes = xp->SetXML((unsigned short const *)res, hLibModule, NULL);
	if( FAILED(hRes) )
		goto error;

	hRes = xp->CreateElement(resId, el1, el2, ul1, pOut);
	if( FAILED(hRes) )
		goto error;

error:
	xp->Destroy();
	::LocalFree((HLOCAL)res);
	::FreeLibrary(hLibModule);
	return hRes;
}
const int g_DUIVersion = 8;


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE /*hPrevInstance*/,
                     LPSTR    /*lpCmdLine*/,
                     int       /*nCmdShow*/)
{    

	OleInitialize(NULL);

	HRESULT hRes = InitProcess(g_DUIVersion, true);
	if( FAILED(hRes) ) {
		MessageBox(NULL, L"Couldn't init process", L"error", 0);
		return -1;
	}

	hRes = InitThread(2);
	if( FAILED(hRes) ) {
		MessageBox(NULL, L"Couldn't init thread", L"error", 0);
		return -1;
	}

	RegisterAllControls();


	NativeHWNDHost *host;
	hRes = NativeHWNDHost::Create( (String)L"Hello from native WPF!!", NULL, NULL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, WS_EX_TOOLWINDOW, WS_OVERLAPPEDWINDOW, 0, &host);
	if( FAILED(hRes) ) {
		MessageBox(NULL, L"Couldn't create NativeHWNDHost", L"error", 0);
		return -1;
	}

	HWNDElement *he;
	hRes = HWNDElement::Create(host->GetHWND(), false, 0, NULL, NULL, (Element**)&he);
	if( FAILED(hRes) ) {
		MessageBox(NULL, L"Couldn't create HWNDElement", L"error", 0);
		return -1;
	}

	he->SetVisible(true);
	he->SetAccessible(true);
	he->SetActive(2);
	host->Host(he);

	he->DoubleBuffered(true);

	Layout *fl;
	VerticalFlowLayout::Create(false, VerticalFlowLayout::LAYOUT_CENTER, 0, VerticalFlowLayout::LAYOUT_MIDDLE, &fl);
	he->SetLayout(fl);

	Element *xmlElement;
	hRes = DUI_CreateElementFromResource(hInstance, DUI_1, (unsigned short const *)L"main", NULL, NULL, NULL, &xmlElement);
	if(FAILED(hRes))
		return -1;

	/* load animation example 
	Movie *ani = (Movie*)xmlElement->FindDescendent(StrToID( (unsigned short const *)L"movie_id"));
	auto q = v->GetString();
	hRes = ani->LoadFromResource(hInst, 165);
	ani->Play();
	*/

	xmlElement->SetVisible(true);

	he->Add(xmlElement);

	host->ShowWindow(SW_SHOW);
	StartMessagePump();

	// cleanup

	//e->Destroy(false);

	UnInitThread();
	UnInitProcess();
	::OleUninitialize();
	return 1;
}
