#pragma once

#include <directui/types.h>


// struct HGADGET__ *
// struct EventMsg *

namespace DirectUI
{
	struct UpdateCache
	{
	 // ??
	};


	class Element
	{
	public:
		Element();
		Element(const Element&);
		virtual ~Element();
		
		Element& operator=(const Element &);
		
		long Initialize(unsigned int, Element * ,unsigned long *);
		static long Create(unsigned int, Element *parent, unsigned long *, Element **out);


		
		static long UnRegister(IClassInfo **);

		long Add(Element *);
		long Add(Element *, int (__cdecl*)(const void *, const void *));
		virtual long Add(Element **, unsigned int);
		
		long AddListener(IElementListener *);

		unsigned long AddRef();
		static UID AnimationChange();

		void BroadcastEvent(Event *);
		void Detach(DeferCycle *);
		
		virtual long DefaultAction();
		long Destroy(bool);
		long DestroyAll(bool);
		void DoubleBuffered(bool);
		void EnableUiaEvents(bool);
		void EndDefer(unsigned long);
		bool EnsureVisible(unsigned int);
		bool EnsureVisible(void);
		virtual bool EnsureVisible(int,int,int,int);
		Element* FindDescendent(ATOM id);
		void FireEvent(Event*, bool, bool);

		bool GetAbsorbsShortcut();
		const unsigned short* GetAccDefAction(Value **);
		const unsigned short* GetAccDesc(Value **);
		const unsigned short* GetAccHelp(Value **);
		const unsigned short* GetAccItemStatus(Value **);
		const unsigned short* GetAccItemType(Value **);
		const unsigned short* GetAccName(Value **);
		const unsigned short* GetAccNameAsDisplayed(Value **);
		const unsigned short* GetAccValue(Value **);

		int GetAccRole();
		int GetAccState();
		bool GetAccessible();
		virtual long GetAccessibleImpl(IAccessible **);
		int GetActive();
		Element* GetRoot();

		// Properties? wtf is this

		static PropertyInfo const * WINAPI AbsorbsShortcutProp();
		static PropertyInfo const * WINAPI AccDefActionProp();
		static PropertyInfo const * WINAPI AccDescProp();
		static PropertyInfo const * WINAPI AccHelpProp();
		static PropertyInfo const * WINAPI AccItemStatusProp();
		static PropertyInfo const * WINAPI AccItemTypeProp();
		static PropertyInfo const * WINAPI AccNameProp();
		static PropertyInfo const * WINAPI AccRoleProp();
		static PropertyInfo const * WINAPI AccStateProp();
		static PropertyInfo const * WINAPI AccValueProp();
		static PropertyInfo const * WINAPI AccessibleProp();
		static PropertyInfo const * WINAPI ActiveProp();
		static PropertyInfo const * WINAPI AlphaProp();
		static PropertyInfo const * WINAPI AnimationProp();
		static PropertyInfo const * WINAPI BackgroundProp();
		static PropertyInfo const * WINAPI BorderColorProp();
		static PropertyInfo const * WINAPI BorderStyleProp();
		static PropertyInfo const * WINAPI BorderThicknessProp();
		static PropertyInfo const * WINAPI ChildrenProp();
		static PropertyInfo const * WINAPI ClassProp();
		static PropertyInfo const * WINAPI CompositedTextProp();
		static PropertyInfo const * WINAPI ContentAlignProp();
		
