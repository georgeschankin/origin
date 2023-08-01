
#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");

    //std::ofstream f_in;
    //f_in.open("in.txt");
    //std::ofstream f_out;
    //f_out.open("out.txt");

    std::ifstream f_in("in.txt");
    std::string s_in;

    //чтение первого массива

    int n, i = 0;

    f_in >> n;
    std::cout << "количество элементов в первом массиве " << n << std::endl;

    int* mass_N = new int[n];

    while ((!f_in.eof()) && (i < n))
    {
        f_in >> mass_N[i];
        std::cout << mass_N[i] << " ";
        i++;
    }


    std::cout << "\n";

    //замена последнего элемента на первый
    int t1;
    t1 = mass_N[n - 1];
    mass_N[n - 1] = mass_N[0];
    

    //сдвиг влево
    for (int r = 0; r < n - 1; r++)
    {
        mass_N[r - 1] = mass_N[r];
        if (r == n - 2)
        {
            mass_N[r] = t1;
        }
    }

    std::cout << "массив N после сдвига " << std::endl;
    for (int r = 0; r < n; r++)
    {
        std::cout << mass_N[r] << " ";
    }

    std::cout << "\n";

    //чтение второго массива

    int m, k = 0;

    f_in >> m;
    std::cout << "количество элементов во втором массиве " << m << std::endl;

    int* mass_M = new int[m];

    while ((!f_in.eof()) && (k < m))
    {
        f_in >> mass_M[k];
        std::cout << mass_M[k] << " ";
        k++;
    }

    std::cout << "\n";

    //замена первого элемента на последний
    int t2;
    t2 = mass_M[0];
    mass_M[0] = mass_M[m - 1];

    //сдвиг вправо
    for (int r = m - 1; r >= 1; r--)
    {
        mass_M[r] = mass_M[r - 1];
        if (r == 1)
        {
            mass_M[r] = t2;
        }
    }

    std::cout << "массив M после сдвига " << std::endl;
    for (int r = 0; r < m; r++)
    {
        std::cout << mass_M[r] << " ";
    }

    //запись в файл массивов
    std::ofstream f_out("out.txt", std::ios::app);

    if (f_out.is_open())
    {
        //запись в файл массива M
        f_out << m << "\n";
        for (int r = 0; r < n; r++)
        {
            f_out << mass_M[r] << " ";
        }

        f_out << "\n";

        //запись в файл массива N
        f_out << n << "\n";
        for (int r = 0; r < n; r++)
        {
            f_out << mass_N[r] << " ";
        }

        f_out.close();
    }

    /*f_out << m << "\n";
    for (int r = 0; r < n; r++)
    {
        f_out << mass_M[r] << " ";
    }

    //запись в файл массива N
    f_out << n << "\n";
    for (int r = 0; r < n; r++)
    {
        f_out << mass_N[r] << " ";
    }*/

    delete [] mass_N;

    delete[] mass_M;

    f_in.close();

    
}


