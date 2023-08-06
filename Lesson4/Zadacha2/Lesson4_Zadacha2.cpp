#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
    int N, number_house, number_apartment;
    std::string city;
    std::string street;
    std::string temp;

public:
    std::string  get_output_address(Address* addresses, int N)
    {
        setlocale(LC_ALL, "Russian");
        sort(addresses, N);
        for (int i = 0; i < N; i++)
        {
           return (addresses[i].city + ", " + addresses[i].street + ", " + std::to_string(addresses[i].number_house) + ", " + std::to_string(addresses[i].number_apartment));
        }       
    }

    void sort(Address* addresses, int size) //сортировка
    {
        //std::string *temp;
        
        for (int i = 0; i < size - 1; i++) 
        {
            for (int j = 0; j < size - i - 1; j++) 
            {
                if (addresses[j].city > addresses[j + 1].city)
                {                    
                    temp = addresses[j].city;
                    addresses[j].city = addresses[j + 1].city;
                    addresses[j + 1].city = temp;
                }
            }
        }                      
    }

    Address(int number_house, int number_apartment, std::string city, std::string street)
    {
        this->city = city;
        this->street = street;
        this->number_apartment = number_apartment;
        this->number_house = number_house;
    }

    //Address() {}
    
};

int main()
{
    setlocale(LC_ALL, "Russian");

    /*std::ofstream f_in;
    f_in.open("in.txt");
    std::ofstream f_out;
    f_out.open("out.txt");*/

    std::ifstream f_in("in.txt");
    std::ofstream f_out("out.txt", std::ios::app);

    int N, number_house, number_apartment, i = 0;
    std::string city;
    std::string street;

    f_in >> N;

    Address** adr = new Address*[N];
   
    //читаю данные из файла
    while (!f_in.eof())
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                f_in >> city;
            }
            else if (j == 1)
            {
                f_in >> street;
            }
            else if (j == 2)
            {
                f_in >> number_house;
            }
            else if (j == 3)
            {
                f_in >> number_apartment;
            }
        }
        adr[i] = new Address(number_house, number_apartment, city, street);
        
        /*f_out << adr[i].get_output_address();
        f_out << std::endl;*/        
        i++;
        //W = i; //эту переменную применю для удаления массива
    }
    Address s();
    //s.sort(adr, N);
    f_out << N;
    f_out << std::endl;
    f_out << s().get_output_address(*adr, N);
    
    for (int j = 0; j < N; j++)
    {
        delete[] adr[j];
    }

    delete[] adr;

    f_in.close();
    f_out.close();
}
