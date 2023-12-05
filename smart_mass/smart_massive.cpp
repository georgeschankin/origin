
#include <iostream>
#include <Windows.h>

class smart_array
{
private:
	int size_, size2;
	int* arr, *arr1;
	//int* arr1;
	//int new_el;

public:
	smart_array(int size)
	{
		this->size_=size;

		arr = new int[size_];
		for (int i = 0; i < size_; i++)
		{
			arr[i] = i;
		}
	}

	smart_array& operator =(const smart_array& obj) //копирование
	{
		arr = new int[obj.size_];

		if (this != &obj)
		{
			if (size_ <= obj.size_)
			{
				//arr[obj.size_];
				for (int i = 0; i < obj.size_; i++) 
				{ 
					arr[i] = obj.arr[i]; 
				}
				size_ = obj.size_;
				size2 = ++size_;
			}
			else if (obj.size_ < size_)
			{
				//arr[size_];
				for (int i = 0; i < size_; i++)
				{
					obj.arr[i] = arr[i];
				}
			}
		}
		return *this;
	}

	smart_array(const smart_array& rhs)
	{
		arr = new int[rhs.size_];

		if (this != &rhs)
		{
			if (size_ <= rhs.size_)
			{
				for (int i = 0; i < rhs.size_; i++)
				{
					arr[i] = rhs.arr[i];
				}
				size_ = rhs.size_;
			}
			else if (rhs.size_ < size_)
			{
				for (int i = 0; i < size_; i++)
				{
					rhs.arr[i] = arr[i];
				}
			}
		}	
	}

	void add_element(int new_element)
	{
		//this->new_el = new_element;
		this->size2 = ++size_;
		arr1 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			if (i < size2 - 1)
			{
				arr1[i] = arr[i];
			}
			else
			{
				arr1[i] = new_element;
			}
		}
		//return arr1;
		//delete[] arr;
	}

	int get_element(int index)
	{
		for (int i = 0; i < size2; i++)
		{
			std::cout << arr1[i] << std::endl; //записал чтобы проверить какие элементы не выводит. В итоге получается что выводит с 0-4 (первые 5), предпоследний записывает нулем, 9 (последний), остальные элементы массива будто не записываются
		}
	    return arr1[index];
			
		if ((index >= size2) || (index < 0))
		{
			throw "введите корректный индекс";
		}
	}

	~smart_array()
	{
		delete[] arr, arr1;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//задание 1
	try 
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(23);
		arr.add_element(17);
		
		std::cout << "get_element = " << arr.get_element(5) << std::endl;
	}
	catch (const std::exception& ex) 
	{
		std::cout << ex.what() << std::endl;
	}

	//задание 2
	smart_array arr2(5);
	arr2.add_element(1);
	arr2.add_element(4);
	arr2.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);
	
	arr2 = new_array;

	return 0;
}