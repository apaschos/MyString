#pragma once

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

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

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

	//void operator+(const String& other);
	//void append();
	iterator find(const char c) const;
	//String substr() const;

	//Iterator begin();
	//Iterator cbegin() const;
	//Iterator end();
	//Iterator cend() const;

	//void reserve();

private:
	char* data_;
};

} // namespace custom
