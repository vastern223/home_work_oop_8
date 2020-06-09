#include "Date.h"



bool Date::Date_check(int& day, int& month, int& year)const
{
	if (day >= 1 && day <= DAY)
	{
		if (month >= 1 && month <= MOUNTH)
		{
			if (year >= 1)
			{
				return true;
			}
		}
	}
	return false;
}

void Date::Mounth_plus(int& month)
{
	if (month + 1 <= MOUNTH)
	{
		this->month++;
	}
	else
	{
		this->year++;
		this->month = 1;
	}
}

int  Date::Conversion_month_in_days(int month)
{
	Year_check(year);
	int day_ = 0;
	for (int i = 0; i < month; i++)
	{
		day_ += Mounth_check(i + 1);
	}
	return day_;
}

void  Date::Year_check(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 == 0)
	{
		days[1] = 29;
	}
	else
	{
		days[1] = 28;
	}

}

int Date::Mounth_check(int month)const
{
	return days[month - 1];
}

Date::Date() : day(1), month(1), year(1) {};

Date::Date(int day, int month, int year) : Date()
{
	if (Date_check(day, month, year))
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

ifstream& Date::operator>>(ifstream& fin)
{
	fin >> this->day;
	fin >> this->month;
	fin >> this->year;
	return fin;
}
ofstream& Date::operator<<(ofstream& fout)const
{
	fout << day << endl;
	fout << month << endl;
	fout << year << endl;
	return fout;
}

Date  Date::operator+=(int number)
{
	for (int i = 0; i < number; i++)
	{
		Plas_day();
	}
	return *this;
}

Date  Date::operator-=(int number)
{
	for (int i = 0; i < number; i++)
	{
		Minus_day(); 
	}
	return *this;
}

Date  Date::operator()(int days)
{
	for (int i = 0; i < days; i++)
	{
		Plas_day();
	}
	return *this;
}

Date  Date::operator()(int months, int days)
{

	for (int i = 0; i < days; i++)
	{
		Plas_day();
	}
	for (int i = 0; i < months; i++)
	{
		Mounth_plus(month);
	}
	return *this;

}

Date  Date::operator()(int years, int months, int days)
{

	for (int i = 0; i < days; i++)
	{
		Plas_day();
	}
	for (int i = 0; i < months; i++)
	{
		Mounth_plus(month);
	}
	this->year += years;
	return *this;

}

void Date::Print_date()
{
	cout << "Day:" << day << endl;;
	cout << "Month:" << month << endl;
	cout << "Year:" << year << endl;
}

int& Date::Set_Year()
{
	return year;
}

int& Date::Set_Day()
{
	return day;
}
int& Date::Set_month()
{
	return month;
}

bool operator>(Date& other1, Date& other)
{
	if (other1.year == other.year)
	{
		return (other1.day + other1.Conversion_month_in_days(other1.month) > other.day + other.Conversion_month_in_days(other.month));
	}
	else return(other1.year > other.year);

}

bool  operator<(Date& other1, Date& other)
{
	if (other1.year == other.year)
	{
		return (other1.day + other1.Conversion_month_in_days(other1.month) < other.day + other.Conversion_month_in_days(other.month));
	}
	else return(other1.year < other.year);

}
bool operator==(Date& other1, Date& other)
{
	return (other1.day == other.day && other1.month == other.month && other1.year == other.year);
}

bool operator!=(Date& other1, Date& other)
{
	return (other1.day != other.day || other1.month !=other.month || other1.year != other.year);
}

void operator++(Date& other)
{

	other.Year_check(other.Set_Year());

	if (other.Set_Day() + 1 <= other.Mounth_check(other.Set_month()))
	{
		other.Set_Day()++;
	}
	else if (other.Set_month() + 1 <= MOUNTH)
	{
		other.Set_month()++;
		other.Set_Day() = 1;
	}
	else
	{
		other.Set_Year()++;
		other.Set_Day() = 1;
		other.Set_month() = 1;
	}
}


void operator--(Date& other)
{
	other.Year_check(other.Set_Year());

	if (other.Set_Day() - 1 > 0)
	{
		other.Set_Day()--;
	}
	else if (other.Set_month() - 1 > 0)
	{
		other.Set_month()--;
		other.Set_Day() = other.Mounth_check(other.Set_month());
	}
	else
	{
		other.Set_Year()--;
		other.Set_month() = 12;
		other.Set_Day() = other.Mounth_check(other.Set_month());
	}
}
