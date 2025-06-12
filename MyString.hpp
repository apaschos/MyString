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

	//void operator+(const String& other);
	//void append();
	//Iterator find() const;
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