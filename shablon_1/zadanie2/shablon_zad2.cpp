
#include <iostream>
#include <vector>

template<typename T>
class Table
{
private:
    int l, c;
    int size_ = 0;
    T** arr;

public:
    Table(int line, int column)
    {
        this->l = line;
        this->c = column;    

        arr = new T* [l];

        for (int i = 0; i < l; i++)
        {
            arr[i] = new T[c];
        }
    }

    Table(const Table& other)
    {        
        this->l = other.l;
        this->c = other.c;
       
        arr = new T* [l];
        for (int i = 0; i < l; i++)
        {
            arr[i] = new T[c];
        }       
        
        for (size_t i = 0; i < other.l; i++)
        {
            for (size_t j = 0; j < other.c; j++)
            {
                arr[i][j] = other.arr[i][j];
            }
        }       
    };

    T& operator()(int i, int j)
    {
        if (i >= l || i < 0) throw std::out_of_range("индекс (i) вне диапазона");
        if (j >= c || j < 0) throw std::out_of_range("индекс (j) вне диапазона");

        return arr[i][j];
    };

    Table<T>& operator =(const Table<T>& obj)
    {
        if (this != &obj)
        {
            this->c = obj.c;
            this->l = obj.l;
           
            this->~Table();
           
            arr = new T* [l] ;
            for (int i = 0; i < l; i++)
            {
                arr[i] = new T[c]{};
            }           

            //копирование
            for (size_t i = 0; i < obj.l; i++)
            {
                for (size_t j = 0; j < obj.c; j++)
                {
                    arr[i][j] = obj.arr[i][j];
                }
            }           
            return *this;
        }  
        return *this;
    }

            class wrapper_line
            {
            private:
                T* arr_l;
                int c = 0;

            public:
                wrapper_line(T* arr_l, const int c_) : arr_l(arr_l), c(c_) {}

                T& operator[](int i)
                {           
					if (i >= c || i < 0)
					{
                       throw  std::out_of_range("индекс [j] вне диапазона") ;
					}
						
                    return arr_l[i];
                }

                
            };

			wrapper_line operator[](const int i) const
            {    
				if (i >= l || i < 0)
				{
                   throw  std::out_of_range("индекс [i] вне диапазона") ;
				}
					
                return wrapper_line(arr[i], c);
            };    

    friend std::ostream& operator <<(std::ostream& out, const Table<T>& num)
    {
        out << T.num;
        return out;
    }
    
    ~Table()
    {
        for (int i = 0; i < l; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main()
{
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
}
