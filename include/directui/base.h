#pragma once

#include <directui/types.h>

namespace DirectUI
{
	class ClassInfoBase
	{
	public:
		ClassInfoBase(ClassInfoBase const &);
		ClassInfoBase();
		virtual ~ClassInfoBase();
		ClassInfoBase & operator=(ClassInfoBase const &);

		virtual void AddChild();
		virtual void AddRef();
		virtual void AssertPIZeroRef() const;
		static bool ClassExist(IClassInfo **, PropertyInfo const * const *, unsigned int, IClassInfo *, HINSTANCE, unsigned short const *, bool);
		virtual void Destroy();
		virtual PropertyInfo const * EnumPropertyInfo(unsigned int);
		virtual PropertyInfo const * GetByClassIndex(unsigned int);
		virtual int GetChildren() const;
		virtual unsigned int GetGlobalIndex() const;
		virtual HINSTANCE GetModule() const;
		virtual unsigned short const * GetName() const;
		virtual unsigned int GetPICount() const;
		long Initialize(HINSTANCE, unsigned short const *, bool, PropertyInfo const * const *, unsigned int);
		virtual bool IsGlobal() const;
		virtual bool IsSubclassOf(IClassInfo *) const;
		virtual bool IsValidProperty(PropertyInfo const *) const;
		long Register();
		virtual int Release();
		virtual void RemoveChild();
	};

	class RefcountBase
	{
	public:
		RefcountBase();
		virtual ~RefcountBase();

		long AddRef();
		long Release();
	};

	class BaseScrollBar
	{
	public:
		BaseScrollBar(BaseScrollBar const &);
		BaseScrollBar();
		BaseScrollBar & operator=(BaseScrollBar const &);
		virtual void End();

		virtual void Home();
		bool IsPinned();
		bool IsScrollable();
		virtual void LineDown(unsigned int);
		virtual void LineUp(unsigned int);
		void OnMaximumChanged(Value *);
		void OnMinimumChanged(Value *);
		void OnPageChanged(Value *);
		bool OnPageChanging(Value *);
		void OnPositionChanged(Value *);
		bool OnPositionChanging(Value *);
		virtual void PageDown(unsigned int);
		virtual void PageUp(unsigned int);
		static class UID Scroll();
		void SetPinned(bool);
	private:
		int GetPageInc();
	};

	class BaseScrollViewer : public Element, public IElementListener
	{
	public:
		BaseScrollViewer(BaseScrollViewer const &);
		BaseScrollViewer();
		virtual ~BaseScrollViewer();
		BaseScrollViewer & operator=(BaseScrollViewer const &);

		long Initialize(Element *, unsigned long *);
		virtual long Add(Element **, unsigned int);

		static IClassInfo * GetClassInfoPtr();
		virtual IClassInfo * GetClassInfoW();
		int GetPinning();
		int GetXBarVisibility();
		int GetXOffset();
		bool GetXScrollable();
		int GetYBarVisibility();
		int GetYOffset();
		bool GetYScrollable();

		virtual void OnEvent(Event *);
		virtual void OnInput(InputEvent *);
		virtual void OnListenedEvent(Element *, Event *);
		virtual void OnListenedInput(Element *, InputEvent *);
		virtual void OnListenedPropertyChanged(Element *, PropertyInfo const *, int, Value *, Value *);
		virtual bool OnListenedPropertyChanging(Element *, PropertyInfo const *, int, Value *, Value *);
		virtual void OnListenerAttach(Element *);
		virtual void OnListenerDetach(Element *);
		virtual void OnPropertyChanged(PropertyInfo const *, int, Value *, Value *);
		virtual bool OnPropertyChanging(PropertyInfo const *, int, Value *, Value *);

		static long Register();
		static void SetClassInfoPtr(IClassInfo *);

		long SetPinning(int);
		long SetXBarVisibility(int);
		long SetXOffset(int);
		long SetXScrollable(bool);
		long SetYBarVisibility(int);
		long SetYOffset(int);
		long SetYScrollable(bool);

		static PropertyInfo const * PinningProp();
		static PropertyInfo const * XBarVisibilityProp();
		static PropertyInfo const * XOffsetProp();
		static PropertyInfo const * XScrollableProp();
		static PropertyInfo const * YBarVisibilityProp();
		static PropertyInfo const * YOffsetProp();
		static PropertyInfo const * YScrollableProp();
	
	protected:
		void FireAnimationChangeEvent(bool);

	private:
		void CheckScroll(BaseScrollBar *, int, int, int);
		static IClassInfo * s_pClassInfo;
	};
}