		static PropertyInfo const * WINAPI ContentProp();
		static PropertyInfo const * WINAPI CursorProp();
		static PropertyInfo const * WINAPI CustomProp();
		static PropertyInfo const * WINAPI DPIProp();
		static PropertyInfo const * WINAPI DirectionProp();
		static PropertyInfo const * WINAPI DesiredSizeProp();
		static PropertyInfo const * WINAPI ExtentProp();
		static PropertyInfo const * WINAPI ForegroundProp();
		static PropertyInfo const * WINAPI FontFaceProp();
		static PropertyInfo const * WINAPI FontProp();
		static PropertyInfo const * WINAPI FontQualityProp();
		static PropertyInfo const * WINAPI FontSizeProp();
		static PropertyInfo const * WINAPI FontStyleProp();
		static PropertyInfo const * WINAPI FontWeightProp();
		static PropertyInfo const * WINAPI KeyFocusedProp();
		static PropertyInfo const * WINAPI KeyWithinProp();
		static PropertyInfo const * WINAPI LastDSConstProp();
		static PropertyInfo const * WINAPI LayoutPosProp();
		static PropertyInfo const * WINAPI LayoutProp();
		static PropertyInfo const * WINAPI LocationProp();
		static PropertyInfo const * WINAPI HeightProp();
		static PropertyInfo const * WINAPI HighDPIProp();
		static PropertyInfo const * WINAPI IDProp();
		static PropertyInfo const * WINAPI MinSizeProp();
		static PropertyInfo const * WINAPI MouseFocusedProp();
		static PropertyInfo const * WINAPI MouseWithinProp();
		static PropertyInfo const * WINAPI OverhangProp();
		static PropertyInfo const * WINAPI PaddingProp();
		static PropertyInfo const * WINAPI ParentProp();
		static PropertyInfo const * WINAPI PosInLayoutProp();
		static PropertyInfo const * WINAPI SelectedProp();
		static PropertyInfo const * WINAPI ShadowIntensityProp();
		static PropertyInfo const * WINAPI SheetProp();
		static PropertyInfo const * WINAPI ShortcutProp();
		static PropertyInfo const * WINAPI SizeInLayoutProp();
		static PropertyInfo const * WINAPI TextGlowSizeProp();
		static PropertyInfo const * WINAPI TooltipMaxWidthProp();
		static PropertyInfo const * WINAPI TooltipProp();
		static PropertyInfo const * WINAPI VisibleProp();
		static PropertyInfo const * WINAPI WidthProp();
		static PropertyInfo const * WINAPI WindowActiveProp();
		static PropertyInfo const * WINAPI XProp();
		static PropertyInfo const * WINAPI YProp();

		long GetRootRelativeBounds(LPRECT);
		bool GetSelected();
		int GetShadowIntensity();
		StyleSheet* GetSheet();
		int GetShortcut();
		unsigned short GetShortcutChar();
		int GetTextGlowSize();
		bool GetTooltip();
		int GetTooltipMaxWidth();
		Element* GetTopLevel();
		float GetTreeAlphaLevel();
		Value* GetValue(PropertyInfo const * (WINAPI*)(void), int, UpdateCache *);
		Value * GetValue(PropertyInfo const *, int, UpdateCache *);
		bool GetVisible();
		int GetWidth();
		bool GetWindowActive();
		int GetX();
		int GetY();
		virtual void HandleUiaDestroyListener();

		virtual void HandleUiaEventListener(Event *);
		virtual void HandleUiaPropertyChangingListener(PropertyInfo const *);
		virtual void HandleUiaPropertyListener(PropertyInfo const *, int, Value *, Value *);
		bool HasAnimation();
		bool HasBorder();
		bool HasChildren();
		bool HasContent();
		bool HasLayout();
		bool HasMargin();
		bool HasPadding();
		static void InitDefaultFontSize();
		static UID KeyboardNavigate();
		
		long Insert(Element *, unsigned int);
		virtual long Insert(Element **, unsigned int, unsigned int);
		void InvokeAnimation(int, unsigned int);
		void InvokeAnimation(unsigned int, unsigned int, float, float, bool);
		bool IsCompositedText();
		virtual bool IsContentProtected();
		bool IsDefaultCAlign();
		bool IsDefaultCursor();
		bool IsDescendent(Element *);
		bool IsDestroyed();
		bool IsHosted();
		bool IsRTL();
		virtual bool IsRTLReading();
		int IsRoot();
		bool IsSelfLayout();
		bool IsValidAccessor(PropertyInfo const *, int, bool);
		static bool IsValidValue(PropertyInfo const *, Value *);
		bool IsWordWrap();
		void MapElementPoint(Element *, POINT const *, LPPOINT);
		static PropertyInfo const * WINAPI MarginProp();

		void MarkNeedsDSUpdate();
		virtual unsigned int MessageCallback(GMSG *);
		bool NeedsDSUpdate();

