/*
Вы разрабатываете программу автоматической генерации стихотворений. Один из модулей этой программы должен подбирать рифмы
к словам из некоторого словаря.

Словарь содержит n различных слов. Словами будем называть последовательности из 1—10 строчных букв латинского алфавита.

Зарифмованность двух слов — это длина их наибольшего общего суффикса (суффиксом будем называть какое-то количество букв
в конце слова). Например:

task и flask имеют зарифмованность 3 (наибольший общий суффикс — ask);
decide и code имеют зарифмованность 2 (наибольший общий суффикс — de);
id и void имеют зарифмованность 2 (наибольший общий суффикс — id);
code и forces имеют зарифмованность 0.

Ваша программа должна обработать q запросов следующего вида: дано слово ti (возможно, принадлежащее словарю), необходимо
найти слово из словаря, которое не совпадает с ti и имеет максимальную зарифмованность с ti среди всех слов словаря, не
совпадающих с ti. Если подходящих слов несколько — выведите любое из них.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    int len = 0;
    std::cin >> len;

    std::unordered_map<std::string, std::vector<std::string>> uMap {};

    for (int i = 0; i < len; ++i)
    {
        std::string str {};
        std::cin >> str;

        std::string tmp = str;
        for (int i = 0; i < str.size(); ++i)
        {
            tmp = str.substr(i);
            uMap[tmp].push_back(str);
        }
    }

    int count = 0;
    std::cin >> count;

    std::vector<std::string> results {};

    for (int i = 0; i < count; ++i)
    {
        std::string str {};
        std::cin >> str;

        std::string result {};

        for (int i = 0; i < str.size(); ++i)
        {
            std::string tmp = str.substr(i);
            if (uMap.count(tmp))
            {
                std::vector<std::string> &vec = uMap[tmp];
                for (const std::string &s : vec)
                {
                    if (s != str)
                    {
                        result = s;
                        break;
                    }
                }
                if (result != "")
                    break;
            }
        }
        if (result == "")
        {
            auto it = uMap.begin();
            while(true)
            {
                std::vector<std::string> &vec = it->second;
                for (const std::string &s : vec)
                {
                    if (s != str)
                    {
                        result = s;
                        break;
                    }
                }

                if (result != "")
                    break;
                it++;
            }
        }
        results.push_back(result);
    }

    for (auto &el : results)
        std::cout << el << std::endl;

    return 0;
}
