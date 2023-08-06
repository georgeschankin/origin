
#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
    int N, number_house, number_apartment;
    std::string city;
    std::string street;

public:
    std::string  get_output_address()
    {
        setlocale(LC_ALL, "Russian");        
        return (city + ", " + street + ", " + std::to_string(number_house) + ", " + std::to_string(number_apartment));
    }

Address(int number_house, int number_apartment, std::string city, std::string street)
    {
        this->city = city;
        this->street = street;
        this->number_apartment = number_apartment;
        this->number_house = number_house;
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
    std::ofstream f_out("out.txt", std::ios::app);

    int N, number_house, number_apartment;
    std::string city;
    std::string street;

    f_in >> N;

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
        Address addr(number_house, number_apartment, city, street);
        f_out << N;
        f_out << std::endl;
        f_out << addr.get_output_address();
        f_out << std::endl;
    }
    f_in.close();
    f_out.close();           
}

