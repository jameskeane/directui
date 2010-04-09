#pragma once

#include <directui/types.h>

namespace DirectUI
{
	class Layout
	{
	public:
		Layout(Layout const &);
		Layout();
		virtual ~Layout();
		Layout & operator=(Layout const &);

		virtual void Attach(Element *);
		static HRESULT WINAPI Create(Layout **);
		void Destroy();
		virtual void Detach(Element *);
		virtual void DoLayout(Element *, int, int);
		virtual Element * GetAdjacent(Element *, Element *, int, NavReference const *, unsigned long);
		Element * GetChildFromLayoutIndex(Element *, int, DynamicArray<Element *, 0> *);
		unsigned int GetLayoutChildCount(Element *);
		int GetLayoutIndexFromChild(Element *, Element *);
		void Initialize();
		virtual void OnAdd(Element *, Element **, unsigned int);
		virtual void OnLayoutPosChanged(Element *, Element *, int, int);
		virtual void OnRemove(Element *, Element **, unsigned int);
		virtual SIZE UpdateDesiredSize(Element *, int, int, Surface *);
		static void WINAPI UpdateLayoutRect(Element *, int, int, Element *, int, int, int, int);
	protected:
		void ClearCacheDirty();
		bool IsCacheDirty();
		void SetCacheDirty();
	};

	class FillLayout : public Layout
	{
	public:
		FillLayout(FillLayout const &);
		FillLayout();
		virtual ~FillLayout();

		FillLayout & operator=(FillLayout const &);

		static HRESULT WINAPI Create(int, int *, Value **);
		static HRESULT WINAPI Create(Layout **);
		virtual void DoLayout(Element *, int, int);
		virtual Element * GetAdjacent(Element *, Element *, int, NavReference const *, unsigned long);
		void Initialize();
		virtual SIZE UpdateDesiredSize(Element *, int, int, Surface *);
	};

    class BorderLayout;
	class GridLayout;
	class FillLayout;
	class FlowLayout;
	class RowLayout;
	class NineGridLayout;
	class ShellBorderLayout;
	class TableLayout;


	class VerticalFlowLayout : public Layout
	{
	public:	
		enum Align
		{
			LAYOUT_LEFT = 0,
			LAYOUT_RIGHT = 1,
			LAYOUT_CENTER = 2,
			LAYOUT_TOP = 0,
			LAYOUT_BOTTOM = 1,
			LAYOUT_MIDDLE = 2
		};

		VerticalFlowLayout(VerticalFlowLayout const &);
		VerticalFlowLayout();
		virtual ~VerticalFlowLayout();
		VerticalFlowLayout & operator=(VerticalFlowLayout const &);

		static HRESULT WINAPI Create(int, int *, Value **);
		static HRESULT WINAPI Create(bool, unsigned int horAlign, unsigned int, unsigned int vertAlign, Layout **);
		virtual void DoLayout(Element *, int, int);
		virtual Element * GetAdjacent(Element *, Element *, int, NavReference const *, unsigned long);
		int GetLine(Element *, Element *);
		void Initialize(bool, unsigned int, unsigned int, unsigned int);
		virtual SIZE UpdateDesiredSize(Element *, int, int, Surface *);

	protected:
		SIZE BuildCacheInfo(Element *, int, int, Surface *,bool);
		static SIZE WINAPI SizeZero(void);
	};
}