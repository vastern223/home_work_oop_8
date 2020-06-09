#pragma once
#include<iostream>
#include<fstream>
using namespace std;

enum Date_ { DAY = 31, MOUNTH = 12 };

class Date
{
	int day;
	int month;
	int year;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	bool Date_check(int& day, int& month, int& year)const;
	void Mounth_plus(int& month);
	int Conversion_month_in_days(int month);
public:
	void Year_check(int year);
	int Mounth_check(int month)const;
	Date();
	Date(int day, int month, int year);
	ifstream& operator>>(ifstream& fin);
	ofstream& operator<<(ofstream& fout)const;
	Date operator+=(int number);
	Date operator-=(int number);
	Date operator()(int days);
	Date operator()(int months, int days);
	Date operator()(int years, int months, int days);
	void Print_date();
	int& Set_Year();
	int& Set_Day();
	int& Set_month();
	void Plas_day()
	{

		Year_check(year);

		if (day+ 1 <= Mounth_check(month))
		{
			day++;
		}
		else if (month + 1 <= MOUNTH)
		{
			month++;
			day = 1;
		}
		else
		{
			year++;
			day = 1;
			month = 1;
		}
	}

	void Minus_day()
	{

		Year_check(year);

		if (day - 1 > 0)
		{
			day--;
		}
		else if (month - 1 > 0)
		{
			month--;
			day = Mounth_check(month);
		}
		else
		{
			year--;
			month = 12;
			day = Mounth_check(month);
		}
	}
	friend bool operator>(Date& other1, Date& other);
	friend bool operator<(Date& other1, Date& other);
	friend bool operator==(Date& other1, Date& other);
	friend bool operator!=(Date& other1, Date& other);
};

void operator++(Date& other);
void operator--(Date& other);

