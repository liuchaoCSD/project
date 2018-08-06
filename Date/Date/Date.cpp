
#include<iostream>
using namespace std;
class Date{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	int Getmonthday(int _year, int _month)
	{
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		static int day = days[_month];
		if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))

		{
			return days[2] = 29;
		}
		else
		{
			return days[2] = 28;
		}
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		if (_year >= 1900
			&& _month > 0 && _month<13
			&& _day>0 && _day <= Getmonthday(_year, _month));
	}
	Date(const Date &d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	

	void Display()
	{
	cout << this << endl;
		cout << this->_year << "-"<< _month << " -" << _day << endl;
	}
	bool operator<(const Date &x)
	{
		if (_year < x._year)
		{
			return true;
		}
		else if (_year == x._year)
		{
			if (_month < x._month)
			{
				return true;
			}
			else if (_month == x._month)
			{
				if (_day < x._day)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool operator>(const Date &x)
	{
		if (_year > x._year)
		{
			return true;
		}
		else if (_year == x._year)
		{
			if (_month >x._month)
			{
				return true;
			}
			else if (_month == x._month)
			{
				if (_day > x._day)
				{
					return true;
				}
			}
		}
		return false;
	}

private :
	int _year;
	int _month;
	int _day;
	
};
int  main()
{
	Date d1(2008, 5, 12);
	Date d2(d1);
	d1.Display();
	d2.Display();
	return 0;
}