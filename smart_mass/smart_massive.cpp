
#include <iostream>
#include <Windows.h>

class smart_array
{
private:
	int size_, size2;
	int* arr;
	int* arr1;

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

	smart_array(smart_array& obj) //копирование
	{
		arr = new int[obj.size_];

		for (int i = 0; i < obj.size_; i++) { arr[i] = obj.arr[i]; }

		size_ = obj.size_;
	}

	/*int copy_mass(int N, int* arr2)//копирование (не для задания 2)
	{
		arr1 = new int[N];
		for (int i = 0; i < N; i++)
		{
			arr1[i] = arr2[i];
		}

		return *arr1;
	}*/

	void add_element(int new_size)
	{
		this->size2 = new_size;
		arr1 = new int[size2 + size_];

		for (int i = 0; i < size2 + size_; i++)
		{
			if (i < size_)
			{
				arr1[i] = arr[i];
			}
			else
			{
				arr1[i] = i;
			}
		}
	}

	int get_element(int index)
	{
		do
		{
			if (index >= size2 + size_)
			{
				std::cout << "индекс элемента должен быть меньше или равен размеру массива. Введите правильное значение " << std::endl;
				std::cin >> index;
				continue;
			}
			else { break; }
		} while (index >= size2 + size_);
		return arr1[index];
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
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(16) << std::endl;
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
	
	arr2 = new_array;//не понимаю как сделать данную операцию через =, ведь нельзя перегрузить оператор =, могу ли сделать через метод класса copy_mass ?

	return 0;
}