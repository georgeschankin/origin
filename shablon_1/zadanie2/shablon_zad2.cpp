
#include <iostream>
#include <vector>

template<typename T>
class Table
{
public:
    int l, c, L, C;
    int value;
    int* arr;
    Table(int unsigned line, int unsigned column)
    {
        this->l = line;
        this->c = column;

         arr = new int [l];

        for (int i = 0; i < l; i++)
        {
            arr[i] = new T[c];
        }
    }

    Table<T>& operator [](const int unsigned a)
    {
        this->C = a;
        //return Table<T>(*this, C);
        return arr[*this][L];
    }

    const Table<T>& operator [](const unsigned int a) const
    {
        this->C = a;
        //return Table<T>(*this, C);
        return arr[*this][L];     
    }

    Table<T>& operator =(const int obj)
    {
        /*if (this != &obj)
        {
            l = obj.l;
            c = obj.c;
        }
        return *this;*/

        this->value = obj;
        Table<T>(*this, L) = value;
        return Table<T>(*this, L);
        //return arr[*this][L] = value;
    }

    Table<T>& operator <<(std::ostream& out, const int num)
    {  
        out << num;
        return arr[this][out];
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
