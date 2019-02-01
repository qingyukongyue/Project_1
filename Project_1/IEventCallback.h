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
		//�¼�
		//virtual void Event(Event_E e, void* object,float elapsed) = 0;

		//�����¼�
		virtual void Keyboard(int button, int action, void* object, float elapsed) = 0;
		//virtual void KeyboardKeyDown(int button, void* object, float elapsed) = 0;
		//virtual void KeyboardKeyUp(int button, void* object, float elapsed) = 0;

		//����¼�
		virtual void MouseEvent(int x, int y, int button, int action, int wheel_delta, void* object, float elapsed) = 0;
		//virtual void MouseClick(int x, int y, int button, int wheel_delta, void* object, float elapsed) = 0;
		//virtual void MouseDoubleClick(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void MouseKeyDown(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void MouseKeyUp(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void MouseWheel(int x, int y, int action, int wheel_delta, void* object, float elapsed) = 0;
		//virtual void MouseMove(int x, int y, void* object, float elapsed) = 0;

		//�����¼�
		virtual void TouchEvent(int x, int y, int button, void* object, float elapsed) = 0;
		//virtual void TouchDown(int x, int y, void* object, float elapsed) = 0;
		//virtual void TouchUp(int x, int y, void* object, float elapsed) = 0;

		//�ı�����
		virtual void TextInputEvent(uint32_t text, void* object, float elapsed) = 0;

		//��С�ı�
		virtual void SizeChange(int w, int h, void* object, float elapsed) = 0;

		//��ȡ����
		virtual void SetFocus(void* object, float elapsed) = 0;

		//ʧȥ����
		virtual void LostFocus(void* object, float elapsed) = 0;

		//�ر�
		virtual void Close(void* object, float elapsed) = 0;

		//�ƶ�
		virtual void Move(int x, int y, void* object, float elapsed) = 0;

		//================
	};
	//ö�ٶ���
	enum Keys
	{
		//
		// Summary:
		//     �Ӽ�ֵ��ȡ���η���λ���Ρ�
		Modifiers = -65536,
		//
		// Summary:
		//     û�а��κμ���
		None = 0,
		//
		// Summary:
		//     �����ť��
		LButton = 1,
		//
		// Summary:
		//     ����Ұ�ť��
		RButton = 2,
		//
		// Summary:
		//     Cancel ����
		Cancel = 3,
		//
		// Summary:
		//     ����а�ť��������ť����꣩��
		MButton = 4,
		//
		// Summary:
		//     ��һ�� X ��갴ť�������ť����꣩��
		XButton1 = 5,
		//
		// Summary:
		//     �ڶ��� X ��갴ť�������ť����꣩��
		XButton2 = 6,
		// Summary:
		//     Backspace ����
		Back = 8,
		//
		// Summary:
		//     Tab ����
		Tab = 9,
		//
		// Summary:
		//     LINEFEED ����
		LineFeed = 10,
		//
		// Summary:
		//     Clear ����
		Clear = 12,
		//
		// Summary:
		//     Return ����
		Return = 13,
		//
		// Summary:
		//     Enter ����
		Enter = 13,
		//
		// Summary:
		//     Shift ����
		ShiftKey = 16,
		//
		// Summary:
		//     CTRL ����
		ControlKey = 17,
		//
		// Summary:
		//     Alt ����
		Menu = 18,
		//
		// Summary:
		//     Pause ����
		Pause = 19,
		//
		// Summary:
		//     CAPS LOCK ����
		Capital = 20,
		//
		// Summary:
		//     CAPS LOCK ����
		CapsLock = 20,
		//
		// Summary:
		//     IME Kana ģʽ����
		KanaMode = 21,
		//
		// Summary:
		//     IME Hanguel ģʽ������Ϊ�˱��ּ����Զ����ã�ʹ�� HangulMode��
		HanguelMode = 21,
		//
		// Summary:
		//     IME Hangul ģʽ����
		HangulMode = 21,
		//
		// Summary:
		//     IME Junja ģʽ����
		JunjaMode = 23,
		//
		// Summary:
		//     IME ����ģʽ����
		FinalMode = 24,
		//
		// Summary:
		//     IME Hanja ģʽ����
		HanjaMode = 25,
		//
		// Summary:
		//     IME Kanji ģʽ����
		KanjiMode = 25,
		//
		// Summary:
		//     Esc ����
		Escape = 27,
		//
		// Summary:
		//     IME ת������
		IMEConvert = 28,
		//
		// Summary:
		//     IME ��ת������
		IMENonconvert = 29,
		//
		// Summary:
		//     IME ���ܼ����滻 System.Windows.Forms.Keys.IMEAceept��
		IMEAccept = 30,
		//
		// Summary:
		//     IME ���ܼ����ѹ�ʱ������� System.Windows.Forms.Keys.IMEAccept��
		IMEAceept = 30,
		//
		// Summary:
		//     IME ģʽ���ļ���
		IMEModeChange = 31,
		//
		// Summary:
		//     �ո����
		Space = 32,
		//
		// Summary:
		//     Page Up ����
		Prior = 33,
		//
		// Summary:
		//     Page Up ����
		PageUp = 33,
		//
		// Summary:
		//     PAGE DOWN ����
		Next = 34,
		//
		// Summary:
		//     PAGE DOWN ����
		PageDown = 34,
		//
		// Summary:
		//     End ����
		End = 35,
		//
		// Summary:
		//     Home ����
		Home = 36,
		//
		// Summary:
		//     �������
		Left = 37,
		//
		// Summary:
		//     ���ϼ���
		Up = 38,
		//
		// Summary:
		//     ���Ҽ���
		Right = 39,
		//
		// Summary:
		//     ���¼���
		Down = 40,
		//
		// Summary:
		//     Select ����
		Select = 41,
		//
		// Summary:
		//     Print ����
		Print = 42,
		//
		// Summary:
		//     EXECUTE ����
		Execute = 43,
		//
		// Summary:
		//     Print Screen ����
		Snapshot = 44,
		//
		// Summary:
		//     Print Screen ����
		PrintScreen = 44,
		//
		// Summary:
		//     INS ����
		Insert = 45,
		//
		// Summary:
		//     DEL ����
		Delete = 46,
		//
		// Summary:
		//     HELP ����
		Help = 47,
		//
		// Summary:
		//     0 ����
		D0 = 48,
		//
		// Summary:
		//     1 ����
		D1 = 49,
		//
		// Summary:
		//     2 ����
		D2 = 50,
		//
		// Summary:
		//     3 ����
		D3 = 51,
		//
		// Summary:
		//     4 ����
		D4 = 52,
		//
		// Summary:
		//     5 ����
		D5 = 53,
		//
		// Summary:
		//     6 ����
		D6 = 54,
		//
		// Summary:
		//     7 ����
		D7 = 55,
		//
		// Summary:
		//     8 ����
		D8 = 56,
		//
		// Summary:
		//     9 ����
		D9 = 57,
		//
		// Summary:
		//     A ����
		A = 65,
		//
		// Summary:
		//     B ����
		B = 66,
		//
		// Summary:
		//     C ����
		C = 67,
		//
		// Summary:
		//     D ����
		D = 68,
		//
		// Summary:
		//     E ����
		E = 69,
		//
		// Summary:
		//     F ����
		F = 70,
		//
		// Summary:
		//     G ����
		G = 71,
		//
		// Summary:
		//     H ����
		H = 72,
		//
		// Summary:
		//     I ����
		I = 73,
		//
		// Summary:
		//     J ����
		J = 74,
		//
		// Summary:
		//     K ����
		K = 75,
		//
		// Summary:
		//     L ����
		L = 76,
		//
		// Summary:
		//     M ����
		M = 77,
		//
		// Summary:
		//     N ����
		N = 78,
		//
		// Summary:
		//     O ����
		O = 79,
		//
		// Summary:
		//     P ����
		P = 80,
		//
		// Summary:
		//     Q ����
		Q = 81,
		//
		// Summary:
		//     R ����
		R = 82,
		//
		// Summary:
		//     S ����
		S = 83,
		//
		// Summary:
		//     T ����
		T = 84,
		//
		// Summary:
		//     U ����
		U = 85,
		//
		// Summary:
		//     V ����
		V = 86,
		//
		// Summary:
		//     W ����
		W = 87,
		//
		// Summary:
		//     X ����
		X = 88,
		//
		// Summary:
		//     Y ����
		Y = 89,
		//
		// Summary:
		//     Z ����
		Z = 90,
		//
		// Summary:
		//     �� Windows �ձ����Microsoft Natural Keyboard�����幤��ѧ���̣���
		LWin = 91,
		//
		// Summary:
		//     �� Windows �ձ����Microsoft Natural Keyboard�����幤��ѧ���̣���
		RWin = 92,
		//
		// Summary:
		//     Ӧ�ó������Microsoft Natural Keyboard�����幤��ѧ���̣���
		Apps = 93,
		//
		// Summary:
		//     �����˯�߼���
		Sleep = 95,
		//
		// Summary:
		//     ���ּ����ϵ� 0 ����
		NumPad0 = 96,
		//
		// Summary:
		//     ���ּ����ϵ� 1 ����
		NumPad1 = 97,
		//
		// Summary:
		//     ���ּ����ϵ� 2 ����
		NumPad2 = 98,
		//
		// Summary:
		//     ���ּ����ϵ� 3 ����
		NumPad3 = 99,
		//
		// Summary:
		//     ���ּ����ϵ� 4 ����
		NumPad4 = 100,
		//
		// Summary:
		//     ���ּ����ϵ� 5 ����
		NumPad5 = 101,
		//
		// Summary:
		//     ���ּ����ϵ� 6 ����
		NumPad6 = 102,
		//
		// Summary:
		//     ���ּ����ϵ� 7 ����
		NumPad7 = 103,
		//
		// Summary:
		//     ���ּ����ϵ� 8 ����
		NumPad8 = 104,
		//
		// Summary:
		//     ���ּ����ϵ� 9 ����
		NumPad9 = 105,
		//
		// Summary:
		//     �˺ż���
		Multiply = 106,
		//
		// Summary:
		//     �Ӻż���
		Add = 107,
		//
		// Summary:
		//     �ָ�������
		Separator = 108,
		//
		// Summary:
		//     ���ż���
		Subtract = 109,
		//
		// Summary:
		//     ������
		Decimal = 110,
		//
		// Summary:
		//     ���ż���
		Divide = 111,
		//
		// Summary:
		//     F1 ����
		F1 = 112,
		//
		// Summary:
		//     F2 ����
		F2 = 113,
		//
		// Summary:
		//     F3 ����
		F3 = 114,
		//
		// Summary:
		//     F4 ����
		F4 = 115,
		//
		// Summary:
		//     F5 ����
		F5 = 116,
		//
		// Summary:
		//     F6 ����
		F6 = 117,
		//
		// Summary:
		//     F7 ����
		F7 = 118,
		//
		// Summary:
		//     F8 ����
		F8 = 119,
		//
		// Summary:
		//     F9 ����
		F9 = 120,
		//
		// Summary:
		//     F10 ����
		F10 = 121,
		//
		// Summary:
		//     F11 ����
		F11 = 122,
		//
		// Summary:
		//     F12 ����
		F12 = 123,
		//
		// Summary:
		//     F13 ����
		F13 = 124,
		//
		// Summary:
		//     F14 ����
		F14 = 125,
		//
		// Summary:
		//     F15 ����
		F15 = 126,
		//
		// Summary:
		//     F16 ����
		F16 = 127,
		//
		// Summary:
		//     F17 ����
		F17 = 128,
		//
		// Summary:
		//     F18 ����
		F18 = 129,
		//
		// Summary:
		//     F19 ����
		F19 = 130,
		//
		// Summary:
		//     F20 ����
		F20 = 131,
		//
		// Summary:
		//     F21 ����
		F21 = 132,
		//
		// Summary:
		//     F22 ����
		F22 = 133,
		//
		// Summary:
		//     F23 ����
		F23 = 134,
		//
		// Summary:
		//     F24 ����
		F24 = 135,
		//
		// Summary:
		//     NUM LOCK ����
		NumLock = 144,
		//
		// Summary:
		//     Scroll Lock ����
		Scroll = 145,
		//
		// Summary:
		//     �� Shift ����
		LShiftKey = 160,
		//
		// Summary:
		//     �� Shift ����
		RShiftKey = 161,
		//
		// Summary:
		//     �� Ctrl ����
		LControlKey = 162,
		//
		// Summary:
		//     �� Ctrl ����
		RControlKey = 163,
		//
		// Summary:
		//     �� Alt ����
		LAlt = 164,
		//
		// Summary:
		//     �� Alt ����
		RAlt = 165,
		//
		// Summary:
		//     ��������Windows 2000 ����߰汾����
		VolumeMute = 173,
		//
		// Summary:
		//     ��С��������Windows 2000 ����߰汾����
		VolumeDown = 174,
		//
		// Summary:
		//     ������������Windows 2000 ����߰汾����
		VolumeUp = 175,
		//
		// Summary:
		//     ý����һ��Ŀ����Windows 2000 ����߰汾����
		MediaNextTrack = 176,
		//
		// Summary:
		//     ý����һ��Ŀ����Windows 2000 ����߰汾����
		MediaPreviousTrack = 177,
		//
		// Summary:
		//     ý��ֹͣ����Windows 2000 ����߰汾����
		MediaStop = 178,
		//
		// Summary:
		//     ý�岥����ͣ����Windows 2000 ����߰汾����
		MediaPlayPause = 179,
		//
		// Summary:
		//     �����ʼ�����Windows 2000 ����߰汾����
		LaunchMail = 180,
		//
		// Summary:
		//     ѡ��ý�����Windows 2000 ����߰汾����
		SelectMedia = 181,
		//
		// Summary:
		//     ����Ӧ�ó���һ����Windows 2000 ����߰汾����
		LaunchApplication1 = 182,
		//
		// Summary:
		//     ����Ӧ�ó��������Windows 2000 ����߰汾����
		LaunchApplication2 = 183,
		//
		// Summary:
		//     ��ʽ��׼�����ϵ� OEM �ֺż���Windows 2000 ����߰汾����
		OemSemicolon = 186,
		//
		// Summary:
		//     OEM 1 ����
		Oem1 = 186,
		//
		// Summary:
		//     �κι���/���������ϵ� OEM �Ӻż���Windows 2000 ����߰汾����
		Oemplus = 187,
		//
		// Summary:
		//     �κι���/���������ϵ� OEM ���ż���Windows 2000 ����߰汾����
		Oemcomma = 188,
		//
		// Summary:
		//     �κι���/���������ϵ� OEM ���ż���Windows 2000 ����߰汾����
		OemMinus = 189,
		//
		// Summary:
		//     �κι���/���������ϵ� OEM ������Windows 2000 ����߰汾����
		OemPeriod = 190,
		//
		// Summary:
		//     ��ʽ��׼�����ϵ� OEM �ʺż���Windows 2000 ����߰汾����
		OemQuestion = 191,
		//
		// Summary:
		//     OEM 2 ����
		Oem2 = 191,
		//
		// Summary:
		//     ��ʽ��׼�����ϵ� OEM ���η�����Windows 2000 ����߰汾����
		Oemtilde = 192,
		//
		// Summary:
		//     OEM 3 ����
		Oem3 = 192,
		//
		// Summary:
		//     ��ʽ��׼�����ϵ� OEM �����ż���Windows 2000 ����߰汾����
		OemOpenBrackets = 219,
		//
		// Summary:
		//     OEM 4 ����
		Oem4 = 219,
		//
		// Summary:
		//     ��ʽ��׼�����ϵ� OEM �ܵ�����Windows 2000 ����߰汾����
		OemPipe = 220,
		//
		// Summary:
		//     OEM 5 ����
		Oem5 = 220,
		//
		// Summary:
		//     ��ʽ��׼�����ϵ� OEM �����ż���Windows 2000 ����߰汾����
		OemCloseBrackets = 221,
		//
		// Summary:
		//     OEM 6 ����
		Oem6 = 221,
		//
		// Summary:
		//     ��ʽ��׼�����ϵ� OEM ��/˫���ż���Windows 2000 ����߰汾����
		OemQuotes = 222,
		//
		// Summary:
		//     OEM 7 ����
		Oem7 = 222,
		//
		// Summary:
		//     OEM 8 ����
		Oem8 = 223,
		//
		// Summary:
		//     RT 102 ���ļ����ϵ� OEM �����Ż�б�ܼ���Windows 2000 ����߰汾����
		OemBackslash = 226,
		//
		// Summary:
		//     OEM 102 ����
		Oem102 = 226,
		//
		// Summary:
		//     Process Key ����
		ProcessKey = 229,
		//
		// Summary:
		//     ���ڽ� Unicode �ַ������������ݡ�Packet ��ֵ�����ڷǼ������뷨�� 32 λ�����ֵ�ĵ�λ�֡�
		Packet = 231,
		//
		// Summary:
		//     ATTN ����
		Attn = 246,
		//
		// Summary:
		//     Crsel ����
		Crsel = 247,
		//
		// Summary:
		//     Exsel ����
		Exsel = 248,
		//
		// Summary:
		//     ERASE EOF ����
		EraseEof = 249,
		//
		// Summary:
		//     PLAY ����
		Play = 250,
		//
		// Summary:
		//     ZOOM ����
		Zoom = 251,
		//
		// Summary:
		//     �����Ա�����ʹ�õĳ�����
		NoName = 252,
		//
		// Summary:
		//     PA1 ����
		Pa1 = 253,
		//
		// Summary:
		//     Clear ����
		OemClear = 254,
		//
		// Summary:
		//     �Ӽ�ֵ��ȡ�������λ���Ρ�
		KeyCode = 65535,
		//
		// Summary:
		//     Shift �޸ļ���
		Shift = 65536,
		//
		// Summary:
		//     Ctrl �޸ļ���
		Control = 131072,
		//
		// Summary:
		//     Alt �޸ļ���
		Alt = 262144
	};
	//======================================================
	//�����¼�ö�ٶ���
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
