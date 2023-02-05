#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
 
int main()
{
    int count = 0;
    std::cin >> count;
 
    for (int i = 0; i < count; i++)
    {
        int cnt = 0;
        std::cin >> cnt;
 
        std::vector<int> vec{};
 
        for (int j = 0; j < cnt; j++)
        {
            int val = 0;
            std::cin>>val;
            vec.push_back(val);
        }
        auto vec2 = vec;
        std::sort(vec2.begin(),vec2.end());
        std::unordered_map<int,int> umap{};
 
        int place = 0;
        int add = 1;
        int prev = -1;
        for (int k = 0; k < vec2.size(); k++)
        {
            if (vec2[k] - prev > 1)
            {
                umap[vec2[k]] = place + add;
                place = place + add;
                prev = vec2[k];
                add = 1;
            }
            else
            {
                umap[vec2[k]] = place;
                add++;
                prev = vec2[k];
            }
        }
 
        for(const auto &el : vec)
        {
            std::cout << umap[el] << " ";
        }
        std::cout << std::endl;
 
    }
    return 0;
}
