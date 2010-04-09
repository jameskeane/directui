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

		static HRESULT WINAPI AccNavigate(Element *, long, Element **);
		virtual unsigned long WINAPI AddRef();
		virtual HRESULT WINAPI Clone(IEnumVARIANT **);
		virtual HRESULT WINAPI ContextSensitiveHelp(int);
		virtual HRESULT WINAPI Disconnect();

		static Element * WINAPI GetAccessibleParent(Element *);
		virtual HRESULT WINAPI GetIDsOfNames(const GUID&, unsigned short **, unsigned int, unsigned long, long *);
		virtual HRESULT WINAPI GetIdentityString(unsigned long, unsigned char **, unsigned long *);
		virtual HRESULT WINAPI GetTypeInfo(unsigned int, unsigned long, ITypeInfo **);
		virtual HRESULT WINAPI GetTypeInfoCount(unsigned int *);
		virtual HRESULT WINAPI GetWindow(HWND *);

		virtual HRESULT WINAPI Invoke(long, const GUID&, unsigned long, unsigned short, DISPPARAMS*, VARIANT*, EXCEPINFO*, unsigned int *);
		virtual HRESULT WINAPI Next(unsigned long, VARIANT *, unsigned long *);
		virtual HRESULT WINAPI QueryInterface(const GUID&, void **);
		virtual HRESULT WINAPI QueryService(const GUID&, const GUID&, void **);
		virtual unsigned long WINAPI Release();
		virtual HRESULT WINAPI Reset();
		virtual HRESULT WINAPI Skip(unsigned long);
		virtual HRESULT WINAPI accDoDefaultAction(VARIANT);
		virtual HRESULT WINAPI accHitTest(long, long, VARIANT*);
		virtual HRESULT WINAPI accLocation(long *, long *, long *, long *, VARIANT);
		virtual HRESULT WINAPI accNavigate(long, VARIANT, VARIANT *);
		virtual HRESULT WINAPI accSelect(long, VARIANT);

		virtual HRESULT WINAPI get_accChild(VARIANT, IDispatch **);
		virtual HRESULT WINAPI get_accChildCount(long *);
		virtual HRESULT WINAPI get_accDefaultAction(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accDescription(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accFocus(VARIANT *);
		virtual HRESULT WINAPI get_accHelp(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accHelpTopic(unsigned short **, VARIANT, long *);
		virtual HRESULT WINAPI get_accKeyboardShortcut(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accName(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accParent(IDispatch **);
		virtual HRESULT WINAPI get_accRole(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accSelection(VARIANT *);
		virtual HRESULT WINAPI get_accState(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accValue(VARIANT, unsigned short **);
		virtual HRESULT WINAPI put_accName(VARIANT, unsigned short *);
		virtual HRESULT WINAPI put_accValue(VARIANT, unsigned short *);
	
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
	
		virtual HRESULT WINAPI Clone(IEnumVARIANT **);
		virtual HRESULT WINAPI ContextSensitiveHelp(int);
		virtual HRESULT WINAPI Disconnect();
		virtual HRESULT WINAPI GetIdentityString(unsigned long, unsigned char **, unsigned long *);
		virtual HRESULT WINAPI GetWindow(HWND *);
		virtual HRESULT WINAPI Next(unsigned long, VARIANT *, unsigned long *);
		virtual HRESULT WINAPI QueryInterface(const GUID&, void **);
		virtual HRESULT WINAPI QueryService(const GUID&, const GUID&, void **);
		virtual HRESULT WINAPI Reset();
		virtual HRESULT WINAPI Skip(unsigned long);
		virtual HRESULT WINAPI accDoDefaultAction(VARIANT);
		virtual HRESULT WINAPI accHitTest(long, long, VARIANT *);
		virtual HRESULT WINAPI accLocation(long *, long *, long *, long *, VARIANT);
		virtual HRESULT WINAPI accNavigate(long, VARIANT, VARIANT *);
		virtual HRESULT WINAPI accSelect(long, VARIANT);

		virtual HRESULT WINAPI get_accChild(VARIANT, IDispatch **);
		virtual HRESULT WINAPI get_accChildCount(long *);
		virtual HRESULT WINAPI get_accDefaultAction(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accDescription(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accFocus(VARIANT *);
		virtual HRESULT WINAPI get_accHelp(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accHelpTopic(unsigned short **, VARIANT, long *);
		virtual HRESULT WINAPI get_accKeyboardShortcut(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accName(VARIANT, unsigned short **);
		virtual HRESULT WINAPI get_accParent(struct IDispatch **);
		virtual HRESULT WINAPI get_accRole(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accSelection(VARIANT *);
		virtual HRESULT WINAPI get_accState(VARIANT, VARIANT *);
		virtual HRESULT WINAPI get_accValue(VARIANT, unsigned short **);
		virtual HRESULT WINAPI put_accName(VARIANT, unsigned short *);
		virtual HRESULT WINAPI put_accValue(VARIANT, unsigned short *);
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

		virtual HRESULT WINAPI Disconnect();
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