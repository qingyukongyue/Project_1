#include "String.h"

namespace ProjectONE {

	String::String()
	{
	}


	String::~String()
	{
		this->Free(mStr);
	}


	void String::Alloc(wchar ** pp, uint32_t asize, uint32_t * psize)
	{
		uint32_t size = (asize + 7) / 8 * 8;
		*pp = new wchar[size];
		if (psize)
		{
			*psize = size;
		}
	}

	void String::Free(void * pp)
	{
		delete(pp);
	}

	String::String(uint32_t size)
	{
		this->Resize(size);
	}

	String::String(const wchar_t * s)
	{
		this->Append(s);
	}

	wchar & String::operator[](uint32_t i)
	{
		return mStr[i];
	}

	const wchar & String::operator[](uint32_t i) const
	{
		return mStr[i];
	}

	String & String::operator=(const char * s)
	{
		std::wstring_convert<std::codecvt_utf8<wchar>, wchar> cvt;
		this->Clear();
		this->Append(cvt.from_bytes(s).data());

		return *this;
	}

	String & String::operator=(const char16_t * s)
	{
		this->Clear();
		if (this->IsUTF16())
		{
			this->Append((wchar*)s);
			return *this;
		}
		std::wstring_convert<std::codecvt_utf8_utf16<char16>, char16> cvt;
		std::wstring_convert<std::codecvt_utf8<wchar>, wchar> cvt8;

		auto u8 = cvt.to_bytes(s);
		auto u4 = cvt8.from_bytes(u8);

		this->Append(u4.data());

		return *this;
	}

	String & String::operator=(const wchar_t * s)
	{
		this->Clear();
		this->Append(s);

		return *this;
	}

	String & String::operator=(String & s)
	{
		this->Clear();
		this->Append(s);

		return *this;
	}

	String & String::operator=(const std::string & s)
	{
		std::wstring_convert<std::codecvt_utf8<wchar>, wchar> cvt;
		this->Clear();
		this->Append(cvt.from_bytes(s).data());

		return *this;
	}

	String & String::operator=(const int & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Clear();
		this->Append(ss.str().data());
	}

	String & String::operator=(const float & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Clear();
		this->Append(ss.str().data());
	}

	String & String::operator=(const uint32_t & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Clear();
		this->Append(ss.str().data());
	}

	String & String::operator=(const double & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Clear();
		this->Append(ss.str().data());
		return *this;
	}

	String & String::operator<<(double & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Append(ss.str().data());
		return *this;
	}

	String & String::operator<<(int64_t & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Append(ss.str().data());
		return *this;
	}

	String & String::operator<<(uint64_t & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Append(ss.str().data());
		return *this;
	}

	String & String::operator >> (int64_t & s)
	{
		std::wstringstream ss;
		ss << mStr;
		ss >> s;
		return *this;
	}

	String & String::operator >> (uint64_t & s)
	{
		std::wstringstream ss;
		ss << mStr;
		ss >> s;
		return *this;
	}

	String & String::operator<<(int & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Append(ss.str().data());
		return *this;
	}

	String & String::operator<<(float & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Append(ss.str().data());
		return *this;
	}

	String & String::operator<<(uint32_t & s)
	{
		std::wstringstream ss;
		ss << s;
		this->Append(ss.str().data());
		return *this;
	}

	bool String::operator!=(const wchar * s)
	{
		if (this->Compare(s))
		{
			return false;
		}
		return true;
	}

	bool String::operator!=(String & s)
	{
		if (this->Compare(s))
		{
			return false;
		}
		return true;
	}

	bool String::IsUTF16()
	{
		if (sizeof(wchar) == sizeof(uint16_t)) return true;
		return false;
	}

	wchar * String::Data()
	{
		return mStr;
	}

	const wchar * String::Cstr()
	{
		return mStr;
	}

	void String::Clear()
	{
		mStr[0] = 0;
		mLenght = 0;
	}

	bool String::Empty()
	{
		if (mStr[0] != 0)return false;
		return true;
	}

	uint32_t String::Size()
	{
		return mLenght;
	}

	bool String::Compare(const wchar * s)
	{
		if (wcscmp(mStr, s) == 0)
		{
			return true;
		}
		return false;
	}

	bool String::Compare(String & s)
	{
		if (s.Size==mLenght)
		{
			if (wcscmp(mStr, s.Cstr()) == 0)
			{
				return true;
			}
		}
		return false;
	}

	void String::Append(const wchar * s)
	{
		uint32_t nsize = wcslen(s) + 1;
		if (nsize + mLenght > mAllocs)
		{
			wchar* p = nullptr;
			uint32_t newsize;
			this->Alloc(&p, nsize + mLenght, &newsize);

			wcscpy_s(p, UINT32_MAX, mStr);
			wcscpy_s(&p[mLenght], UINT32_MAX, s);

			this->Free(mStr);
			mStr = p;
		}
		else
		{
			wcscpy_s(&mStr[mLenght], UINT32_MAX, s);
		}
	}

	void String::Append(String & s)
	{
		this->Append(s);
	}

	void String::Resize(uint32_t newsize)
	{
		if (mAllocs > newsize + 1)
		{
			mStr[newsize] = 0;
			return;
		}
		auto p = mStr;
		this->Alloc(&mStr, newsize, &mAllocs);
		this->Clear();
		this->Append(p);
		this->Free(p);
	}

	Utf8String String::ToUTF8()
	{
		std::wstring_convert<std::codecvt_utf8<wchar>> cvt;
		auto rstr = cvt.to_bytes(mStr);
		return rstr;
	}

	Utf16String String::ToUTF16()
	{
		if (this->IsUTF16())
		{
			Utf16String rstr = (char16*)mStr;
			return rstr;
		}
		auto u8 = this->ToUTF8();
		std::wstring_convert<std::codecvt_utf16<char16>, char16> cvt;
		return cvt.from_bytes(u8);
	}

	Utf32String String::ToUTF32()
	{
		if (this->IsUTF16())
		{
			std::wstring_convert<std::codecvt_utf8<char32>, char32> cvt;
			auto u8 = this->ToUTF8();
			return cvt.from_bytes(u8);
		}
		Utf32String ss = (char32*)mStr;
		return ss;
	}

	String & String::operator >> (int & s)
	{
		std::wstringstream ss;
		ss << mStr;
		ss >> s;
		return *this;
	}

	String & String::operator >> (float & s)
	{
		std::wstringstream ss;
		ss << mStr;
		ss >> s;
		return *this;
	}

	String & String::operator >> (uint32_t & s)
	{
		std::wstringstream ss;
		ss << mStr;
		ss >> s;
		return *this;
	}

	String & String::operator >> (double & s)
	{
		std::wstringstream ss;
		ss << mStr;
		ss >> s;
		return *this;
	}

}