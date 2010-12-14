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
	// stuff needed for calls
	VARIANT v;
	const IID id;

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
	k.GetIDsOfNames(id, NULL, 0, 0, NULL);
	k.GetIdentityString(0, NULL,  NULL);
	k.GetTypeInfo(NULL, NULL, NULL);
	k.GetTypeInfoCount( NULL );
	k.GetWindow(NULL);
	
	//
	k.Invoke(0, id, 0, 0, NULL, NULL, NULL, NULL);
	k.Next(0, NULL, NULL);
	k.QueryInterface(id, NULL);
	k.QueryService(id, id, NULL);
	k.Release();
	k.Reset();
	k.Skip(0);
	k.accDoDefaultAction(v);
	k.accHitTest(0, 0, NULL);
	k.accLocation(NULL, NULL, NULL, NULL, v);
	k.accNavigate(0, v, NULL);
	k.accSelect(0, v);

	//
	k.get_accChild(v, NULL);
	k.get_accChildCount(NULL);
	k.get_accDefaultAction(v, NULL);
	k.get_accDescription(v, NULL);
	k.get_accFocus(NULL);
	k.get_accHelp(v, NULL);
	k.get_accHelpTopic(NULL, v, NULL);
	k.get_accKeyboardShortcut(v, NULL);
	k.get_accName(v,  NULL);
	k.get_accParent(NULL);
	k.get_accRole(v, NULL);
	k.get_accSelection(NULL);
	k.get_accState(v, NULL);
	k.get_accValue(v, NULL);
	k.put_accName(v, NULL);
	k.put_accValue(v, NULL);
	
}

void HWNDHostAccessible_coverage() 
{
	// stuff needed for calls
	VARIANT v;
	const IID id;
	
	// static members
	HWNDHostAccessible::Create(NULL, NULL, NULL);

	HWNDHostAccessible k;
	k.Initialize(NULL, NULL);

	//
	k.Clone(NULL);
	k.ContextSensitiveHelp(0);
	k.Disconnect();
	k.GetIdentityString(0, NULL, NULL);
	k.GetWindow(NULL);
	k.Next(0, NULL, NULL);
	k.QueryInterface(id, NULL);
	k.QueryService(id, id, NULL);
	k.Reset();
	k.Skip(0);
	k.accDoDefaultAction(v);
	k.accHitTest(0, 0, NULL);
	k.accLocation(NULL, NULL, NULL, NULL, v);
	k.accNavigate(0, v, NULL);
	k.accSelect(0, v);

	//
	k.get_accChild(v, NULL);
	k.get_accChildCount(NULL);
	k.get_accDefaultAction(v, NULL);
	k.get_accDescription(v, NULL);
	k.get_accFocus(NULL);
	k.get_accHelp(v, NULL);
	k.get_accHelpTopic(NULL, v, NULL);
	k.get_accKeyboardShortcut(v, NULL);
	k.get_accName(v, NULL);
	k.get_accParent(NULL);
	k.get_accRole(v, NULL);
	k.get_accSelection(NULL);
	k.get_accState(v, NULL);
	k.get_accValue(v, NULL);
	k.put_accName(v, NULL);
	k.put_accValue(v, NULL);
}