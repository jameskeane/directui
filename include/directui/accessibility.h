#pragma once

#include <directui/types.h>

namespace DirectUI
{
    class DuiAccessible : public IAccIdentity, public IAccessible, public IEnumVARIANT, public IOleWindow, public IServiceProvider
    {
	public:
		DuiAccessible();
		virtual ~DuiAccessible();
		
		void Initialize(Element *);
		static HRESULT WINAPI Create(Element *, DuiAccessible **);
		static Element * WINAPI GetAccessibleParent(Element *);
		static HRESULT WINAPI AccNavigate(Element *, long, Element **);
	
		virtual HRESULT Disconnect(void);

		// IUnknown
		virtual HRESULT WINAPI QueryInterface(REFIID riid, void **ppvObject);
		virtual ULONG WINAPI AddRef();
		virtual ULONG WINAPI Release();
		
		// IDispatch
		virtual HRESULT WINAPI GetTypeInfoCount(UINT *pctinfo);
		virtual HRESULT WINAPI GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo  );
		virtual HRESULT WINAPI GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);	
		virtual HRESULT WINAPI Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
		
		// IAccIdentity
		virtual HRESULT WINAPI GetIdentityString(DWORD dwIDChild, BYTE **ppIDString, DWORD *pdwIDStringLen);
		
		// IAccessible
		virtual HRESULT WINAPI get_accParent(IDispatch **);
		virtual HRESULT WINAPI get_accChildCount(long *);
		virtual HRESULT WINAPI get_accChild(VARIANT, IDispatch **);
		virtual HRESULT WINAPI get_accName(VARIANT,  BSTR *);
		virtual HRESULT WINAPI get_accValue(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accDescription(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accRole(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accState(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accHelp(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accHelpTopic(BSTR *, VARIANT, long *);
		virtual HRESULT WINAPI get_accKeyboardShortcut(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accFocus(VARIANT *);
		virtual HRESULT WINAPI get_accSelection(VARIANT *);
		virtual HRESULT WINAPI get_accDefaultAction(VARIANT, BSTR *);
		
		virtual HRESULT WINAPI accSelect(long flagsSelect, VARIANT varID);
		virtual HRESULT WINAPI accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varID);
		virtual HRESULT WINAPI accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEnd);
		virtual HRESULT WINAPI accHitTest(long xLeft, long yTop, VARIANT *pvarID);
		virtual HRESULT WINAPI accDoDefaultAction(VARIANT varID);
		
		virtual HRESULT WINAPI put_accName(VARIANT varID, BSTR pszValue);
		virtual HRESULT WINAPI put_accValue(VARIANT varID, BSTR pszValue);		
		
		// IEnumVARIANT
		virtual HRESULT WINAPI Clone(IEnumVARIANT **ppEnum);
		virtual HRESULT WINAPI Next(unsigned long celt, VARIANT *rgVar, unsigned long *pCeltFetched);
		virtual HRESULT WINAPI Reset();
		virtual HRESULT WINAPI Skip(unsigned long celt);
		
		// IOleWindow
		virtual HRESULT WINAPI GetWindow(HWND *phwnd);
		virtual HRESULT WINAPI ContextSensitiveHelp(BOOL fEnterMode);

		// IServiceProvider
		virtual HRESULT WINAPI QueryService(REFGUID guidService, REFIID riid, void **ppv);
		
	protected: 
		long GetAccName(VARIANT, int, unsigned short **);
		long GetAccNameFromContent(unsigned short **);
		long GetDispatchFromElement(Element *, IDispatch **);
    };


	class HWNDHostAccessible : public DuiAccessible
	{
	public:
		HWNDHostAccessible();
		virtual ~HWNDHostAccessible();

		long Initialize(Element *, IAccessible *);
		static HRESULT WINAPI Create(Element *, IAccessible *, DuiAccessible **);
	
		//IAccIdentity
		virtual HRESULT WINAPI GetIdentityString(unsigned long, unsigned char **, unsigned long *);
	
		virtual HRESULT WINAPI Clone(IEnumVARIANT **);
		virtual HRESULT WINAPI ContextSensitiveHelp(int);
		virtual HRESULT Disconnect();
		virtual HRESULT WINAPI GetWindow(HWND *);
		virtual HRESULT WINAPI Next(unsigned long, VARIANT *, unsigned long *);
		virtual HRESULT WINAPI QueryInterface(const IID &, void **);
		virtual HRESULT WINAPI QueryService(const IID &, const IID &, void **);
		virtual HRESULT WINAPI Reset();
		virtual HRESULT WINAPI Skip(unsigned long);
		virtual HRESULT WINAPI accDoDefaultAction(VARIANT);
		virtual HRESULT WINAPI accHitTest(long, long, VARIANT *);
		virtual HRESULT WINAPI accLocation(long *, long *, long *, long *, VARIANT);
		virtual HRESULT WINAPI accNavigate(long, VARIANT, VARIANT *);
		virtual HRESULT WINAPI accSelect(long, VARIANT);
		
		// IAccessible
		virtual HRESULT WINAPI get_accChild(VARIANT, IDispatch **);
		virtual HRESULT WINAPI get_accChildCount(long *);
		virtual HRESULT WINAPI get_accDefaultAction(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accDescription(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accFocus(VARIANT *);
		virtual HRESULT WINAPI get_accHelp(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accHelpTopic(BSTR *, VARIANT, long *);
		virtual HRESULT WINAPI get_accKeyboardShortcut(VARIANT, BSTR *);
		virtual HRESULT WINAPI get_accName(VARIANT,  BSTR *);
		virtual HRESULT WINAPI get_accParent(IDispatch **);
		virtual HRESULT WINAPI get_accRole(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accSelection(VARIANT *);
		virtual HRESULT WINAPI get_accState(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accValue(VARIANT, BSTR *);
		virtual HRESULT WINAPI put_accName(VARIANT, BSTR);
		virtual HRESULT WINAPI put_accValue(VARIANT, BSTR);
	};

	class HWNDHostClientAccessible
	{
	public:
		HWNDHostClientAccessible();
		virtual ~HWNDHostClientAccessible();

		static HRESULT WINAPI Create(Element *, IAccessible *, DuiAccessible **);
		virtual HRESULT WINAPI accNavigate(long, VARIANT, LPVARIANT);
		virtual HRESULT WINAPI get_accParent(IDispatch **);
		virtual HRESULT WINAPI get_accRole(VARIANT, VARIANT *);
	};
	 
	class HWNDElementAccessible : DuiAccessible
	{
	public:
		HWNDElementAccessible();
		virtual ~HWNDElementAccessible();

		long Initialize(HWNDElement *);
		static HRESULT WINAPI Create(HWNDElement *, DuiAccessible **);

		virtual HRESULT Disconnect();
		virtual HRESULT WINAPI get_accParent(IDispatch **);
	};

    class AccessibleButton : public Button
    {
    public:
        AccessibleButton(const AccessibleButton&);
        AccessibleButton();
        
        virtual ~AccessibleButton();
        AccessibleButton& operator=(const AccessibleButton& );
        
        static HRESULT WINAPI Create(Element *, unsigned long *, Element **);
        static IClassInfo * WINAPI GetClassInfoPtr();
        virtual IClassInfo * GetClassInfoW();

        long Initialize(Element *, unsigned long *);

        void Recalc();
        static HRESULT WINAPI Register();
        static void WINAPI SetClassInfoPtr(IClassInfo *);
        virtual void OnPropertyChanged(const PropertyInfo *, int, Value *, Value *);
        
        // member types
        struct ACCESSIBLEROLE
        {
            // see http://msdn.microsoft.com/en-us/library/system.windows.forms.accessiblerole.aspx
            ACCESSIBLEROLE& operator=(const ACCESSIBLEROLE& );
  	  	};
    
    private:
        static ACCESSIBLEROLE const * const c_rgar;
        static IClassInfo* s_pClassInfo;
        static const ACCESSIBLEROLE* FindAccessibleRole(int);
    };

}