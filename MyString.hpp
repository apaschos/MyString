#pragma once

#include <iostream>

namespace custom
{
class String
{
public:
	explicit String(const char* str = "");
	String(const String& other);
	String(String&& other) noexcept;
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;

	const char* c_str() const;
	size_t size() const;

	String substr(size_t start, size_t end) const;

	void append(const char* str);

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	String& operator+=(const String& other);
	friend String operator+(const String& lhs, const String& rhs);

	friend std::ostream& operator<<(std::ostream& os, const String& str);

	using iterator = char*;
	using const_iterator = const char*;
	using reverse_iterator = char*;
	using const_reverse_iterator = const char*;

	iterator begin();
	const_iterator begin() const;
	const_iterator cbegin() const;
	iterator end();
	const_iterator end() const;
	const_iterator cend()   const;

	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator crbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	const_reverse_iterator crend() const;

	iterator find(const char c) const;


private:
	String(const char* str, size_t count);

	char* data_;
};

} // namespace custom
