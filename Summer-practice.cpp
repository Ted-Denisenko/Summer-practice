#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cstdio>
#include <cassert>


// ������ 5
/*
�������� ����, �� �������� ����������� ������, �������� ��� ������ ������������� ��������, ����� �������� ����� ������������� ��������.
��������� ��� ������ �1 � �2, �������� ������� �������� �������� �� ������� 1 � 2 �������������� (� ��� �������, ��� ��� ������ � �����).
    ������� ��� ������, ���������� � ������ ����� �� �������������� ��������, �� ������ - ����� �������������� � �� ����� �����
��������� ���������� ������� �1 � �2 � ������ ������ �3, ���������� �������� �� ����������� ��������.
    ���������� ��� ������� � ����, ����� ��������� ���������� ��� �3
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
    fin.close();     // ��������� ����
}

