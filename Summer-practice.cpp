#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cstdio>
#include <cassert>
#include <algorithm>


// ������ 5
/*
�������� ����, �� �������� ����������� ������, �������� ��� ������ ������������� ��������, ����� �������� ����� ������������� ��������.
��������� ��� ������ �1 � �2, �������� ������� �������� �������� �� ������� 1 � 2 �������������� (� ��� �������, ��� ��� ������ � �����).
��������� ���������� ������� �1 � �2 � ������ ������ �3, ���������� �������� �� ����������� ��������.
������� �� ����� ������ �1, �2, �3.
*/

/*
� ����� ���� �������� � ������, � �������� ����������� ������������ ������������� �����.
����� �� ���. ����� � ������ �1, ����� ����� ���. ����� � ������ �2.
������� ��� ������ � ����, ������������� � ������� ���������� ��������
������� ������ �1, �2 � ��������������� �3.
*/


int main()
{
    std::ifstream fin;
    fin.open("C:\\Code\\summer_practice.txt");
    int read_number;
    bool separator_flag = 0;
    std::list<int> C1;
    std::list<int> C2;

    // ������ ���� � ��������� �� ��� ������
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

    // ��������� ������ �3 ������������������ ���������� �� C1 � C2
    std::list<int> C3;
    std::list<int>::iterator i = C3.begin();
    C3.insert(i, C1.begin(), C1.end());
    i = C3.end();
    C3.insert(i, C2.begin(), C2.end());
    // ��������� �3
    C3.sort();

    fin.close();     // ��������� ����
}