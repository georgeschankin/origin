
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
    
Address(int number_house, int number_apartment, std::string city, std::string street)
    {
        this->city = city;
        this->street = street;
        this->number_apartment = number_apartment;
        this->number_house = number_house;
    }

Address() {}

std::string  get_output_address()
    {
        setlocale(LC_ALL, "Russian");        
        return (city + ", " + street + ", " + std::to_string(number_house) + ", " + std::to_string(number_apartment)); //компилятор ругается на то что переменные number_apartment и number_house не инициализированы, хотя я их инициализировал в private
    }

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

    Address* addr = new Address [N];
   
    for (int i = 0; i < N; i++)
    {       
       f_in >> city; //город
       f_in >> street; //улица
       f_in >> number_house; //дом
       f_in >> number_apartment; //квартира
       addr[i] = Address(number_house, number_apartment, city, street);                 
    }
    
    for (int i = N - 1; i >= 0; i--)
    {     
       f_out << addr[i].get_output_address();   
       f_out << std::endl;
    }                

    delete[] addr;

    f_in.close();
    f_out.close();           
}

