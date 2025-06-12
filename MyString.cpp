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

String::~String()
{
	delete[] data_;
}

const char* String::c_str() const
{
	return data_;
}

size_t String::size() const
{
	return strlen(data_);
}

char& String::operator[](size_t index)
{
	return data_[index];
}

const char& String::operator[](size_t index) const
{
	return data_[index];
}


} // namespace custom
