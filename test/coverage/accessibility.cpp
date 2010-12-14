#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <directui.h>
#include <directui/accessibility.h>
using namespace DirectUI;

void accessibility_Accessibility()
{
	
}

void DuiAccessible_coverage()
{
	// static members
	DuiAccessible::Create(NULL, NULL);
	DuiAccessible::AccNavigate(NULL, 0, NULL);
	DuiAccessible::GetAccessibleParent(NULL);
	
	// 
	DuiAccessible k;
	k.Initialize(NULL);

	//
	k.AddRef();
	k.Clone(NULL);
	k.ContextSensitiveHelp(0);
	k.Disconnect();
	
	//
	//k.GetIDsOfNames(const GUID&, unsigned short **, unsigned int, unsigned long, long *);
	k.GetIdentityString(0, NULL,  NULL);
	k.GetTypeInfo(NULL, NULL, NULL);
	k.GetTypeInfoCount( NULL );
	k.GetWindow(NULL);
	
	
	//k.Invoke(long, const GUID&, unsigned long, unsigned short, DISPPARAMS*, VARIANT*, EXCEPINFO*, unsigned int *);
	k.Next(0, NULL, NULL);
	//k.QueryInterface(const GUID&, void **);
	//k.QueryService(const GUID&, const GUID&, void **);
	k.Release();
	k.Reset();
	k.Skip(0);
	//k.accDoDefaultAction(VARIANT);
	k.accHitTest(0, 0, NULL);
	//k.accLocation(NULL, NULL, NULL, NULL, VARIANT);
	//k.accNavigate(long, VARIANT, VARIANT *);
	//k.accSelect(long, VARIANT);

}

