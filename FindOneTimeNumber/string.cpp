#include<iostream>
//#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

	class String
	{
	public:
		String(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		String(const String& s) :_str(nullptr)
		{
			String strTmp(s._str);
			swap(_str, strTmp._str);
		}

		String& operator=(const String& s)
		{
			if (this != &s)
			{
				String strTmp(s._str);
				swap(_str, strTmp._str);
			}
			return *this;

		}

		~String()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}

	private:
		char* _str;
	};

void main()
{
	String s("abc");
	String s1("xyz");
	s1 = s;
}