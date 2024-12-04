
#include <iostream>
#include <Windows.h>

class smart_array
{
private:
	int size_;
	int* arr;
	int count_ = 0;
	
public:
	smart_array(const int size)
	{
		this->size_=size;

		arr = new int[size_];
		for (int i = 0; i < size_; i++)
		{
			arr[i] = i;
		}
	}

	smart_array& operator =(const smart_array& obj)
	{		
		if (this != &obj)
		{			
			this->size_ = obj.size_;
			this->count_ = obj.count_;

			delete[] arr;

			arr = new int[obj.size_];

			for (int i = 0; i < obj.size_; i++)
			{
				this->arr[i] = obj.arr[i];
			}			
			return *this;
		}
		return *this;
	}

	smart_array(const smart_array& rhs)
	{		
		this->size_ = rhs.size_;
		this->count_ = rhs.count_;
		
		arr = new int[rhs.size_];
		
		for (int i = 0; i < rhs.size_; i++)
		{
			this->arr[i] = rhs.arr[i];
		}
		std::cout << std::endl;
	}

	void add_element(const int new_element)
	{
		if (count_ >= size_)
		{
			throw std::out_of_range("ошибка добавления элемента");
		}
		else
		{			
			arr[count_] = new_element;
			++count_;
		}
	}

	int get_element(const int index)
	{					
		if ((index >= count_) || (index < 0))
		{
			throw std::out_of_range("введите корректный индекс");
		}
		else
		{
			return arr[index];
		}
	}

	~smart_array()
	{
		delete[] arr;
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
		
		std::cout << "get_element = " << arr.get_element(7) << std::endl;
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