#include "Result_Sort.h"
#include <iostream>
#include <string>

void static sort(Result_Sort* res, int size)
{
    setlocale(LC_ALL, "Russian");

    Result_Sort temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (res[j].time_ > res[j + 1].time_)
            {
                temp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << res[i].name_trans_ << ". Время = " << res[i].time_ << std::endl;
    }
}
