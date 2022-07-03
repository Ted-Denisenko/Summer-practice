#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cstdio>
#include <cassert>


// Задача 5
/*
Исходный файл, из которого считываются данные, содержит два набора положительных значений, между наборами стоит отрицательное значение.
Построить два списка С1 и С2, элементы которых содержат значение из наборов 1 и 2 соответственно (в том порядке, как они заданы в файле).
    создать два списка, записывать в первый числа до отрицательного значения, во второй - после отрицательного и до конца файла
Выполнить соединение списков С1 и С2 в третий список С3, упорядочив элементы по возрастанию значений.
    объединить два массива в один, затем запустить сортировку для С3
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
    FILE* ptrFile;
    errno_t err = fopen_s(&ptrFile, "C:\\Code\\summer_practice.txt", "r");
    assert(err == 0 && "File has failed to open!");
    std::string line;
    std::list<int> C1;
    std::list<int> C2;
    if (fin.is_open())
    {
        std::string tmp_string;
        while (getline(fin, line))
        {
            int tmp_int;
            tmp_string = line;
            tmp_int = atoi(tmp_string.c_str());

            int counter{0};
            while (tmp_int > 0)
            {
                C1.push_back(tmp_int);
                counter++;
            }
            line = fseek(ptrFile, counter*sizeof(int), SEEK_SET);

            while (tmp_int > 0 )
            {
                C1.push_back(tmp_int);
                counter++;
            }
        }
    }
    fin.close();     // закрываем файл
}

