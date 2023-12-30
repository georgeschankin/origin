
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void uniq_vector(std::vector<T>& v)
{
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}

int main()
{
    std::vector <int> A = { 1, 2, 7, 3, 9, 4, 3, 2 };
    uniq_vector(A);   
    return 0;
}
