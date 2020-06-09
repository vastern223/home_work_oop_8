#pragma once
#include<iostream>
#include<ctime>

using namespace std;
class Array {
private:
	long* arr;
	int size;
	bool Size_check()const;
	bool Check_index(long index)const;
public:
	Array();
	Array(int size);
	Array(const Array& new_arr);
	~Array();
	void Add_arr_random();
	void Add_arr_keyboard();
	void Add_arr_default();
	void Show_arr()const;
	void Add_arr(long element);
	void Delete_arr_index(int index);
	void Sort_arr();
	long Get_Min_arr();
	long Get_Max_arr();
	double Get_Average_arr();
	Array operator++()const;
	Array operator--()const;
	Array operator++(int)const;
	Array operator--(int)const;
	Array operator-()const;
	Array& operator=(const Array& other);
    operator long()const;
	long operator[](const int index)const;
	void operator()(const int number);
	


};
