#pragma once

#ifndef _PROJECT_ONE_INCLUDE_H
#define _PROJECT_ONE_INCLUDE_H

//��׼��
#include<time.h>
#include<string>
#include<sstream>
#include<codecvt>
#include<vector>
#include<list>
#include<queue>
#include<fstream>
#include<memory>
#include<algorithm>
#include<map>

#include<filesystem>
// �߳�
#include<thread>
#include<condition_variable>
#include<mutex>
#include<functional>
#include<future>
#include<atomic>

#define __WIN32_PLATFORM 1

#ifdef __ANDROID_PLATFORM
#define VK_USE_PLATFORM_ANDROID_KHR 1
#elif __MIR_PLATFORM
#define VK_USE_PLATFORM_MIR_KHR 1
#elif __WAYLAND_PLATFORM
#define VK_USE_PLATFORM_WAYLAND_KHR 1
#elif __WIN32_PLATFORM
#define VK_USE_PLATFORM_WIN32_KHR 1
#include<Windows.h>
#include<VersionHelpers.h>
#elif __XCB_PLATFORM
#define VK_USE_PLATFORM_XCB_KHR 1
#elif __XLIB_PLATFORM
#define VK_USE_PLATFORM_XLIB_KHR 1
#endif // !_PLATFORM

#include<vulkan\vulkan.h>

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllimport)
#else
#define DLL_EXPORT __declspec(dllexport)
#endif // !DLL_EXPORT

#ifndef null
#define null 0
#endif // !null



typedef std::string		Utf8String;
typedef std::u16string	Utf16String;
typedef std::u32string	Utf32String;

typedef int BOOLEAN;
typedef void* Handle;
typedef char16_t char16;
typedef char32_t char32;
typedef double float64;
typedef wchar_t wchar;


enum class RESULT
{
	R_NEGATIVE = -1,							//�ܾ� 
	R_SUCCESS = 0,								//�ɹ�
	R_FAILED,											//ʧ��
	R_FAILED_NATIVE_WINDOW,			//ʧ��ԭ������
	R_FAILED_DEVICE,							//ʧ���豸							
	R_FAILED_RENDER_WINDOW,			//ʧ����Ⱦ����
	R_FAILED_TIMEOUT,							//ʧ�ܳ�ʱ
	R_INVALID_DEVICE,							//��Ч�豸
	R_INVALID_EXT,								//��Ч��չ��δ֧����չ
	R_INVALID_POINTER,						//��Чָ��
	R_ERROR_COMMAND,						//����ָ�� 
	R_NOT_READY,									//û׼����
	R_NOT_REALIZATION,						//Ϊʵ��
	R_NOT_SUPPORT,							//��֧��

};

#endif // !_PROJECT_ONE_INCLUDE_H
