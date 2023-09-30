#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
    int number_house, number_apartment;
    std::string city;
    std::string street;   

public:
    static std::string get_output_address(Address* addresses, int N)
    {
        setlocale(LC_ALL, "Russian");
        //sort(addresses, N);
        for (int i = 0; i < N; i++)
        {
           return (addresses[i].city + ", " + addresses[i].street + ", " + std::to_string(addresses[i].number_house) + ", " + std::to_string(addresses[i].number_apartment));
        }       
    }

   static void sort(Address* addresses, int size) //сортировка
    {
       Address temp;
        
       for (int i = 0; i < size; i++)
       {
           for (int j = 0; j < size - i - 1; j++)
           {
               if (addresses[j].city < addresses[j + 1].city)
               {
                   temp = addresses[j];
                   addresses[j] = addresses[j + 1];
                   addresses[j + 1] = temp;
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

    Address()
    {}
};


int main()
{
    setlocale(LC_ALL, "Russian");

    /*std::ofstream f_in;
    f_in.open("in.txt");
    std::ofstream f_out;
    f_out.open("out.txt");*/

    std::ifstream f_in("in.txt");
    std::ofstream f_out("out.txt", std::ios::out);

    int N, number_house, number_apartment;
    std::string city;
    std::string street;

    f_in >> N;

    f_out << N;
    f_out << std::endl;

    Address* adr = new Address[N];
             
    //читаю данные из файла
    for (int i = 0; i < N; i++)
    {       
       f_in >> city; //город
       f_in >> street; //улица
       f_in >> number_house; //дом
       f_in >> number_apartment; //квартира
       adr[i] = Address(number_house, number_apartment, city, street);       
    }

    //f_out << Address::get_output_address(adr, N);

    Address::sort(adr, N);
    for (int i = N - 1; i >= 0; i--)
    {
        f_out << Address::get_output_address(&adr[i], N);
        f_out << std::endl;
    }
       
    delete[] adr;
      
    f_in.close();
    f_out.close();
}
