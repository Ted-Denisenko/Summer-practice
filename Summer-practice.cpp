#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cstdio>
#include <cassert>
#include <algorithm>


// Задача 5
/*
Исходный файл, из которого считываются данные, содержит два набора положительных значений, между наборами стоит отрицательное значение.
Построить два списка С1 и С2, элементы которых содержат значение из наборов 1 и 2 соответственно (в том порядке, как они заданы в файле).
Выполнить соединение списков С1 и С2 в третий список С3, упорядочив элементы по возрастанию значений.
Вывести на экран списки С1, С2, С3.
*/

/*
В файле идут значения в строке, в качестве разделителя используется отрицательное число.
Числа до отр. числа – список С1, числа после отр. числа – список С2.
Собрать два списка в один, отсортировать с помощью сортировки слиянием
Вывести списки С1, С2 и отсортированный С3.
*/


int main()
{
    std::ifstream fin;
    fin.open("C:\\Code\\summer_practice.txt");
    int read_number;
    bool separator_flag = 0;
    std::list<int> C1;
    std::list<int> C2;

    // читаем файл и разбиваем на два списка
    while (fin >> read_number)
    {
        if (read_number < 0)
        {
            separator_flag = 1;
            continue;
        }
        if (separator_flag == 0)
            C1.push_back(read_number);
        if (separator_flag == 1)
            C2.push_back(read_number);
    }

    // заполняем список С3 неотсортированными значениями из C1 и C2
    std::list<int> C3;
    std::list<int>::iterator i = C3.begin();
    C3.insert(i, C1.begin(), C1.end());
    i = C3.end();
    C3.insert(i, C2.begin(), C2.end());
    // сортируем С3
    C3.sort();

    fin.close();     // закрываем файл
}