
#include <iostream>
#include <set>

int main()
{
    setlocale(LC_ALL, "rus");
    int v;
    std::set <int> st;
    for (int i = 0; i < 8; i++)
    {
        std::cin >> v;
        st.insert(v);
    }

    //почему-то такой код работает на версии C++ 20
    for (std::set<int>::reverse_iterator n = st.rbegin(); n != st.rend(); ++n)
    {
        std::cout << *n << " ";
    }
    return 0;
}
