#pragma once

#include <directui/types.h>
#include <directui/parser.h>		// can't forward declare Schema::Pattern

namespace DirectUI
{
	class ElementProvider
	{
	public:
		ElementProvider();
		virtual ~ElementProvider();
		
		virtual unsigned long AddRef();
		virtual long AdviseEventAdded(int, SAFEARRAY *);
		virtual long AdviseEventRemoved(int, SAFEARRAY *);
		static long Create(Element *, InvokeHelper *, ElementProvider **out);
		long DoInvokeArgs(int, ProviderProxy * (__cdecl*)(Element *), char *);
		virtual volatile const Element * GetElement();
		const Element* GetElementKey();

		virtual long GetEmbeddedFragmentRoots(SAFEARRAY **);
		virtual long GetPatternProvider(int, IUnknown **);
		virtual long GetPropertyValue(int, VARIANT*);

		virtual ProviderProxy* (*GetProxyCreator())(Element *);

		virtual long GetRuntimeId(SAFEARRAY **);
		virtual long Navigate(NavigateDirection, IRawElementProviderFragment **);

		virtual long QueryInterface(const GUID&, void **);
		virtual unsigned long Release();
		virtual long SetFocus();

		void TossElement();
		void TossPatternProvider(Schema::Pattern);

		virtual long get_BoundingRectangle(UiaRect *);
		virtual long get_FragmentRoot(IRawElementProviderFragmentRoot **);
		virtual long get_HostRawElementProvider(IRawElementProviderSimple **);
		virtual long get_ProviderOptions(ProviderOptions *);

	protected:
		virtual long Init(Element *, InvokeHelper *);
		long DoInvoke(int, ...);
	};
	
    template <class X, class Y, int>
    class PatternProvider 
    {
        public:
            PatternProvider();
            virtual ~PatternProvider();
            
            static long Create(ElementProvider *, IUnknown **);
            virtual void Init(ElementProvider *);
            
        protected:
            long DoInvoke(int,...);
		private:
			
    };
	
	class XProvider 
	{
	public:
		XProvider();
		XProvider( const XProvider& );
		virtual ~XProvider(); 

		XProvider& operator=( const XProvider& );

		virtual unsigned long AddRef();
		virtual long CanSetFocus(bool *);
		virtual int ClickDefaultButton();

		long Initialize(Element *, IXProviderCP *);
		static long Create(Element *, IXProviderCP *, XProvider **);
		virtual long CreateDUI(IXElementCP *, HWND *);
		long CreateParser(DUIXmlParser **);

		virtual int FindElementWithShortcutAndDoDefaultAction(unsigned short, int);
		virtual long ForceThemeChange(unsigned __int64, __int64);

		virtual long GetDesiredSize(int, int, LPSIZE);
		virtual long GetHostedElementID(String id);

		virtual long IsDescendent(Element *, bool *);
		virtual long Navigate(int, bool *);
		virtual long QueryInterface(const GUID&, void **pUnk);

		virtual unsigned long Release();
		virtual long SetButtonClassAcceptsEnterKey(bool);

		virtual long SetDefaultButtonTracking(bool);
		virtual long SetFocus(Element *);
		virtual long SetParameter(const GUID&, void *);
		virtual long SetRegisteredDefaultButton(Element *);

	protected:
		void SetHandleEnterKey(bool);
		Element * GetRoot();
	};
	
	class XResourceProvider : public XProvider
	{
	public:
		XResourceProvider();
		XResourceProvider( const XResourceProvider& );
		XResourceProvider& operator=( const XResourceProvider& );

		static long Create(XResourceProvider **pOut);
		static long Create(HINSTANCE, unsigned short const *, unsigned short const *, unsigned short const *, XResourceProvider **pOut );
		virtual long CreateDUICP(HWNDElement *, HWND, HWND, Element **, DUIXmlParser **);		
		virtual long CreateParserCP(DUIXmlParser **pOut);

		virtual void DestroyCP();
		long Initialize(HINSTANCE h, const unsigned short* s1, const unsigned short*s2, const unsigned short*s3);

	};
}