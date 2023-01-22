/*
    Представьте, вы собрали собственный сервер из n разнородных процессоров и теперь решили создать для него
простейший планировщик задач.

Ваш сервер состоит из n процессоров. Но так как процессоры разные, то и достигают они одинаковой скорости
работы при разном энергопотреблении. А именно, i-й процессор в нагрузке тратит ai энергии за одну секунду.

Вашему серверу в качестве тестовой нагрузки придет m задач. Про каждую задачу вам известны два значения:
tj и lj — момент времени, когда задача j придет и время выполнения задачи в секундах.

Для начала вы решили реализовать простейший планировщик, ведущий себя следующим образом: в момент tj прихода
задачи, вы выбираете свободный процессор с минимальным энергопотреблением и выполняете данную задачу на
выбранном процессоре все заданное время. Если к моменту прихода задачи свободных процессоров нет, то вы
просто отбрасываете задачу.

Процессор, на котором запущена задача j будет занят ровно lj секунд, то есть освободится ровно в момент tj+lj
и в этот же момент уже может быть назначен для выполнения какой-то другой задачи.

Определите суммарное энергопотребление вашего сервера при обработке m заданных задач (будем считать, что
процессоры в простое не потребляют энергию).
*/

#include <iostream>
#include <vector>
#include <map>

int main()
{
    int nProc = 0;
    int nTask = 0;
    std::cin >> nProc >> nTask;

    std::map<int, int> mm {};
    std::multimap<int, int> del {};

    for (int i = 0; i < nProc; ++i)
    {
        int energy = 0;
        std::cin >> energy;

        mm[energy] = 1;
    }

    long long result = 0;

    for (int i = 0; i < nTask; ++i)
    {
        int t = 0;
        int duration = 0;
        std::cin >> t >> duration;

        for (auto it = del.begin(); it != del.end(); )
        {
            if (it->first <= t)
            {
                auto save = it;
                save++;
                mm.insert(std::pair<int,int>(it->second,it->first));
                del.erase(it);
                it = save;
                continue;
            }

           break;
        }

        for (auto it = mm.begin(); it != mm.end(); ++it)
        {
            if (it->second <= t)
            {
                it->second = t + duration;
                result += (long long)it->first * (long long)duration;
                del.insert(std::pair<int,int>(it->second,it->first));
                mm.erase(it);
                break;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}