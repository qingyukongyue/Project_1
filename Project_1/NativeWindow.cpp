#include "NativeWindow.h"
namespace Project_ONE {
	NativeWindow::~NativeWindow()
	{
	}

#ifdef __WIN32_PLATFORM

	static NativeWindow* gp = nullptr;

	LRESULT NativeWindow::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (gp)
		{
			gp->Handle(hWnd, message, wParam, lParam);
		}
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	inline void NativeWindow::Handle(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		//
		static int mx, my, wheel;
		//
		static uint32_t text;
		//
		static float time;
		//
		static int action;
		//
		static int button;
		//
		if (eventcallback)
		{
			switch (message)
			{
				//
			case WM_SETFOCUS:
				eventcallback->SetFocus(this, time);
				break;
				//
			case WM_KILLFOCUS:
				eventcallback->LostFocus(this, time);
				break;
				//
			case WM_CLOSE:
				eventcallback->Close(this, time);
				break;
				//
			case WM_CHAR:
			case WM_SYSCHAR:
			//case WM_UNICHAR:
				eventcallback->TextInputEvent(wParam, this, time);
				break;
				//
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:
			case WM_KEYUP:
			case WM_SYSKEYUP:
				button = wParam;
				action = ((lParam >> 31) & 1) ? 0 : 1;
				if (wParam == VK_SHIFT)
				{
					if (GetAsyncKeyState(VK_LSHIFT) != 0) {
						eventcallback->Keyboard(Keys::LShiftKey, action, this, time);
					}
					if (GetAsyncKeyState(VK_RSHIFT) != 0) {
						eventcallback->Keyboard(Keys::RShiftKey, action, this, time);
					}
					return;
				}
				if (wParam == VK_CONTROL)
				{
					if (GetAsyncKeyState(VK_LCONTROL) != 0) {
						eventcallback->Keyboard(Keys::LControlKey, action, this, time);
					}
					if (GetAsyncKeyState(VK_RCONTROL) != 0) {
						eventcallback->Keyboard(Keys::RControlKey, action, this, time);
					}
					return;
				}
				if (wParam == VK_MENU)
				{
					if (GetAsyncKeyState(VK_LMENU) != 0) {
						eventcallback->Keyboard(Keys::LAlt, action, this, time);
					}
					if (GetAsyncKeyState(VK_RMENU) != 0) {
						eventcallback->Keyboard(Keys::RAlt, action, this, time);
					}
					return;
				}
				eventcallback->Keyboard(button, action, this, time);
				break;
				//
			case WM_RBUTTONDOWN:
			case WM_LBUTTONDOWN:
			case WM_MBUTTONDOWN:
			case WM_RBUTTONUP:
			case WM_LBUTTONUP:
			case WM_MBUTTONUP:
				//
				mx = LOWORD(lParam);
				my = HIWORD(lParam);
				//
				if (message == WM_LBUTTONDOWN || message == WM_LBUTTONUP)
					button = Keys::LButton;
				else if (message == WM_RBUTTONDOWN || message == WM_RBUTTONUP)
					button = Keys::RButton;
				else if (message == WM_MBUTTONDOWN || message == WM_MBUTTONUP)
					button = Keys::MButton;
				else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
					button = Keys::XButton1;
				else
					button = XButton2;
				//
				if (message == WM_LBUTTONDOWN || message == WM_RBUTTONDOWN ||
					message == WM_MBUTTONDOWN || message == WM_XBUTTONDOWN)
				{
					action = 1;
					SetCapture(hWnd);
				}
				else
				{
					action = 0;
					ReleaseCapture();
				}
				//
				eventcallback->MouseEvent(mx, my, button, action, wheel, this, time);
				//
				break;
			case WM_MOUSEMOVE:
				mx = LOWORD(lParam);
				my = HIWORD(lParam);
				//
				eventcallback->MouseEvent(mx, my, None, 0, wheel, this, time);
				break;
				//
			case WM_MOUSEWHEEL:
				mx = LOWORD(lParam);
				my = HIWORD(lParam);
				wheel = GET_WHEEL_DELTA_WPARAM(wParam);
				eventcallback->MouseEvent(mx, my, None, 0, wheel, this, time);
				break;
				//
			case WM_SIZE:
				mx = LOWORD(lParam);
				my = HIWORD(lParam);
				eventcallback->SizeChange(mx, my, this, time);
				break;
				//
			case WM_MOVE:
				mx = LOWORD(lParam);
				my = HIWORD(lParam);
				break;
				//
			case WM_TOUCH:
				//eventcallback->TouchDown()
				break;
			default:
				break;
			}

			//
			return;
		}

		//
		switch (message)
		{
			//
		case WM_SETFOCUS:
			this->SetFocus(this, time);
			break;
			//
		case WM_KILLFOCUS:
			this->LostFocus(this, time);
			break;
			//
		case WM_CLOSE:
			this->Close(this, time);
			break;
			//
		case WM_CHAR:
		case WM_SYSCHAR:
			//case WM_UNICHAR:
			this->TextInputEvent(wParam, this, time);
			break;
			//
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			button = wParam;
			action = ((lParam >> 31) & 1) ? 0 : 1;
			if (wParam == VK_SHIFT)
			{
				if (GetAsyncKeyState(VK_LSHIFT) != 0) {
					this->Keyboard(Keys::LShiftKey, action, this, time);
				}
				if (GetAsyncKeyState(VK_RSHIFT) != 0) {
					this->Keyboard(Keys::RShiftKey, action, this, time);
				}
				return;
			}
			if (wParam == VK_CONTROL)
			{
				if (GetAsyncKeyState(VK_LCONTROL) != 0) {
					this->Keyboard(Keys::LControlKey, action, this, time);
				}
				if (GetAsyncKeyState(VK_RCONTROL) != 0) {
					this->Keyboard(Keys::RControlKey, action, this, time);
				}
				return;
			}
			if (wParam == VK_MENU)
			{
				if (GetAsyncKeyState(VK_LMENU) != 0) {
					this->Keyboard(Keys::LAlt, action, this, time);
				}
				if (GetAsyncKeyState(VK_RMENU) != 0) {
					this->Keyboard(Keys::RAlt, action, this, time);
				}
				return;
			}
			this->Keyboard(button, action, this, time);
			break;
			//
		case WM_RBUTTONDOWN:
		case WM_LBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_LBUTTONUP:
		case WM_MBUTTONUP:
			//
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			//
			if (message == WM_LBUTTONDOWN || message == WM_LBUTTONUP)
				button = Keys::LButton;
			else if (message == WM_RBUTTONDOWN || message == WM_RBUTTONUP)
				button = Keys::RButton;
			else if (message == WM_MBUTTONDOWN || message == WM_MBUTTONUP)
				button = Keys::MButton;
			else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
				button = Keys::XButton1;
			else
				button = XButton2;
			//
			if (message == WM_LBUTTONDOWN || message == WM_RBUTTONDOWN ||
				message == WM_MBUTTONDOWN || message == WM_XBUTTONDOWN)
			{
				action = 1;
				SetCapture(hWnd);
			}
			else
			{
				action = 0;
				ReleaseCapture();
			}
			//
			this->MouseEvent(mx, my, button, action, wheel, this, time);
			//
			break;
		case WM_MOUSEMOVE:
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			//
			this->MouseEvent(mx, my, None, 0, wheel, this, time);
			break;
			//
		case WM_MOUSEWHEEL:
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			wheel = GET_WHEEL_DELTA_WPARAM(wParam);
			this->MouseEvent(mx, my, None, 0, wheel, this, time);
			break;
			//
		case WM_SIZE:
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			this->SizeChange(mx, my, this, time);
			break;
			//
		case WM_MOVE:
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			break;
			//
		case WM_TOUCH:
			//eventcallback->TouchDown()
			break;
		default:
			break;
		}

		//
		return;

	}

