#include<iostream>
#include<assert.h>
#include<time.h>
#include<windows.h>

using namespace std;

class Date

{
public:
	friend ostream& operator<<(ostream& out, const Date& d);

	// ��ȡĳ��ĳ�µ�����
	/*int GetMonthDay(int year, int month)
	{
		static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int day = days[month];
		if(month == 2
			&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}*/
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}



	// �������캯��
  // d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



	// ��ֵ���������
  // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}



	// ��������
	~Date()
	{};



	// ����+=����
	Date& operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}



	// ����+����
	Date operator+(int day)
	{
		Date tmp(*this);
		tmp._day += day;
		ToCorrect(tmp);
		return tmp;
	}



	// ����-����
	Date operator-(int day)
	{
		Date tmp(*this);
		tmp._day -= day;
		ToCorrect(tmp);
		return tmp;
	}



	// ����-=����
	Date& operator-=(int day)
	{
		*this = *this - day;
		return *this;
	}



	// ǰ��++
	Date& operator++()
	{
		(*this)++;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date tmp(*this);
		(*this) += 1;
		return *this;
	}



	// ����--
	Date operator--(int)
	{
		Date tmp(*this);
		(*this) -= 1;
		return *this;
	}



	// ǰ��--
	Date& operator--()
	{
		(*this)--;
		return *this;
	}

	// >���������
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}



	// ==���������
	bool operator==(const Date& d)
	{
		return(_year == d._year && _month == d._month && _year == d._year && _month == d._month && _day == d._day);
	}



	// >=���������
	inline bool operator >= (const Date& d)
	{
		return !(*this < d);
	}



	// <���������
	bool operator < (const Date& d)
	{
		return(_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day));
	}



	// <=���������
	bool operator <= (const Date& d)
	{
		return (*this < d) || (*this == d);
	}



	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}



	// ����-���� ��������
	int operator-(const Date& d)
	{
		int i = 0;
		int day = 0;
		int day1 = JianDay(*this);
		int day2 = JianDay(d);
		if (*this > d)
		{
			for (i = d._year; i < _year; i++)
			{
				if (IsRunYear(i))
					day += 366;
				else
					day += 365;
			}
			day = day - day2 + day1;
		}
		else
		{
			for (i = _year; i <d._year; i++)
			{
				if (IsRunYear(i))
					day += 366;
				else
					day += 365;
			}
			day = day - day1 + day2;
		}
		return day;
	}

public:
	int JianDay(const Date &d)
	{
		int day = 0;
		for (int i = 1; i < d._month; i++)
		{
			day += GetMonthDay(d._year, d._month);
		}
		day += d._day;
		return day;
	}
	bool IsRunYear(int year)
	{
		if (year % 400 || (year % 4 && year % 100))
		return true;
		return false;
	}
	int GetMonthDay(int year, int month)
	{
		int day;
		int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		day = days[month];
		if (month == 2)
			day += IsRunYear(year);
		return day;
	}
	Date ToCorrect(Date& d)
	{
		//+���������
		if (d._day > GetMonthDay(d._year, d._month))
		{
			while (d._day > GetMonthDay(d._year, d._month))
			{
				d._day -= GetMonthDay(d._year, d._month);

				if (d._month == 12)
				{
					d._year++;
					d._month = 1;
				}
				else
				{
					++d._month;
				}
			}
		}
		else //��ȥ���������
		{
			while (d._day <= 0)
			{
				if (d._month == 1)
				{
					d._year--;
					d._month = 12;
				}
				else
				{
					--d._month;
				}
				d._day += GetMonthDay(d._year, d._month);
			}
		}
		return d;
	}


private:

	int _year;

	int _month;

	int _day;

};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��";
	return out;
}

void main()
{
	Date d(2021,3,5);
	Date d2(2024, 5, 3);
	cout << d << endl;
	//int day = d.GetMonthDay(2021,3);
	//Date d1;
	//d1 = d;
	cout << d2 << endl;
	bool t = d2 >= d;
	cout << t << endl;
	Date f;
	f = d -60;
	cout << f << endl;
	int day = 0;
	day = d2 - d;
	cout << day << endl;
}