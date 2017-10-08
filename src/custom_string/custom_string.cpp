#define _SCL_SECURE_NO_WARNINGS // Suppress warning С4996 on Visual Studio
#include <locale>
#include <algorithm>
#include <clocale>
#include <cstring>
#include "custom_string.h"

CustomString::CustomString(const CustomString& s) : _size(s._size), _chars(_size ? new char[_size]() : nullptr)
{
	std::copy(s._chars, s._chars + s._size, _chars);
}

CustomString::CustomString(const char* s) : _size(0), _chars(nullptr)
{
	if (!s)
    {
        return;
    }
    _size = strlen(s) + 1;
	_chars = new char[_size];
	std::copy(s, s + _size, _chars);
}

CustomString::~CustomString()
{
	if (_chars) {
            delete[] _chars;
            _chars = nullptr;
        }
}

const CustomString& CustomString::operator = (CustomString s)
{
	swap(*this, s);
	return *this;
}

const CustomString& CustomString::operator += (const CustomString& rhs)
{
	CustomString res;
	res._size = getLength() + rhs.getLength() + 1;
	res._chars = new char[res._size];
	std::copy(_chars, _chars + getLength(), res._chars);
	std::copy(rhs._chars, rhs._chars + rhs._size, res._chars + getLength());
	swap(*this, res);
	return *this;
}

bool CustomString::stricmp(const CustomString& a, const CustomString& b)
{
	#define LOCALE_NAME_BUF_LEN 100
	size_t asize = a.getLength();
	size_t bsize = b.getLength();
	char locale[LOCALE_NAME_BUF_LEN] = { 0 };
	const char* l = std::setlocale(LC_ALL, nullptr);
	std::copy(l, l + strlen(l), locale);
	if (std::lexicographical_compare(
		a.c_str(), a.c_str() + a.getLength(), b.c_str(), b.c_str() + b.getLength(),
			[&locale](const char c1, const char c2)
			{
				return std::tolower(c1, std::locale(locale)) < std::tolower(c2, std::locale(locale));
			}
		)
	)
	{
		return true;
	}
	return false;
}

const char* CustomString::c_str() const
{
	return _chars;
}

CustomString operator + (CustomString left, const CustomString& right)
{
	return left += right;
}

std::ostream& operator << (std::ostream& out, const CustomString& str)
{
	return out << str.c_str();
}

std::istream& operator >> (std::istream& in, CustomString& str)
{
	#define BUFLEN 256
	char tmpChars[BUFLEN];
	in.getline(tmpChars, BUFLEN);
	str = CustomString(tmpChars);
	return in;
}

void swap(CustomString& first, CustomString& second)
{
	using std::swap;
	swap(first._size, second._size);
	swap(first._chars, second._chars);
}

void CustomString::hexlify(char* dst, bool addSpace, size_t n) const
{
	char dict[] = "0123456789ABCDEF";
	char* iter = dst;
	size_t len = 0;
	size_t symbLen = addSpace ? 3 : 2; // длина представления одного байта "XX_" (3) или "XX" (2)
	for (unsigned int i = 0; i < _size; ++i)
	{
		if (len < n - symbLen)
		{
			unsigned char c = _chars[i];
			*iter++ = dict[c >> 4];
			*iter++ = dict[c & 0x0F];
			if (addSpace)
			{
				*iter++ = ' ';
			}
			len += symbLen;
		}
	}
	*iter = '\0'; // И поставим жирную точку в этом вопросе.
}
