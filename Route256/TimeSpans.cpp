/*
Вам задан набор отрезков времени. Каждый отрезок задан в формате HH:MM:SS-HH:MM:SS, то есть сначала заданы часы,
минуты и секунды левой границы отрезка, а затем часы, минуты и секунды правой границы.

Вам необходимо выполнить валидацию заданного набора отрезков времени. Иными словами, вам нужно проверить следующие условия:

часы, минуты и секунды заданы корректно (то есть часы находятся в промежутке от 0 до 23, а минуты и секунды — в промежутке от 0 до 59);
левая граница отрезка находится не позже его правой границы (но границы могут быть равны);
никакая пара отрезков не пересекается (даже в граничных моментах времени).
Вам необходимо вывести YES, если заданный набор отрезков времени проходит валидацию, и NO в противном случае.

Вам необходимо ответить на t независимых наборов тестовых данных.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
    int count = 0;
    std::cin >> count;

    for (int i = 0; i < count; ++i)
    {
        int cnt = 0;
        std::cin >> cnt;

        std::vector<std::string> vec {};
        bool result = 1;

        std::multimap<int, int> mm{};

        for (int j = 0; j < cnt; ++j)
        {
            std::string str {};
            std::cin >> str;

            vec.push_back(str);
        }

        for (int k = 0; k < vec.size(); ++k)
        {
            int pos = 0;
            int pos1 = vec[k].find(":",pos);

            int hour1 = std::stoi(vec[k].substr(pos,pos1-pos));

            pos = pos1 + 1;
            pos1 = vec[k].find(":",pos);
            int min1 = std::stoi(vec[k].substr(pos,pos1-pos));

            pos = pos1 + 1;
            pos1 = vec[k].find("-",pos);
            int sec1 = std::stoi(vec[k].substr(pos,pos1-pos));

            pos = pos1 + 1;
            pos1 = vec[k].find(":",pos);
            int hour2 = std::stoi(vec[k].substr(pos,pos1-pos));

            pos = pos1 + 1;
            pos1 = vec[k].find(":",pos);
            int min2 = std::stoi(vec[k].substr(pos,pos1-pos));

            pos = pos1 + 1;
            int sec2 = std::stoi(vec[k].substr(pos,2));

            if (hour1 >= 0 && hour1 < 24 && hour2 >= 0 && hour2 < 24 &&
                min1 >= 0 && min1 < 60 && min2 >= 0 && min2 < 60 &&
                sec1 >= 0 && sec1 < 60 && sec2 >= 0 && sec2 < 60)
            {
                int time1 = hour1 * 3600 + min1 * 60 + sec1;
                int time2 = hour2 * 3600 + min2 * 60 + sec2;

                if (time1 <= time2)
                {
                    if (!mm.count(time1) && !mm.count(time2))
                    {
                        mm.insert(std::pair<int,int>(time1,k));
                        mm.insert(std::pair<int,int>(time2,k));
                    }
                    else
                    {
                        result = false;
                        break;
                    }
                }
                else
                {
                    result = false;
                    break;
                }
            }
            else
            {
                result = false;
                break;
            }
        }

        if (result)
        {
            for (auto it = mm.begin(); it != mm.end(); ++it)
            {
                auto it2 = it;
                ++it2;
                if (it->second == it2->second)
                {
                    it = it2;
                    continue;
                }
                else
                {
                    result = false;
                    break;
                }
            }
            if (result)
                std::cout << "YES" <<std::endl;
            else
                std::cout << "NO" <<std::endl;
        }
        else
            std::cout << "NO" <<std::endl;

    }

    return 0;
}

