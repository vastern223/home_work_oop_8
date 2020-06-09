#include "arr_class.h"


bool Array::Size_check()const
{
	return(size > 0);
}

bool Array::Check_index(long index)const
{
	return(index >= 0 && index <= size);
}

Array::Array()
{
	arr = nullptr;
	size = 0;
}

Array::Array(int size)
{
	this->size = size;
	arr = new long[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

}

Array::Array(const Array& new_arr)
{
	this->size = new_arr.size;
	this->arr = new long[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = new_arr.arr[i];
	}
}

Array:: ~Array()
{
	if (arr != nullptr)
		delete[] arr;
}


void Array::Add_arr_random()
{
	if (Size_check())
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
	}

}

void  Array::Add_arr_keyboard()
{
	if (Size_check())
	{
		for (int i = 0; i < size; i++)
		{
			cout << "enter arr[" << i << "]=";
			cin >> arr[i];
		}
	}

}

void Array::Add_arr_default()
{
	if (Size_check())
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = i;
		}
	}

}

void Array::Show_arr()const
{
	if (Size_check())
	{
		for (int i = 0; i < size; i++)
		{
			cout << "arr[" << i << "]=" << arr[i] << endl;
		}
	}
}

void Array::Add_arr(long element)
{

	long* new_arr = new long[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	delete[] arr;
	new_arr[size] = element;
	size++;
	arr = new_arr;

}

void Array::Delete_arr_index(int index)
{
	if (Size_check())
	{
		if (Check_index(index))
		{
			long* new_arr = new long[size - 1];
			for (int i = 0, j = 0; i < size; i++)
			{
				if (i != index)
				{
					new_arr[j] = arr[i];
					++j;
				}
			}
			delete[]arr;
			size--;
			arr = new_arr;
		}
	}
}

void Array::Sort_arr()
{
	if (Size_check())
	{
		long temp = 0;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}

long Array::Get_Min_arr()
{
	if (Size_check())
	{
		long min = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (min > arr[i])min = arr[i];
		}
		return min;
	}
}

long Array::Get_Max_arr()
{
	if (Size_check())
	{
		long max = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (max < arr[i])max = arr[i];
		}
		return max;
	}
}

double Array::Get_Average_arr()
{
	if (Size_check())
	{
		double average = 0;
		for (int i = 0; i < size; i++)
		{
			average += arr[i];
		}

		return average /= size;
	}
}

Array Array::operator++()const
{
	for (int i = 0; i < size; i++)
	{
		arr[i]++;
	}
	return *this;
}
Array Array::operator--()const
{
	for (int i = 0; i < size; i++)
	{
		arr[i]--;
	}
	return *this;
}
Array Array::operator++(int)const
{
	Array temp = *this;
	for (int i = 0; i < size; i++)
	{
		arr[i]++;
	}
	return temp;
}

Array Array:: operator--(int)const
{
	Array temp = *this;
	for (int i = 0; i < size; i++)
	{
		arr[i]--;
	}
	return temp;
}

Array Array:: operator-()const
{
	for (int i = 0; i < size; i++)
	{
		-arr[i];
	}
	return *this;
}
Array& Array:: operator=(const Array& other)
{
	if (this == &other)
		return *this;

	if (arr != nullptr)
		delete[] arr;

	this->size = other.size;

	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

Array:: operator long()const
{
	long sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}


long Array:: operator[](const int index)const
{
	if (index >= 0 && index < size)
		return arr[index];
}

void Array:: operator()(const int number)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] += number;
	}
}

