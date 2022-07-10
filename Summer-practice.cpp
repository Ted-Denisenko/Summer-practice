#include <iostream>
#include <fstream>
#include <list>


// ������ 5
/*
�������� ����, �� �������� ����������� ������, �������� ��� ������ ������������� ��������, ����� �������� ����� ������������� ��������.
��������� ��� ������ �1 � �2, �������� ������� �������� �������� �� ������� 1 � 2 �������������� (� ��� �������, ��� ��� ������ � �����).
��������� ���������� ������� �1 � �2 � ������ ������ �3, ���������� �������� �� ����������� ��������.
������� �� ����� ������ �1, �2, �3.
*/


int main()
{
    // ������ ������ �� ��������� �����
    std::ifstream fin;
    fin.open("C:\\Code\\summer_practice.txt");
    int read_number;
    bool separator_flag = 0;
    std::list<int> C1;
    std::list<int> C2;

    // ��������� ������ �������� �� ������������� ��������
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

    // ��������� ������ �1 � �2 � ������ �3 � ��������� �������� �� �����������
    std::list<int> C3;
    std::list<int>::iterator i = C3.begin();
    C3.insert(i, C1.begin(), C1.end());
    i = C3.end();
    C3.insert(i, C2.begin(), C2.end());
    C3.sort();

    // ������� �������� ������� �� �����
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

    // ��������� ����
    fin.close();
}