/*
Вам необходимо написать часть функциональности обработки сортировок в электронных таблицах.

Задана прямоугольная таблица n×m (n строк по m столбцов) из целых чисел.

Если кликнуть по заголовку i-го столбца, то строки таблицы пересортируются таким образом, что
в этом столбце значения будут идти по неубыванию (то есть возрастанию или равенству). При этом,
если у двух строк одинаковое значение в этом столбце, то относительный порядок строк не изменится.

Обработайте последовательность кликов и выведите состояние таблицы после всех кликов.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int count = 0;
    std::cin >> count;

    for (int i = 0; i < count; ++i)
    {
        int n = 0;
        int m = 0;

        std::cin >> n;
        std::cin >> m;

        std::vector<std::vector<int>> m_table;

        for (int j = 0; j < n; ++j)
        {
            m_table.emplace_back();

            for (int k = 0; k < m; ++k)
            {
                int val = 0;
                std::cin >> val;

                m_table[j].push_back(val);
            }
        }

        int clickCount = 0;
        std::vector<int> clicks {};
        int last = 0;

        std::cin >> clickCount;

        for (int j = 0; j < clickCount; ++j)
        {
            int val = 0;
            std::cin >> val;
            clicks.push_back(val);
        }

        for (const auto &cl : clicks)
        {
            if (last == cl)
                continue;

            std::stable_sort(m_table.begin(),m_table.end(), [&](const auto &vec1,const auto &vec2){
            return vec1[cl-1] < vec2[cl-1];
        });

            last = cl;
        }

        for (const auto &vec : m_table)
        {
            for (const auto &el : vec)
                std::cout << el << ' ';

            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