	RESULT NativeWindow::Create(int w, int h, const wchar * text, bool noborder)
	{
		//
		auto err = RESULT::R_FAILED_NATIVE_WINDOW;
		//
		DWORD dwStyle;

		//==============================
		if (noborder)
		{
			dwStyle = WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		}
		else
		{
			dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		}
		//
		instance = GetModuleHandle(0);
		//
		auto name = L"Project ONE";
		//注册窗口类
		WNDCLASSEXW wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = 0;
		wcex.lpfnWndProc = wndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = instance;
		wcex.hIcon = 0;
		wcex.hCursor = 0;
		wcex.hbrBackground = 0;
		wcex.lpszMenuName = 0;
		wcex.lpszClassName = name;
		wcex.hIconSm = 0;

		if (!RegisterClassExW(&wcex)) {
			std::runtime_error("注册窗口类失败\n");
			return err;
		}
		//
		window = CreateWindowW(
			name,
			name,
			dwStyle,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			w,
			h,
			nullptr,
			nullptr,
			instance,
			nullptr);

		if (!window)
		{
			std::runtime_error("无法创建窗口\n");
			return err;
		}
		RECT rc;
		GetClientRect(window, &rc);
		windowRect.x = rc.left;
		windowRect.y = rc.top;
		windowRect.w = rc.right;
		windowRect.h = rc.bottom;

		return RESULT::R_SUCCESS;
	}

