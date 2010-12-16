#pragma once

#include <directui/types.h>

namespace DirectUI
{
    // exported for int
    template<typename>
    class SafeArrayAccessor 
    {
        public:
            SafeArrayAccessor();
            ~SafeArrayAccessor();
            operator typename*();
            long Access(SAFEARRAY  *, unsigned short);
            int Count();
           
		private:
			void *unk1;
			void *unk2;
			void *unk3;
    };

	class CritSecLock
	{
	public:
		CritSecLock(RTL_CRITICAL_SECTION*);
		~CritSecLock();
		CritSecLock & operator=(CritSecLock const &);
		void Unlock();
	};


	class Value
	{
	public:
		Value& operator=(const Value &);
		void AddRef();

		static Value* CreateAtom(unsigned short);
		static Value* CreateAtom(const String);
		static Value* CreateBool(bool);
		static Value* CreateColor(unsigned long);
		static Value* CreateColor(unsigned long, unsigned long, unsigned char);
		static Value* CreateColor(unsigned long, unsigned long, unsigned long, unsigned char);
		static Value* CreateCursor(HICON);
		static Value* CreateCursor(const String);
		static Value* CreateDFCFill(unsigned int, unsigned int);
		static Value* CreateDTBFill(const String, int, int);
		static Value* CreateElementList(DynamicArray<Element *,0> *);
		static Value* CreateElementRef(Element *);
		static Value* CreateEncodedString(const String);
		static Value* CreateExpression(Expression *);
		static Value* CreateFill(const Fill &);
		static Value* CreateGraphic(HBITMAP, unsigned char, unsigned int, bool, bool, bool);
		static Value* CreateGraphic(HENHMETAFILE, HENHMETAFILE);
		static Value* CreateGraphic(HICON, bool, bool, bool);
		static Value* CreateGraphic(const String, unsigned char, unsigned int, unsigned short, unsigned short, HINSTANCE, bool ,bool); 
		static Value* CreateGraphic(const String, unsigned short, unsigned short, HINSTANCE, bool, bool);
		static Value* CreateInt(int);
		static Value* CreateLayout(Layout *);
		static Value* CreatePoint(int, int);
		static Value* CreateRect(int, int, int, int);
		static Value* CreateSize(int, int);
		static Value* CreateString(const String, HINSTANCE);
		static Value* CreateStyleSheet(StyleSheet *);

		bool GetBool();
		Cursor * GetCursor();
		Element * GetElement();
		DynamicArray<Element *, 0>* GetElementList();
		Expression * GetExpression();
		const Fill * GetFill();
		Graphic * GetGraphic();
		void * GetImage();
		int GetInt();
		Layout * GetLayout();
		const LPPOINT GetPoint();
		const LPRECT GetRect();
		int GetRefCount() const;
		const LPSIZE GetSize();
		unsigned short const * GetString();
		StyleSheet * GetStyleSheet();
		int GetType() const;

		unsigned short GetAtom();
		static Value* GetAtomZero();
		static Value* GetBoolFalse();
		static Value* GetBoolTrue();
		static Value* GetColorTrans();
		static Value* GetCursorNull();
		static Value* GetElListNull();
		static Value* GetElementNull();
		static Value* GetExprNull();
		static Value* GetIntZero();
		static Value* GetLayoutNull();
		static Value* GetNull();
		static Value* GetPointZero();
		static Value* GetRectZero();
		static Value* GetSheetNull();
		static Value* GetSizeZero();
		static Value* GetStringNull();
		static Value* GetUnavailable();
		static Value* GetUnset();

		bool IsEqual(Value *);
		void Release();
		String ToString(String, unsigned int) const;
	private:
		void _ZeroRelease();
		static long StrDupW(const String, String*);
	};
	
 	// TODO: find a place to put this
	class Movie : public Element
	{
	public:
		Movie(Movie const &);
		Movie();
		virtual ~Movie();

		Movie & operator=(Movie const &);

		static long WINAPI Create(unsigned int, Element *, unsigned long *, Element **);
		static long WINAPI Create(Element *, unsigned long *, Element **);
		static UID WINAPI AdvanceFrame();

		void Forward();
		bool GetAutoStart();
		bool GetAutoStop();
		static IClassInfo * WINAPI GetClassInfoPtr();
		virtual IClassInfo * GetClassInfoW();
		int GetCompositingQuality();
		bool GetDrawOutlines();
		int GetInterpolationMode();
		unsigned short const * GetPath(Value **);
		int GetPixelOffsetMode();
		bool GetPlayAllFramesMode();
		bool GetRepeat();
		int GetSmoothingMode();
		HRESULT LoadFromPath(unsigned short const *);
		HRESULT LoadFromResource(HINSTANCE, int);
		virtual void OnDestroy();
		virtual void OnEvent(Event *);
		virtual void OnHosted(Element *);
		virtual void Paint(HDC, LPCRECT, LPCRECT, LPRECT, LPRECT);
		void Pause();
		void Play();
		static void WINAPI RawActionProc(struct GMA_ACTIONINFO *);
		static long WINAPI Register();
		void Resume();
		void Rewind();
		long SetAutoStart(bool);
		long SetAutoStop(bool);
		static void WINAPI SetClassInfoPtr(IClassInfo *);
		long SetCompositingQuality(int);
		long SetDrawOutlines(bool);
		long SetInterpolationMode(int);
		long SetPath(unsigned short const *);
		long SetPixelOffsetMode(int);
		long SetPlayAllFramesMode(bool);
		long SetRepeat(bool);
		long SetSmoothingMode(int);
		void doAction(struct GMA_ACTIONINFO *);

		static PropertyInfo const * WINAPI AutoStartProp();
		static PropertyInfo const * WINAPI AutoStopProp();
		static PropertyInfo const * WINAPI CompositingQualityProp();
		static PropertyInfo const * WINAPI DrawOutlinesProp();
		static PropertyInfo const * WINAPI InterpolationModeProp();
		static PropertyInfo const * WINAPI PathProp();
		static PropertyInfo const * WINAPI PixelOffsetModeProp();
		static PropertyInfo const * WINAPI PlayAllFramesModeProp();
		static PropertyInfo const * WINAPI RepeatProp();
		static PropertyInfo const * WINAPI SmoothingModeProp();

		private: 
			static IClassInfo * s_pClassInfo;
			void advanceFrameActionStart();
			void advanceFrameActionStop();
	};

}
