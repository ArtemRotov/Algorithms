/*
В магазине акция: «купи три одинаковых товара и заплати только за два».
 Конечно, каждый купленный товар может участвовать лишь в одной акции.
  Акцию можно использовать многократно.

Например, если будут куплены 7 товаров одного вида по цене 2 за штуку и 
5 товаров другого вида по цене 3 за штуку, то вместо 7⋅2+5⋅3 надо будет 
оплатить 5⋅2+4⋅3=22.

Считая, что одинаковые цены имеют только одинаковые товары, найдите сумму к оплате.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    int count = 0;
    std::vector<std::vector<int>> table {};

    std::cin >> count;

    for (int i = 0; i < count; ++i)
    {
        int cnt = 0;
        std::cin >> cnt;

        table.emplace_back();

        for (int j = 0; j < cnt; ++j)
        {
            int val = 0;
            std::cin >> val;
            table[i].push_back(val);
        }

    }

    for (std::vector<int> &vec : table)
    {
        std::sort(vec.begin(),vec.end());

        int size = vec.size() - 2;
        for (int i = 0; i < (int) vec.size() -2 ; ++i)
        {
            if (vec[i] == vec[i+2])
            {
                vec[i] = 0;
                i += 2;
            }
        }

        std::cout << std::accumulate(vec.begin(),vec.end(),0 ) << std::endl;
    }

    return 0;
}
