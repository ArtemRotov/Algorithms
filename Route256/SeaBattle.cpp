#include <iostream>
#include <unordered_map>
 
int main()
{
 
    int count = 0;
    std::cin >> count;
 
    for (int i = 0; i < count; i++)
    {
       std::unordered_map<int,int> u {};
 
        for (int j = 0; j < 10; j++)
        {
            int val = 0;
            std::cin >> val;
            u[val]++;
        }
 
        if (u[1] != 4)
        {
            std::cout<<"NO" << std::endl;
            continue;
        }
        if (u[2] != 3)
        {
            std::cout<<"NO" << std::endl;
            continue;
        }
        if (u[3] != 2)
        {
            std::cout<<"NO" << std::endl;
            continue;
        }
        if (u[4] != 1)
        {
            std::cout<<"NO" << std::endl;
            continue;
        }
        std::cout<<"YES" << std::endl;
    }
    return 0;
}