		virtual void OnDestroy();
		virtual void OnEvent(Event *);
		virtual void OnGroupChanged(int, bool);
		virtual void OnInput( InputEvent *);
		virtual void OnKeyFocusMoved(Element *, Element *);
		virtual void OnMouseFocusMoved(Element *, Element *);
		virtual void OnPropertyChanged(PropertyInfo *, int, Value *, Value *);
		virtual void OnPropertyChanged(PropertyInfo const *, int, Value *, Value *);
		virtual bool OnPropertyChanging(PropertyInfo *, int, Value *, Value *);
		virtual bool OnPropertyChanging(PropertyInfo const *, int, Value *, Value *);

		virtual void Paint(HDC, RECT const *, RECT const *, RECT *, RECT *);
		void PaintBackground(HDC, Value *, RECT const &, RECT const &, RECT const &, RECT const &);
		void PaintBorder(HDC, Value *, RECT *, RECT const &);
		void PaintContent(HDC, RECT const *);
		void PaintFocusRect(HDC, RECT const *, RECT const *);
		void PaintStringContent(HDC, RECT const *, Value *, int);
		
		void PostEvent(Event *);
		virtual long WINAPI QueryInterface(GUID const &, void **);
		long QueueDefaultAction();
		static long Register();
		unsigned long Release();
		long Remove(Element *);
		virtual long Remove(Element **, unsigned int);
		long RemoveAll();
		void RemoveListener(IElementListener *);
		long RemoveLocalValue(PropertyInfo const * (WINAPI*)(void));
		long RemoveLocalValue(PropertyInfo const *);

		long SetAbsorbsShortcut(bool);
		long SetAccDefAction(unsigned short const *);
		long SetAccDesc(unsigned short const *);
		long SetAccHelp(unsigned short const *);
		long SetAccItemStatus(unsigned short const *);
		long SetAccItemType(unsigned short const *);
		long SetAccName(unsigned short const *);
		long SetAccRole(int);
		long SetAccState(int);
		long SetAccValue(unsigned short const *);
		long SetAccessible(bool);
		long SetActive(int);
		long SetAlpha(int);
		long SetAnimation(int);
		long SetBackgroundColor(Fill const &);
		long SetBackgroundColor(unsigned long);
		long SetBackgroundColor(unsigned long,unsigned long,unsigned char);
		long SetBackgroundColor(unsigned long,unsigned long,unsigned long,unsigned char);
		long SetBackgroundColor(unsigned short const *,int,int);
		long SetBackgroundStdColor(int);
		long SetBorderColor(unsigned long);
		long SetBorderGradientColor(unsigned long,unsigned long,unsigned char);
		long SetBorderStdColor(int);
		long SetBorderStyle(int);
		long SetBorderThickness(int,int,int,int);
		long SetClass(unsigned short const *);
		static void SetClassInfoPtr(IClassInfo *);
		long SetCompositedText(bool);
		long SetContentAlign(int);
		long SetContentGraphic(unsigned short const *, unsigned char, unsigned int);
		long SetContentGraphic(unsigned short const *, unsigned short, unsigned short);
		long SetContentString(unsigned short const *);
		long SetCursor(unsigned short const *);
		long SetCursorHandle(HICON);
		long SetDirection(int);
		long SetEnabled(bool);
		long SetEncodedContentString(unsigned short const *);
		long SetFont(unsigned short const *);
		long SetFontFace(unsigned short const *);
		long SetFontQuality(int);
		long SetFontSize(int);
		long SetFontStyle(int);
		long SetFontWeight(int);
		long SetForegroundColor(unsigned long);
		long SetForegroundColor(unsigned long, unsigned long, unsigned char);
		long SetForegroundColor(unsigned long, unsigned long, unsigned long, unsigned char);
		long SetForegroundStdColor(int);
		long SetHeight(int);
		long SetID(unsigned short const *);
		virtual void SetKeyFocus(void);
		long SetLayout(Layout *);
		long SetLayoutPos(int);
		long SetMargin(int, int, int, int);
		long SetMinSize(int, int); 
		long SetOverhang(bool);
		long SetPadding(int, int, int, int);
		long SetSelected(bool);
		long SetShadowIntensity(int);
		long SetSheet(StyleSheet *);
		long SetShortcut(int);
		long SetStdCursor(int);
		long SetTextGlowSize(int);
		long SetTooltip(bool);
		long SetTooltipMaxWidth(int);
		long SetValue(PropertyInfo const * (WINAPI*)(void), int, Value *);
		long SetValue(PropertyInfo const *, int, Value *);
		long SetVisible(bool);
		long SetWidth(int);
		long SetWindowActive(bool);
		long SetX(int);
		long SetY(int);

