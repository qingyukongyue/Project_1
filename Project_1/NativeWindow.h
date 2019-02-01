#pragma once
#ifndef _P_NATIVE_WINDOW_H
#define _P_NATIVE_WINDOW_H
#include"IEventCallback.h"
#include"MyStruct.h"
namespace Project_ONE {

	class DLL_EXPORT NativeWindow : public IEventCallback
	{
	public:

		virtual	~NativeWindow();

		//
		virtual void SetEventCallback(IEventCallback* pcallback) { eventcallback = pcallback; }
		//
	protected:
		//
		IEventCallback* eventcallback = nullptr;
		//窗口范围
		RECTI windowRect;
		std::wstring title;

		bool close = false;

		// WIN32平台
#ifdef __WIN32_PLATFORM


		HWND window = 0;
		HINSTANCE instance = 0;
		//
		static LRESULT _stdcall wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		//
		void Handle(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		//
		virtual RESULT Create(int w, int h, const wchar* text, bool noborder);
		//
	public:
		//virtual HWND GetWindowHandle() { return window; }
		//virtual HINSTANCE GetInstaceHandle() { return instance; }


#endif // __WIN32_PLATFORM

	public:
		//
		virtual bool Loop(bool fast = true);
		//
		virtual void CloseWindow();
		//
		virtual void Show();
		//
		virtual void Hide();
		//
		virtual void Resize(int w, int h);
		//
		virtual void Move(int x, int y);
		//
		virtual void GetSize(int* w, int* h);
		//
		virtual void GetPosition(int* x, int * y);
		//
		virtual void SetTitle(const wchar* title);
		//
		virtual const wchar* GetTitle();

		// 通过 IEventCallback 继承
		//virtual void Event(Event_E e, void* object, float elapsed) override;

		virtual void Keyboard(int button, int action, void * object, float elapsed) override;

		virtual void MouseEvent(int x, int y, int button, int action, int wheel_delta, void * object, float elapsed) override;

		virtual void TouchEvent(int x, int y, int button, void * object, float elapsed) override;

		virtual void TextInputEvent(uint32_t text, void * object, float elapsed) override;


		// 通过 IEventCallback 继承
		virtual void SizeChange(int w, int h, void * object, float elapsed) override;


		// 通过 IEventCallback 继承
		virtual void SetFocus(void * object, float elapsed) override;

		virtual void LostFocus(void * object, float elapsed) override;

		virtual void Close(void * object, float elapsed) override;

		virtual void Move(int x, int y, void * object, float elapsed) override;

	};
}
#endif // !_P_NATIVE_WINDOW_H
