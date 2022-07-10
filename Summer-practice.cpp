#include <iostream>
#include <fstream>
#include <list>


// Задача 5
/*
Исходный файл, из которого считываются данные, содержит два набора положительных значений, между наборами стоит отрицательное значение.
Построить два списка С1 и С2, элементы которых содержат значение из наборов 1 и 2 соответственно (в том порядке, как они заданы в файле).
Выполнить соединение списков С1 и С2 в третий список С3, упорядочив элементы по возрастанию значений.
Вывести на экран списки С1, С2, С3.
*/


int main()
{
    // читаем данные из исходного файла
    std::ifstream fin;
    fin.open("C:\\Code\\summer_practice.txt");
    int read_number;
    bool separator_flag = 0;
    std::list<int> C1;
    std::list<int> C2;

    // заполняем списки наборами из положительных значений
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

    // соединяем списки С1 и С2 в список С3 и сортируем значения по возрастанию
    std::list<int> C3;
    std::list<int>::iterator i = C3.begin();
    C3.insert(i, C1.begin(), C1.end());
    i = C3.end();
    C3.insert(i, C2.begin(), C2.end());
    C3.sort();

    // выводим значения списков на экран
    std::cout << "C1 and C2 values before merging in C3" << std::endl;
    std::cout << "\nC1:   ";
    for (std::list<int>::iterator i = C1.begin(); i != C1.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\nC2:   ";
    for (std::list<int>::iterator i = C2.begin(); i != C2.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n\nC3 list sorted values\n" << std::endl;
    for (std::list<int>::iterator i = C3.begin(); i != C3.end(); ++i)
    {
        std::cout << *i << " ";
    }

    // закрываем файл
    fin.close();
}