		long SortChildren(int (WINAPI*)(void const *, void const *));
		void StartDefer(unsigned long *);
		void StopAnimation(unsigned int);
		DeferCycle * TestDeferObject();
		bool UiaEvents();
		void UpdateLayout();
		static void _AddDependency(Element *, PropertyInfo const *, int, DepRecs *, DeferCycle *, long *);
		void _ClearNeedsLayout();
		static long _DisplayNodeCallback(struct HGADGET__ *, void *, struct EventMsg *);
		void _EndOptimizedLayoutQ();
		int _GetChangesUpdatePass();
		unsigned int _GetNeedsLayout();
		static int _MarkElementForDS(Element *);
		static int _MarkElementForLayout(Element *, unsigned int);
		static bool _SetGroupChanges(Element *, int, DeferCycle *);
		int _SetNeedsLayout(unsigned int);
		void _StartOptimizedLayoutQ(void);
		static void _TransferGroupFlags(Element *, int);
		struct tagSIZE _UpdateDesiredSize(int, int, Surface *);
		void _UpdateLayoutPosition(int, int);
		void _UpdateLayoutSize(int, int);

	protected:
		virtual void ActivateTooltip(Element *, unsigned long);
		virtual void OnHosted(Element *);
		virtual void OnUnHosted(Element *);
		void MarkHosted();
		void MarkSelfLayout();
		virtual void RemoveTooltip(Element *);
		virtual void UpdateTooltip(Element *);
		static void _FlushLayout(Element *, DeferCycle *);
		static void _InvalidateCachedDSConstraints(Element *);
		void _OnFontPropChanged(Value *);
		long _RemoveLocalValue(PropertyInfo const * (WINAPI*)(void), bool);
		long _RemoveLocalValue(PropertyInfo const *,bool);
		virtual void _SelfLayoutDoLayout(int, int);
		virtual SIZE _SelfLayoutUpdateDesiredSize(int, int, Surface *);
		long _SetValue(PropertyInfo const * (WINAPI*)(void), int, Value *, bool);
		long _SetValue(PropertyInfo const *, int, Value *, bool);

	private:
		Element* FindDescendentWorker(unsigned short);
		void _SyncBackground();
		void _SyncRedrawStyle();
		void _SyncVisible();
		bool IsPointValid(double, double);
		unsigned short * RemoveShortcutFromName(const String);
		bool TryLinePattern(LPPOINT, const RECT&);
		bool TryPattern(double, double, LPPOINT, const RECT&);
		bool TrySparsePattern(LPPOINT, const RECT&);
		void _BroadcastEventWorker(Event *);
		int _CachedValueIsEqual(const PropertyInfo *, Element *);
		void _GetBuriedSheetDependencies(const PropertyInfo *, Element *, DepRecs *, DeferCycle *, long *);
		void _UpdatePropertyInCache(const PropertyInfo *);
		static void _VoidPCNotifyTree(int, DeferCycle *);
		static IClassInfo *s_pClassInfo;

		void _FlushDS(DeferCycle *);
		Value * _GetComputedValue(PropertyInfo const *, UpdateCache *);
		long _GetDependencies(PropertyInfo const *, int, DepRecs *, int, Value *, DeferCycle *);
		Value * _GetLocalValue(PropertyInfo const *);
		Value * _GetLocalValueFromVM(PropertyInfo const *);
		Value * _GetSpecifiedValue(PropertyInfo const *, UpdateCache *);
		Value * _GetSpecifiedValueIgnoreCache(PropertyInfo const *);
		void _InheritProperties();
		long _PostSourceChange();
		long _PreSourceChange(PropertyInfo const * (WINAPI*)(void), int, Value *, Value *);
		long _PreSourceChange(PropertyInfo const *, int, Value *, Value *);
	};

	class Button : public Element 
	{
	public:
		Button(const Button&);
		Button();
		virtual ~Button();
		Button & operator=(const Button&);

		long Initialize(unsigned int, Element*, unsigned long *);
		static long Create(unsigned int, Element *, unsigned long *, Element **);
		static long Create(Element *, unsigned long *, Element **);

