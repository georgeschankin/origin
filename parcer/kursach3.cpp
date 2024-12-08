#include "Ini_Parser.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    Ini_Parser parser("file_parcer.ini");
    auto value = parser.get_value<std::string>("Section2", "var2");
    std::cout << value;

    return 0;
}