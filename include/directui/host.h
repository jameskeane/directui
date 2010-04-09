#pragma once

#include <directui/types.h>


namespace DirectUI
{

	class NativeHWNDHost
	{
	public:
		NativeHWNDHost(	const NativeHWNDHost& );
		NativeHWNDHost();
		virtual ~NativeHWNDHost();

		static LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);
		NativeHWNDHost& operator=(const NativeHWNDHost&);
		static UINT AsyncDestroyMsg();

		static HRESULT WINAPI Create(unsigned short const * lpClassName, unsigned short const * lpWindowName, HWND hWndParent, HICON hIcon, int x, int y, int nWidth, int nHeight, int dwExStyle, int dwStyle, HINSTANCE, UINT, NativeHWNDHost **out);
		static HRESULT WINAPI Create(unsigned short const * lpWindowName, HWND hWndParent, HICON hIcon, int x, int y, int nWidth, int nHeight, int dwExStyle, int dwStyle, unsigned int, NativeHWNDHost **out);

		void Destroy();
		void DestroyWindow();
		
		Element* GetElement();
		HWND GetHWND();
		
		void HideWindow();
		void Host(Element *);
		
		HRESULT Initialize(unsigned short const * lpClassName, unsigned short const * lpWindowName, HWND hWndParent, HICON hIcon, int x, int y, int nWidth, int nHeight, int dwExStyle, int dwStyle, HINSTANCE, UINT);
		HRESULT Initialize(const unsigned short*, HWND, HICON, int, int, int, int, int, int, UINT);

		virtual HRESULT OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *);

		int RestoreFocus();
		void SaveFocus();
		void SetDefaultFocusID(const unsigned short*);
		void ShowWindow(int);
	
	private:
		HWND m_hWnd;
		void *unk2;
		void *unk3;
		void *unk4;
		char unk5;
	};

	
	class HWNDHost : public ElementWithHWND
	{
	public:
		HWNDHost(const HWNDHost &);
		HWNDHost();
		virtual ~HWNDHost();
		HWNDHost& operator=(const HWNDHost &);

		long Initialize(unsigned int, unsigned int, Element *, unsigned long *);
		static long Create(unsigned int, unsigned int, Element *, unsigned long *, Element **pOut);
		static long Create(Element *, unsigned long *, Element **pOut);
		void Detach();

		static const PropertyInfo * BackgroundOwnerIDProp();
		virtual long GetAccessibleImpl(IAccessible **);
		unsigned short GetBackgroundOwnerID();
		static IClassInfo * GetClassInfoPtr();
		virtual IClassInfo * GetClassInfoW();
		long GetClientAccessibleImpl(IAccessible **);
		virtual HWND GetHWND();
		HWND GetHWNDParent();
		virtual bool GetKeyFocused();
		bool GetOptimizeMove();
		bool GetTransparent();

		virtual unsigned int MessageCallback(LPGMSG);
		virtual int OnAdjustWindowSize(int, int, unsigned int);

		virtual bool OnCtrlThemeChanged(UINT, WPARAM wParam, LPARAM lParam, LRESULT *);
		virtual bool OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *);
		virtual bool OnNotify(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *);
		virtual void OnDestroy();
		virtual void OnEvent(Event *);
		virtual void OnInput(InputEvent *);
		virtual void OnPropertyChanged(const PropertyInfo *, int, Value *, Value *);
		virtual bool OnSinkThemeChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *);
		virtual bool OnSysChar(unsigned short);

		virtual void OnWindowStyleChanged(WPARAM, STYLESTRUCT const *);
		virtual void Paint(HDC, LPCRECT, LPCRECT, LPRECT, LPRECT);
		long SetBackgroundOwnerID(const String);
		virtual void SetKeyFocus();
		long SetOptimizeMove(bool);
		long SetTransparent(bool);
		virtual void SetWindowDirection(HWND);

		static const PropertyInfo * OptimizeMoveProp();
		static long Register();
		static void SetClassInfoPtr(IClassInfo *);
		static const PropertyInfo * ThemeChangedProp();
		static const PropertyInfo * TransparentProp();

	protected:
		static void AttachCtrlSubclassProc(HWND);
		HWND CreateAccNameLabel(HWND);
		virtual HWND CreateHWND(HWND);
		static __int64 CtrlSubclassProc(HWND, unsigned int, unsigned __int64, __int64);
		virtual bool EraseBkgnd(HDC, LRESULT *);
		Element * GetBackgroundOwner();
		HFONT GetFont();
		bool GetStaticColor(HDC, HBRUSH *);
		int GetThemeChanged();
		bool IsMoveDeferred();
		virtual void OnHosted(Element *);
		virtual void OnUnHosted(Element *);
		void PrintRTLControl(HDC, HDC, const RECT&);
		long SetThemeChanged(int);
		void SyncBackground();
		void SyncDirection();
		void SyncFont();
		void SyncForeground();
		void SyncParent();
		void SyncRect(unsigned int, bool);
		void SyncStyle();
		void SyncText();
		void SyncVisible();
		int VerifyParentage();

	private:
		static unsigned int const (*g_rgMouseMap)[3];
		static IClassInfo * s_pClassInfo;
		void ApplySinkRegion(const LPRECT, bool);
		long GetAccessibleImpl(IAccessible **, bool);
		void GetSinkRect(const LPRECT, LPRECT);
		bool HaveWin32Focus();
		void SyncColorsAndFonts();
		void UnvirtualizePosition();
		void _DeleteCtrlWnd();
		static int _CtrlWndProc(void *, HWND, unsigned int, unsigned __int64, __int64, __int64 *);
		static int _SinkWndProc(void *, HWND, unsigned int, unsigned __int64, __int64, __int64 *);
	};

	class XHost
	{
	public:

		XHost();
		~XHost();
		XHost & operator=(XHost const &);

		static long Create(IXElementCP *, XHost **);
		void Destroy();
		void DestroyWindow();

		Element * GetElement();
		HWND GetHWND();

		void HideWindow();
		void Host(Element *);
		long Initialize(IXElementCP *);
		void ShowWindow(int);

		static LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}