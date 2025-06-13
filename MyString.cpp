#include "MyString.hpp"

#include <cstring>

namespace
{
	void copy_str(char* dst, const char* src, const size_t len)
	{
		for (size_t i = 0; i < len; ++i)
		{
			dst[i] = src[i];
		}
	}
}

namespace custom
{

String::String(const char* str)
{
	size_t length = strlen(str);
	data_ = new char[length + 1];
	::copy_str(data_, str, length + 1);
}

String::String(const char* str, size_t count)
{
	data_ = new char[count + 1];
	::copy_str(data_, str, count + 1);
}

String::String(const String& other)
{
	size_t length = strlen(other.data_);
	data_ = new char[length + 1];
	::copy_str(data_, other.data_, length + 1);
}

String::String(String&& other) noexcept
{
	size_t length = strlen(other.data_);
	data_ = new char[length + 1];
	::copy_str(data_, other.data_, length + 1);
	delete[] other.data_;
	other.data_ = nullptr;
}

String::~String()
{
	delete[] data_;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] data_;
		size_t length = strlen(other.data_);
		data_ = new char[length + 1];
		::copy_str(data_, other.data_, length + 1);
	}

	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		delete[] data_;

		size_t length = strlen(other.data_);
		data_ = new char[length + 1];
		::copy_str(data_, other.data_, length);

		delete[] other.data_;
		other.data_ = nullptr;
	}

	return *this;
}

size_t String::size() const
{
	return strlen(data_);
}

const char* String::c_str() const
{
	return data_;
}

String String::substr(size_t start, size_t count) const
{
	if (count == 0)
	{
		return String();
	}

	return String(data_ + start, count);
}

void String::append(const char* str)
{
	if (str != nullptr)
	{
		size_t lengthOther = strlen(str);

		if (lengthOther > 0)
		{
			size_t length = strlen(data_);
			char* newdata = new char[length + lengthOther + 1];
			copy_str(newdata, data_, length);
			copy_str(newdata + length, str, lengthOther + 1);
			delete[] data_;
			data_ = newdata;
		}
	}
}

char& String::operator[](size_t index)
{
	return data_[index];
}

const char& String::operator[](size_t index) const
{
	return data_[index];
}

String& String::operator+=(const String& other)
{
	size_t length = size();
	size_t lengthOther = other.size();
	if (lengthOther > 0)
	{
		char* newdata = new char[length + lengthOther + 1];
		copy_str(newdata, data_, length);
		copy_str(newdata + length, other.data_, lengthOther + 1);
		delete[] data_;
		data_ = newdata;
	}

	return *this;
}

String operator+(const String& lhs, const String& rhs)
{
	String newStr = lhs;
	newStr += rhs;

	return newStr;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	for (char c : str) {
		os << c;
	}

	return os;
}

String::iterator String::begin() { return data_; }
String::const_iterator String::begin() const { return data_; }
String::const_iterator String::cbegin() const { return data_; }
String::iterator String::end() { return data_ + strlen(data_); }
String::const_iterator String::end() const { return data_ + strlen(data_); }
String::const_iterator String::cend() const { return data_ + strlen(data_); }

String::reverse_iterator String::rbegin() { return data_ + strlen(data_) - 1; }
String::const_reverse_iterator String::rbegin() const { return data_ + strlen(data_) - 1; }
String::const_reverse_iterator String::crbegin() const { return data_ + strlen(data_) - 1; }
String::reverse_iterator String::rend() { return data_ - 1; }
String::const_reverse_iterator String::rend() const { return data_ - 1; }
String::const_reverse_iterator String::crend() const { return data_ - 1; }

String::iterator String::find(const char c) const
{
	size_t length = strlen(data_);
	for (size_t i = 0; i < length; ++i)
	{
		if (data_[i] == c)
		{
			return &data_[i];
		}
	}

	return &data_[length];
}

} // namespace custom
