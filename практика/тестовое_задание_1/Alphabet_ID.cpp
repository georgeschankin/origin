#include "ID_Generation.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string str = "B5-K9";  
    std::cout << ID_Generation().GenerateNextIdentifier(str);
    return 0;
}