		static UID Click();
		static UID Context();

		virtual long DefaultAction();
		bool GetCaptured();
		static IClassInfo* GetClassInfoPtr();
		virtual IClassInfo* GetClassInfoW();
		bool GetPressed();

		virtual void OnInput(InputEvent *);
		virtual bool OnLostDialogFocus(DialogElement *);
		virtual void OnPropertyChanged(const PropertyInfo *, int, Value *, Value *);
		virtual bool OnReceivedDialogFocus(DialogElement *);

		static long Register();
		long SetCaptured(bool);
		static void SetClassInfoPtr(IClassInfo *);
		long SetPressed(bool);

		static const PropertyInfo * CapturedProp();
		static const PropertyInfo * PressedProp();

	private: 
		static IClassInfo* s_pClassInfo;
	};

	class ElementWithHWND : public Element
	{
	public:
		ElementWithHWND(const ElementWithHWND &);
		ElementWithHWND();
		virtual ~ElementWithHWND();
		ElementWithHWND& operator=(const ElementWithHWND &);

		static long Create(Element *, unsigned long *, Element **);
		static IClassInfo * GetClassInfoPtr();
		virtual IClassInfo * GetClassInfoW();
		static long Register();
		static void SetClassInfoPtr(IClassInfo *);

	private: 
		static IClassInfo *s_pClassInfo;
	};
	
	class HWNDElement : public ElementWithHWND
	{
	public:
		HWNDElement(const HWNDElement &);
		HWNDElement();
		virtual ~HWNDElement();
		HWNDElement& operator=(const HWNDElement &);
		
		virtual void ActivateTooltip(Element * , unsigned long);
		virtual bool CanSetFocus();
		static class UID CompositionChange();
		static HRESULT WINAPI Create(HWND, bool, unsigned int, Element * , unsigned long *, Element **pOut);

		virtual long CreateStyleParser(DUIXmlParser **);
		void DelayActivateTooltip();
		Element * ElementFromPoint(LPPOINT);
		static bool FindShortcut(unsigned short, Element *, Element **, int *, int *, int);
		void FlushWorkingSet();
		virtual long GetAccessibleImpl(IAccessible **);
		static IClassInfo * GetClassInfoPtr();
		virtual IClassInfo * GetClassInfoW();

		static HWNDElement * GetFocusedHWNDElement();
		virtual HWND GetHWND();

		static Element * GetKeyFocusedElement();
		unsigned short GetUIState();
		bool GetWrapKeyboardNavigate();
		long Initialize(HWND, bool, unsigned int, Element *, unsigned long *);
		bool IsFirstElement(Element *);
		bool IsLastElement(Element *); 

		virtual void OnCompositionChanged();
		virtual void OnDestroy();
		virtual void OnEvent(Event *);
		
		virtual void OnGroupChanged(int, bool);
		virtual void OnInput(InputEvent *);
		virtual void OnNoChildWithShortcutFound(KeyboardEvent *);
		virtual void OnPropertyChanged(const PropertyInfo *, int, Value *, Value *);
		virtual void OnThemeChanged(ThemeChangedEvent *);
		static long Register();
		virtual void RemoveTooltip(Element *);
		static void SetClassInfoPtr(IClassInfo *);

		void SetFocus(bool);
		void SetParentSizeControl(bool);
		void SetScreenCenter(bool);
		long SetWrapKeyboardNavigate(bool);
		bool ShowAccel(void);
		bool ShowFocus(void);
		void ShowUIState(bool,bool);
		static class UID ThemeChange();

		void ToggleUIState(bool,bool);
		virtual void UpdateTooltip(Element * );
		static PropertyInfo const * WINAPI WrapKeyboardNavigateProp();

		static __int64 StaticWndProc(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual void OnWmThemeChanged(WPARAM wParam, LPARAM lParam);
		virtual void OnGetDlgCode(LPMSG, LRESULT *);
		virtual LRESULT WndProc(HWND, UINT uMsg, WPARAM wParam, LPARAM lParam);

	protected: 
		static bool FindShortcutRecursive(unsigned short, Element *, Element **, int *, int *, int);
	
	private: 
		static IClassInfo * s_pClassInfo;
	};
}