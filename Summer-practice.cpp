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
            // �� ������ ����� ��������(�� �������), ���������� ��� � int,
            // ��������� �� ��������������� - ���� �������������, ����� � ������ � ������������ ������,
            // ���� ��� - ����������� ��������� ������ ������ � ��������� ������ ���������� ����� ���. ����� � �� ����� ������

            int tmp_int;
            tmp_string = line;
            tmp_int = atoi(tmp_string.c_str());
            int count{0};
            {
                char ch{'0'};
                fin >> ch;
                int ch_int = (int)ch;
                while ( !fin.eof())
                {
                    fin >> ch;
                    if (ch > 0)
                        count++;
                }
                while (fin >> ch)
                {
                    count++;
                    count--;
                }
            }
        }
    }
    fin.close();     // ��������� ����
}