	inline bool NativeWindow::Loop(bool fast)
	{
		static MSG msg;
		if (fast)
		{
			while (!close)
			{
				//
				PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE);
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				//
			}
			//
		}
		else
		{
			//
			while (!close)
			{
				//
				GetMessage(&msg, nullptr, 0, 0);
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				//
			}
			//
		}
		return false;
	}

	void NativeWindow::CloseWindow()
	{
		DestroyWindow(window);
		close = true;
		//PostQuitMessage(0);

	}

	void NativeWindow::Show()
	{
		ShowWindow(window, SW_SHOW);
	}

	void NativeWindow::Hide()
	{
		ShowWindow(window, SW_HIDE);
	}

	void NativeWindow::Resize(int w, int h)
	{
		windowRect.w = w;
		windowRect.h = h;
		MoveWindow(window, windowRect.x, windowRect.y, windowRect.w, windowRect.h, TRUE);
	}

	void NativeWindow::Move(int x, int y)
	{
		windowRect.x = x;
		windowRect.y = y;
		MoveWindow(window, windowRect.x, windowRect.y, windowRect.w, windowRect.h, TRUE);
	}

	void NativeWindow::GetSize(int * w, int * h)
	{
		*w = windowRect.w;
		*h = windowRect.h;
	}

	void NativeWindow::GetPosition(int * x, int * y)
	{
		*x = windowRect.x;
		*y = windowRect.y;
	}

	void NativeWindow::SetTitle(const wchar * title)
	{
		this->title = title;
		SetWindowTextW(window, title);
	}

	const wchar * NativeWindow::GetTitle()
	{
		return title.data();
	}


	void NativeWindow::Keyboard(int button, int action, void * object, float elapsed)
	{
	}

	void NativeWindow::MouseEvent(int x, int y, int button, int action, int wheel_delta, void * object, float elapsed)
	{
	}

	void NativeWindow::TouchEvent(int x, int y, int button, void * object, float elapsed)
	{
	}

	void NativeWindow::TextInputEvent(uint32_t text, void * object, float elapsed)
	{
	}

	void NativeWindow::SizeChange(int w, int h, void * object, float elapsed)
	{
	}

	void NativeWindow::SetFocus(void * object, float elapsed)
	{
	}

	void NativeWindow::LostFocus(void * object, float elapsed)
	{
	}

	void NativeWindow::Close(void * object, float elapsed)
	{
		this->CloseWindow();
	}

	void NativeWindow::Move(int x, int y, void * object, float elapsed)
	{
	}



#endif // __WIN32_PLATFORM

}