#pragma once
#ifndef _PROJECT_ONE_STRING_H
#define _PROJECT_ONE_STRING_H
#include"include.h"
namespace ProjectONE {
	class DLL_EXPORT String
	{
	public:
		String();
		~String();
	private:
		wchar_t* mStr = nullptr;
		uint32_t mLenght = 0;
		uint32_t mAllocs = 0;
		void Alloc(wchar** pp, uint32_t asize, uint32_t* psize = nullptr);
		void Free(void* pp);
	public:
		//
		String(uint32_t size);
		String(const wchar_t* s);
		//
		wchar& operator[](uint32_t i);
		const wchar& operator[](uint32_t i)const;
		//
		String& operator=(const char* s);
		String& operator=(const char16_t* s);
		String& operator=(const wchar_t* s);
		String& operator=(String& s);
		String& operator=(const std::string& s);
		//
		String& operator=(const int& s);
		String& operator=(const float& s);
		String& operator=(const uint32_t& s);
		String& operator=(const double& s);
		String& operator=(const int& s);
		String& operator=(const float& s);
		//
		//String& operator+=(const int& s);
		//String& operator+=(const float& s);
		//String& operator+=(const uint32_t& s);
		//String& operator+=(const double& s);
		//String& operator+=(const int& s);
		//String& operator+=(const float& s);
		//
		String& operator>>(int& s);
		String& operator>>(float& s);
		String& operator>>(uint32_t& s);
		String& operator>>(double& s);
		String& operator>>(int64_t& s);
		String& operator>>(uint64_t& s);
		//
		String& operator<<(int& s);
		String& operator<<(float& s);
		String& operator<<(uint32_t& s);
		String& operator<<(double& s);
		String& operator<<(int64_t& s);
		String& operator<<(uint64_t& s);
		//
		bool operator!=(const wchar* s);
		bool operator!=(String& s);
		//¼ì²âwchar ÊÇÊÇ·ñUTF16 true=UTF16 false= UTF32
		bool IsUTF16();
		//
		wchar* Data();
		//
		const wchar* Cstr();
		//
		void Clear();
		//
		bool Empty();
		//
		uint32_t Size();
		//
		bool Compare(const wchar* s);
		bool Compare(String& s);
		//
		void Append(const wchar* s);
		void Append(String& s);
		//
		void Resize(uint32_t newsize);
		//
		Utf8String ToUTF8();
		Utf16String ToUTF16();
		Utf32String ToUTF32();
	};
}
#endif // !_PROJECT_ONE_STRING_H