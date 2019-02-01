#pragma once
#ifndef _PROJECT_ONE_H
#define _PROJECT_ONE_H
#include"include.h"
namespace Project_ONE {


	//
	struct MyStruct_Event
	{
		
	};
	//
	class IEventCallback {
	public:
		//事件
		//virtual void Event(Event_E e, void* object,float elapsed) = 0;

		//键盘事件
		virtual void Keyboard(int button, int action, void* object, float elapsed) = 0;
		//virtual void KeyboardKeyDown(int button, void* object, float elapsed) = 0;
		//virtual void KeyboardKeyUp(int button, void* object, float elapsed) = 0;

		//鼠标事件
		virtual void MouseEvent(int x, int y, int button, int action, int wheel_delta, void* object, float elapsed) = 0;
		//virtual void MouseClick(int x, int y, int button, int wheel_delta, void* object, float elapsed) = 0;
		//virtual void MouseDoubleClick(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void MouseKeyDown(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void MouseKeyUp(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void MouseWheel(int x, int y, int action, int wheel_delta, void* object, float elapsed) = 0;
		//virtual void MouseMove(int x, int y, void* object, float elapsed) = 0;

		//触控事件
		virtual void TouchEvent(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void TouchDown(int x, int y, void* object, float elapsed) = 0;
		//virtual void TouchUp(int x, int y, void* object, float elapsed) = 0;

		//文本输入
		virtual void TextInputEvent(uint32_t text, void* object, float elapsed) = 0;

		//大小改变
		virtual void SizeChange(int w, int h, void* object, float elapsed) = 0;

		//获取焦点
		virtual void SetFocus(void* object, float elapsed) = 0;

		//失去焦点
		virtual void LostFocus(void* object, float elapsed) = 0;

		//关闭
		virtual void Close(void* object, float elapsed) = 0;

		//移动
		virtual void Move(int x, int y, void* object, float elapsed) = 0;

		//================
	};
	//枚举定义
	enum Keys
	{
		//
		// Summary:
		//     从键值提取修饰符的位屏蔽。
		Modifiers = -65536,
		//
		// Summary:
		//     没有按任何键。
		None = 0,
		//
		// Summary:
		//     鼠标左按钮。
		LButton = 1,
		//
		// Summary:
		//     鼠标右按钮。
		RButton = 2,
		//
		// Summary:
		//     Cancel 键。
		Cancel = 3,
		//
		// Summary:
		//     鼠标中按钮（三个按钮的鼠标）。
		MButton = 4,
		//
		// Summary:
		//     第一个 X 鼠标按钮（五个按钮的鼠标）。
		XButton1 = 5,
		//
		// Summary:
		//     第二个 X 鼠标按钮（五个按钮的鼠标）。
		XButton2 = 6,
		// Summary:
		//     Backspace 键。
		Back = 8,
		//
		// Summary:
		//     Tab 键。
		Tab = 9,
		//
		// Summary:
		//     LINEFEED 键。
		LineFeed = 10,
		//
		// Summary:
		//     Clear 键。
		Clear = 12,
		//
		// Summary:
		//     Return 键。
		Return = 13,
		//
		// Summary:
		//     Enter 键。
		Enter = 13,
		//
		// Summary:
		//     Shift 键。
		ShiftKey = 16,
		//
		// Summary:
		//     CTRL 键。
		ControlKey = 17,
		//
		// Summary:
		//     Alt 键。
		Menu = 18,
		//
		// Summary:
		//     Pause 键。
		Pause = 19,
		//
		// Summary:
		//     CAPS LOCK 键。
		Capital = 20,
		//
		// Summary:
		//     CAPS LOCK 键。
		CapsLock = 20,
		//
		// Summary:
		//     IME Kana 模式键。
		KanaMode = 21,
		//
		// Summary:
		//     IME Hanguel 模式键。（为了保持兼容性而设置；使用 HangulMode）
		HanguelMode = 21,
		//
		// Summary:
		//     IME Hangul 模式键。
		HangulMode = 21,
		//
		// Summary:
		//     IME Junja 模式键。
		JunjaMode = 23,
		//
		// Summary:
		//     IME 最终模式键。
		FinalMode = 24,
		//
		// Summary:
		//     IME Hanja 模式键。
		HanjaMode = 25,
		//
		// Summary:
		//     IME Kanji 模式键。
		KanjiMode = 25,
		//
		// Summary:
		//     Esc 键。
		Escape = 27,
		//
		// Summary:
		//     IME 转换键。
		IMEConvert = 28,
		//
		// Summary:
		//     IME 非转换键。
		IMENonconvert = 29,
		//
		// Summary:
		//     IME 接受键，替换 System.Windows.Forms.Keys.IMEAceept。
		IMEAccept = 30,
		//
		// Summary:
		//     IME 接受键。已过时，请改用 System.Windows.Forms.Keys.IMEAccept。
		IMEAceept = 30,
		//
		// Summary:
		//     IME 模式更改键。
		IMEModeChange = 31,
		//
		// Summary:
		//     空格键。
		Space = 32,
		//
		// Summary:
		//     Page Up 键。
		Prior = 33,
		//
		// Summary:
		//     Page Up 键。
		PageUp = 33,
		//
		// Summary:
		//     PAGE DOWN 键。
		Next = 34,
		//
		// Summary:
		//     PAGE DOWN 键。
		PageDown = 34,
		//
		// Summary:
		//     End 键。
		End = 35,
		//
		// Summary:
		//     Home 键。
		Home = 36,
		//
		// Summary:
		//     向左键。
		Left = 37,
		//
		// Summary:
		//     向上键。
		Up = 38,
		//
		// Summary:
		//     向右键。
		Right = 39,
		//
		// Summary:
		//     向下键。
		Down = 40,
		//
		// Summary:
		//     Select 键。
		Select = 41,
		//
		// Summary:
		//     Print 键。
		Print = 42,
		//
		// Summary:
		//     EXECUTE 键。
		Execute = 43,
		//
		// Summary:
		//     Print Screen 键。
		Snapshot = 44,
		//
		// Summary:
		//     Print Screen 键。
		PrintScreen = 44,
		//
		// Summary:
		//     INS 键。
		Insert = 45,
		//
		// Summary:
		//     DEL 键。
		Delete = 46,
		//
		// Summary:
		//     HELP 键。
		Help = 47,
		//
		// Summary:
		//     0 键。
		D0 = 48,
		//
		// Summary:
		//     1 键。
		D1 = 49,
		//
		// Summary:
		//     2 键。
		D2 = 50,
		//
		// Summary:
		//     3 键。
		D3 = 51,
		//
		// Summary:
		//     4 键。
		D4 = 52,
		//
		// Summary:
		//     5 键。
		D5 = 53,
		//
		// Summary:
		//     6 键。
		D6 = 54,
		//
		// Summary:
		//     7 键。
		D7 = 55,
		//
		// Summary:
		//     8 键。
		D8 = 56,
		//
		// Summary:
		//     9 键。
		D9 = 57,
		//
		// Summary:
		//     A 键。
		A = 65,
		//
		// Summary:
		//     B 键。
		B = 66,
		//
		// Summary:
		//     C 键。
		C = 67,
		//
		// Summary:
		//     D 键。
		D = 68,
		//
		// Summary:
		//     E 键。
		E = 69,
		//
		// Summary:
		//     F 键。
		F = 70,
		//
		// Summary:
		//     G 键。
		G = 71,
		//
		// Summary:
		//     H 键。
		H = 72,
		//
		// Summary:
		//     I 键。
		I = 73,
		//
		// Summary:
		//     J 键。
		J = 74,
		//
		// Summary:
		//     K 键。
		K = 75,
		//
		// Summary:
		//     L 键。
		L = 76,
		//
		// Summary:
		//     M 键。
		M = 77,
		//
		// Summary:
		//     N 键。
		N = 78,
		//
		// Summary:
		//     O 键。
		O = 79,
		//
		// Summary:
		//     P 键。
		P = 80,
		//
		// Summary:
		//     Q 键。
		Q = 81,
		//
		// Summary:
		//     R 键。
		R = 82,
		//
		// Summary:
		//     S 键。
		S = 83,
		//
		// Summary:
		//     T 键。
		T = 84,
		//
		// Summary:
		//     U 键。
		U = 85,
		//
		// Summary:
		//     V 键。
		V = 86,
		//
		// Summary:
		//     W 键。
		W = 87,
		//
		// Summary:
		//     X 键。
		X = 88,
		//
		// Summary:
		//     Y 键。
		Y = 89,
		//
		// Summary:
		//     Z 键。
		Z = 90,
		//
		// Summary:
		//     左 Windows 徽标键（Microsoft Natural Keyboard，人体工程学键盘）。
		LWin = 91,
		//
		// Summary:
		//     右 Windows 徽标键（Microsoft Natural Keyboard，人体工程学键盘）。
		RWin = 92,
		//
		// Summary:
		//     应用程序键（Microsoft Natural Keyboard，人体工程学键盘）。
		Apps = 93,
		//
		// Summary:
		//     计算机睡眠键。
		Sleep = 95,
		//
		// Summary:
		//     数字键盘上的 0 键。
		NumPad0 = 96,
		//
		// Summary:
		//     数字键盘上的 1 键。
		NumPad1 = 97,
		//
		// Summary:
		//     数字键盘上的 2 键。
		NumPad2 = 98,
		//
		// Summary:
		//     数字键盘上的 3 键。
		NumPad3 = 99,
		//
		// Summary:
		//     数字键盘上的 4 键。
		NumPad4 = 100,
		//
		// Summary:
		//     数字键盘上的 5 键。
		NumPad5 = 101,
		//
		// Summary:
		//     数字键盘上的 6 键。
		NumPad6 = 102,
		//
		// Summary:
		//     数字键盘上的 7 键。
		NumPad7 = 103,
		//
		// Summary:
		//     数字键盘上的 8 键。
		NumPad8 = 104,
		//
		// Summary:
		//     数字键盘上的 9 键。
		NumPad9 = 105,
		//
		// Summary:
		//     乘号键。
		Multiply = 106,
		//
		// Summary:
		//     加号键。
		Add = 107,
		//
		// Summary:
		//     分隔符键。
		Separator = 108,
		//
		// Summary:
		//     减号键。
		Subtract = 109,
		//
		// Summary:
		//     句点键。
		Decimal = 110,
		//
		// Summary:
		//     除号键。
		Divide = 111,
		//
		// Summary:
		//     F1 键。
		F1 = 112,
		//
		// Summary:
		//     F2 键。
		F2 = 113,
		//
		// Summary:
		//     F3 键。
		F3 = 114,
		//
		// Summary:
		//     F4 键。
		F4 = 115,
		//
		// Summary:
		//     F5 键。
		F5 = 116,
		//
		// Summary:
		//     F6 键。
		F6 = 117,
		//
		// Summary:
		//     F7 键。
		F7 = 118,
		//
		// Summary:
		//     F8 键。
		F8 = 119,
		//
		// Summary:
		//     F9 键。
		F9 = 120,
		//
		// Summary:
		//     F10 键。
		F10 = 121,
		//
		// Summary:
		//     F11 键。
		F11 = 122,
		//
		// Summary:
		//     F12 键。
		F12 = 123,
		//
		// Summary:
		//     F13 键。
		F13 = 124,
		//
		// Summary:
		//     F14 键。
		F14 = 125,
		//
		// Summary:
		//     F15 键。
		F15 = 126,
		//
		// Summary:
		//     F16 键。
		F16 = 127,
		//
		// Summary:
		//     F17 键。
		F17 = 128,
		//
		// Summary:
		//     F18 键。
		F18 = 129,
		//
		// Summary:
		//     F19 键。
		F19 = 130,
		//
		// Summary:
		//     F20 键。
		F20 = 131,
		//
		// Summary:
		//     F21 键。
		F21 = 132,
		//
		// Summary:
		//     F22 键。
		F22 = 133,
		//
		// Summary:
		//     F23 键。
		F23 = 134,
		//
		// Summary:
		//     F24 键。
		F24 = 135,
		//
		// Summary:
		//     NUM LOCK 键。
		NumLock = 144,
		//
		// Summary:
		//     Scroll Lock 键。
		Scroll = 145,
		//
		// Summary:
		//     左 Shift 键。
		LShiftKey = 160,
		//
		// Summary:
		//     右 Shift 键。
		RShiftKey = 161,
		//
		// Summary:
		//     左 Ctrl 键。
		LControlKey = 162,
		//
		// Summary:
		//     右 Ctrl 键。
		RControlKey = 163,
		//
		// Summary:
		//     左 Alt 键。
		LAlt = 164,
		//
		// Summary:
		//     右 Alt 键。
		RAlt = 165,
		//
		// Summary:
		//     静音键（Windows 2000 或更高版本）。
		VolumeMute = 173,
		//
		// Summary:
		//     减小音量键（Windows 2000 或更高版本）。
		VolumeDown = 174,
		//
		// Summary:
		//     增大音量键（Windows 2000 或更高版本）。
		VolumeUp = 175,
		//
		// Summary:
		//     媒体下一曲目键（Windows 2000 或更高版本）。
		MediaNextTrack = 176,
		//
		// Summary:
		//     媒体上一曲目键（Windows 2000 或更高版本）。
		MediaPreviousTrack = 177,
		//
		// Summary:
		//     媒体停止键（Windows 2000 或更高版本）。
		MediaStop = 178,
		//
		// Summary:
		//     媒体播放暂停键（Windows 2000 或更高版本）。
		MediaPlayPause = 179,
		//
		// Summary:
		//     启动邮件键（Windows 2000 或更高版本）。
		LaunchMail = 180,
		//
		// Summary:
		//     选择媒体键（Windows 2000 或更高版本）。
		SelectMedia = 181,
		//
		// Summary:
		//     启动应用程序一键（Windows 2000 或更高版本）。
		LaunchApplication1 = 182,
		//
		// Summary:
		//     启动应用程序二键（Windows 2000 或更高版本）。
		LaunchApplication2 = 183,
		//
		// Summary:
		//     美式标准键盘上的 OEM 分号键（Windows 2000 或更高版本）。
		OemSemicolon = 186,
		//
		// Summary:
		//     OEM 1 键。
		Oem1 = 186,
		//
		// Summary:
		//     任何国家/地区键盘上的 OEM 加号键（Windows 2000 或更高版本）。
		Oemplus = 187,
		//
		// Summary:
		//     任何国家/地区键盘上的 OEM 逗号键（Windows 2000 或更高版本）。
		Oemcomma = 188,
		//
		// Summary:
		//     任何国家/地区键盘上的 OEM 减号键（Windows 2000 或更高版本）。
		OemMinus = 189,
		//
		// Summary:
		//     任何国家/地区键盘上的 OEM 句点键（Windows 2000 或更高版本）。
		OemPeriod = 190,
		//
		// Summary:
		//     美式标准键盘上的 OEM 问号键（Windows 2000 或更高版本）。
		OemQuestion = 191,
		//
		// Summary:
		//     OEM 2 键。
		Oem2 = 191,
		//
		// Summary:
		//     美式标准键盘上的 OEM 波形符键（Windows 2000 或更高版本）。
		Oemtilde = 192,
		//
		// Summary:
		//     OEM 3 键。
		Oem3 = 192,
		//
		// Summary:
		//     美式标准键盘上的 OEM 左括号键（Windows 2000 或更高版本）。
		OemOpenBrackets = 219,
		//
		// Summary:
		//     OEM 4 键。
		Oem4 = 219,
		//
		// Summary:
		//     美式标准键盘上的 OEM 管道键（Windows 2000 或更高版本）。
		OemPipe = 220,
		//
		// Summary:
		//     OEM 5 键。
		Oem5 = 220,
		//
		// Summary:
		//     美式标准键盘上的 OEM 右括号键（Windows 2000 或更高版本）。
		OemCloseBrackets = 221,
		//
		// Summary:
		//     OEM 6 键。
		Oem6 = 221,
		//
		// Summary:
		//     美式标准键盘上的 OEM 单/双引号键（Windows 2000 或更高版本）。
		OemQuotes = 222,
		//
		// Summary:
		//     OEM 7 键。
		Oem7 = 222,
		//
		// Summary:
		//     OEM 8 键。
		Oem8 = 223,
		//
		// Summary:
		//     RT 102 键的键盘上的 OEM 尖括号或反斜杠键（Windows 2000 或更高版本）。
		OemBackslash = 226,
		//
		// Summary:
		//     OEM 102 键。
		Oem102 = 226,
		//
		// Summary:
		//     Process Key 键。
		ProcessKey = 229,
		//
		// Summary:
		//     用于将 Unicode 字符当作键击传递。Packet 键值是用于非键盘输入法的 32 位虚拟键值的低位字。
		Packet = 231,
		//
		// Summary:
		//     ATTN 键。
		Attn = 246,
		//
		// Summary:
		//     Crsel 键。
		Crsel = 247,
		//
		// Summary:
		//     Exsel 键。
		Exsel = 248,
		//
		// Summary:
		//     ERASE EOF 键。
		EraseEof = 249,
		//
		// Summary:
		//     PLAY 键。
		Play = 250,
		//
		// Summary:
		//     ZOOM 键。
		Zoom = 251,
		//
		// Summary:
		//     保留以备将来使用的常数。
		NoName = 252,
		//
		// Summary:
		//     PA1 键。
		Pa1 = 253,
		//
		// Summary:
		//     Clear 键。
		OemClear = 254,
		//
		// Summary:
		//     从键值提取键代码的位屏蔽。
		KeyCode = 65535,
		//
		// Summary:
		//     Shift 修改键。
		Shift = 65536,
		//
		// Summary:
		//     Ctrl 修改键。
		Control = 131072,
		//
		// Summary:
		//     Alt 修改键。
		Alt = 262144
	};
	//======================================================
	//输入事件枚举定义
	//======================================================
	enum InputEvent
	{
		MMove,
		MWheel,
		MDown,
		MUp,
		KeyDown,
		KeyUp,
		Text,
	};
}
#endif // !_PROJECT_ONE_H
