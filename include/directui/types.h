#pragma once

//forward declares
namespace DirectUI
{
    // Primitives
    typedef unsigned short Char;
	typedef unsigned short* String;
	struct Fill;
	struct Cursor;
	struct Graphic;
	struct LINEINFO;
	struct XMLParserCond;
	struct EnumMap;
	struct UiaRect;
	struct PropertyInfo;
	struct DepRecs;
	struct NavReference;
    
	// Base
    class BaseScrollBar;
    class BaseScrollViewer;
	class ClassInfoBase;
	class RefcountBase;

    // Elements
    class Element;
	class ElementWithHWND;
	class UnknownElement;
    class HWNDElement;
	class DialogElement;
	class AnimationStrip;
	class RefPointElement;
    class Button;
    class AutoButton;
	class PushButton;
	class RepeatButton;
	class Progress;
	class Page;
	class Pages;
	class ScrollBar;
	class Combobox;
	class Edit;
	class Expandable;
	class Expando;
	class XElement;

	// Accessibility
	class DuiAccessible;
    class AccessibleButton;
	class HWNDElementAccessible;
	class HWNDHostAccessible;
	class HWNDHostClientAccessible;


	// Layouts
	class Layout;
    class BorderLayout;
	class GridLayout;
	class FillLayout;
	class FlowLayout;
	class RowLayout;
	class NineGridLayout;
	class ShellBorderLayout;
	class TableLayout;
	class VerticalFlowLayout;
	
	// Common Controls
	class CCAVI;
	class CCBase;
	class CCBaseCheckRadioButton;
	class CCBaseScrollBar;
	class CCCheckBox;
	class CCCommandLink;
	class CCHScrollBar;
	class CCListBox;
	class CCListView;
	class CCProgressBar;
	class CCPushButton;
	class CCRadioButton;
	class CCSysLink;
	class CCTrackBar;
	class CCTreeView;
	class CCVScrollBar;
	class CCVScrollBar;
	class CCSysLink;

	// Browser
	class Browser;
	class BrowserSelectionProxy;

    // Providers
    class ElementProvider;
	class ExpandCollapseProvider;
	class GridItemProvider;
	class GridProvider;
	class HWNDElementProvider;
	class InvokeProvider;
    template <class X, class Y, int> class PatternProvider;
	class RangeValueProvider;
	class ScrollItemProvider;
	class ScrollProvider;
	class SelectionItemProvider;
	class SelectionProvider;
	class TableItemProvider;
	class TableProvider;
	class ToggleProvider;
	class ValueProvider;
    class XProvider;
    class XResourceProvider;
    
	// Proxies
	class Proxy;
	class ElementProxy;
	class ExpandCollapseProxy;
	class GridItemProxy;
	class HWNDElementProxy;
	class InvokeProxy;
	class NavigatorSelectionItemProxy;
	class ProgressRangeValueProxy;
	class ProviderProxy;
	class RangeValueProxy;
	class ScrollBarRangeValueProxy;
	class ScrollItemProxy;
	class ScrollProxy;
	class SelectionItemProxy;
	class SelectionProxy;
	class SelectorSelectionItemProxy;
	class SelectorSelectionProxy;
	class TableItemProxy;
	class TableProxy;
	class ToggleProxy;
	class ValueProxy;

	// Hosts
	class NativeHWNDHost;
	class HWNDHost;
	class XHost;

    // Events
	struct Event;
	struct InputEvent;
	struct KeyboardEvent;
	struct ThemeChangedEvent;
    
    // Interfaces
	class IElementListener {};
    struct IClassInfo;
    class IDataEngine;
	class IDataEntry;
	class IProvider;
	class ISBLeak;
	class IXProviderCP;
	class IXElementCP;
	struct IXmlReader;
	struct IRawElementProviderFragment;
	struct IRawElementProviderFragmentRoot;
	struct IRawElementProviderSimple;
	class IElementListener;

    // XML Parser
    class DUIXmlParser;
    class Schema;
	enum _DUI_PARSE_STATE;
	namespace ParserTools
	{
		struct ExprNode;
		class ValueParser;
	}
    
	// Auto Objects
    class AutoButton;
    class AutoLock;
    class AutoThread
	{
	public:
		AutoThread();
		~AutoThread();
		AutoThread& operator=(AutoThread const &);
		HRESULT Init();

	};
    class AutoVariant;

    // Misc
	class CritSecLock;
	class LinkedList;
	class DeferCycle;
	class UID;
	class StyleSheet;
    class Value;
    class Expression;
	class InvokeHelper;
	class ProviderProxy;
	enum NavigateDirection;
	enum ProviderOptions;
	template<typename T, int> class DynamicArray;
    template<typename> class SafeArrayAccessor;
	
	// Unknown
    class Bind;
	class CallstackTracker;
	class CheckBoxGlyph;
	class Clipper;
	class DCSurface;
	class DUIFactory;
	class ExpandoButtonGlyph;
	class FontCache;
	class FontCheckOut;
	class Movie;
	class Navigator;
	class Surface;
	class Thumb;
	class Viewer;
	class InvokeHelper;
	class Macro;
	class PText;
	class RadioButtonGlyph;
	class Repeater;
	class ResourceModuleHandles;
	class ScrollViewer;
	class Selector;
	class SelectorNoDefault;
	class StyledScrollViewer;
	class TaskPage;
	class TextGraphic;
	class XBaby;
}
