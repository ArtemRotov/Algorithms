/*
Напишите программу, которая выводит сумму двух целых чисел.

Пример входных данных:
5
256 42
1000 1000
-1000 1000
-1000 1000
20 22

Пример выходных данных:
298
2000
0
0
42

*/

#include <iostream>
#include <vector>

int main()
{
    int count = 0;
    std::vector <int> vec {};

    std::cin >> count;

    for (int i = 0; i < count*2; ++i)
    {
        int val = 0;
        std::cin >> val;
        vec.push_back(val);
    }

    for (int i = 0; i < count * 2 - 1; ++i)
    {
        std::cout << vec[i] + vec[i+1] << std::endl;
        ++i;
    }

    return 0;
}
