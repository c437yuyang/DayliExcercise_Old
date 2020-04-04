#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

class MyString
{
public:
	MyString(const char *str = NULL);
	MyString(const MyString &other);
	~MyString(void);
	MyString & operator = (const MyString & other);
private:
	char *m_data;
};


MyString::MyString(const char *str = nullptr)
	:m_data(nullptr)
{
	if (str == nullptr)
		return;

	size_t len = strlen(str);
	m_data = new char[len + 1];
	if (!m_data)
		return;

	strcpy(m_data, str);
}

MyString::MyString(const MyString &other)
	:m_data(nullptr)
{
	if (other.m_data == nullptr)
		return;

	size_t len = strlen(other.m_data); //这里按理说是可以重构出一个方法，但是要求不改变类的签名就算了
	m_data = new char[len + 1];
	if (!m_data)
		return;
	strcpy(m_data, other.m_data);
}

MyString::~MyString()
{
	if (m_data)
		delete[] m_data;

	m_data = nullptr;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other)
		return *this;

	if (other.m_data == nullptr)
	{
		if (m_data != nullptr)
			delete m_data;
		m_data = nullptr;
		return *this;
	}

	char *newstr = new char[strlen(other.m_data) + 1];
	strcpy(newstr, other.m_data);
	delete[] m_data;
	m_data = newstr;
	return *this;
}