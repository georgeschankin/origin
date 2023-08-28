
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
    std::ofstream f_out("out.txt", std::ios::out);

    int N, number_house, number_apartment;
    std::string city;
    std::string street;

    f_in >> N;

    f_out << N;
    f_out << std::endl;

    Address** addr = new Address* [N];

    for (int i = 0; i < N; i++)
    {
        *addr[i] = new Address(number_house, number_apartment, city, street)[4];
    }

    /*for (int i = 0; i < N; i++)
    {
        f_in >> city; //город
        f_in >> street; //улица
        f_in >> number_house; //дом
        f_in >> number_apartment; //квартира

        addr[i] = new Address(number_house, number_apartment, city, street);
    }*/

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            f_in >> city; //город
            f_in >> street; //улица
            f_in >> number_house; //дом
            f_in >> number_apartment; //квартира

            addr[i][j] = Address(number_house, number_apartment, city, street);

            //f_out << addr.get_output_address();
            //f_out << std::endl;
        }
    }
    
    for (int i = N; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            f_out << addr[i][j].get_output_address();
        }
    }
                
    for (int i = 0; i < N; i++)
    {
        delete[] addr[i];
    }

    delete[] addr;

    f_in.close();
    f_out.close();           
}

