#include "Ini_Parser.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    Ini_Parser parser("file_parcer.ini");
    auto value1 = parser.get_value<std::string>("Section2", "var2");
    std::cout << value1 << std::endl;

    auto value2 = parser.get_value<int>("Section1", "var1");
    std::cout << value2 << std::endl;

    return 0;
}