#pragma once

#ifndef _PROJECT_ONE_INCLUDE_H
#define _PROJECT_ONE_INCLUDE_H

//标准库
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
// 线程
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
	R_NEGATIVE = -1,							//拒绝 
	R_SUCCESS = 0,								//成功
	R_FAILED,											//失败
	R_FAILED_NATIVE_WINDOW,			//失败原生窗口
	R_FAILED_DEVICE,							//失败设备							
	R_FAILED_RENDER_WINDOW,			//失败渲染窗口
	R_FAILED_TIMEOUT,							//失败超时
	R_INVALID_DEVICE,							//无效设备
	R_INVALID_EXT,								//无效扩展、未支持扩展
	R_INVALID_POINTER,						//无效指针
	R_ERROR_COMMAND,						//错误指令 
	R_NOT_READY,									//没准备好
	R_NOT_REALIZATION,						//为实现
	R_NOT_SUPPORT,							//不支持

};

#endif // !_PROJECT_ONE_INCLUDE_H
