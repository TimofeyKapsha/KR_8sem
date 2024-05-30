#include "Maze.h"
#include <ctime> // ����������� ���������
#include <cstdlib>
#include <iostream>

using namespace std;

bool Mazecreate::no_ways(int x, int y, int** maze, int rows, int colls) // ���������� ������ �������� ������� ���� � ���������
{
    int way_counter = 0; // ������� ����������� ����� ��� ��������

    if (x != 1) // �������� ������ �� ������ ������� ��������
    {
        if (maze[y][x - 2] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (y != 1) // �������� ������ �� ������ ������� �����
    {
        if (maze[y - 2][x] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (x != colls - 2) // �������� ������ �� ������� ������� ��������
    {
        if (maze[y][x + 2] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (y != rows - 2) // �������� ������ �� ������� ������� ��������
    {
        if (maze[y + 2][x] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (way_counter == 4) // ���� ��������� ������ ������� 1 ����� 0
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Mazecreate::mazemake(int** maze, int rows, int colls) // �����, ����������� ��������
{
    int x = 3, y = 3, key = 0, a = 0; // x,y - �����, �� ������� ���������� ������������ ����� � ���������, key - ����������, ���������� �� ��������� �����������
                                      // a - �������� ���������� ��� ������� ������� ������ �� ����� 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colls; j++) { // ������������� ������� ������
            maze[i][j] = 0;
        }
    }


    while (a < 10000) // ���� ��� "����������" ����� � ���������
    {
        maze[y][x] = 1; a++; // ��������� ����� ��� "����������" �����
        while (true)
        {
            key = rand() % 4; // ��������� ��������� ����������� "����������" �����
            switch (key) // �������� �������� ����������� ���� � ����������� ���������� �� �������� key
            {
            case 0: // "����������" 2-� ������ �����
                if (y != 1)
                {
                    if (maze[y - 2][x] == 0)
                    {
                        maze[y - 1][x] = 1;
                        maze[y - 2][x] = 1;
                        y -= 2;
                    }
                }
            case 1: // "����������" 2-� ������ ����
                if (y != rows - 2)
                {
                    if (maze[y + 2][x] == 0)
                    {
                        maze[y + 1][x] = 1;
                        maze[y + 2][x] = 1;
                        y += 2;
                    }
                }
            case 2: // "����������" 2-� ������ �����
                if (x != 1)
                {
                    if (maze[y][x - 2] == 0)
                    {
                        maze[y][x - 1] = 1;
                        maze[y][x - 2] = 1;
                        x -= 2;
                    }
                }
            case 3: // "����������" 2-� ������ ������
                if (x != colls - 2)
                {
                    if (maze[y][x + 2] == 0)
                    {
                        maze[y][x + 1] = 1;
                        maze[y][x + 2] = 1;
                        x += 2;
                    }
                }
            }

            if (no_ways(x, y, maze, rows, colls)) // ���� ��������� ����� ���, ����� �� �����
            {
                break;
            }
        }

        if (no_ways(x, y, maze, rows, colls)) // ���� ��������� �����, �� ������������ � �������, ��� ����� ��������� ����� ������
        {
            do
            {
                x = 2 * (rand() % ((colls - 1) / 2)) + 1;
                y = 2 * (rand() % ((rows - 1) / 2)) + 1;
            } while (maze[y][x] != 1);
        }
    }
}

int Mazecreate::create_range(int rows, int colls) // ���������� ������, �������������� ������� rand()
{
    if (rows > colls)
    {
        return rows;
    }
    else
    {
        return colls;
    }
}

bool Mazecreate::check_out(int rows, int colls, int res) // ���������� ������, ������������ ����� �� ���������� ������� ������� rand()
{
    if (res >= rows || res >= colls)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Mazecreate::start_point(int** maze, int rows, int colls) // ���������� ������, ��������� ����� ����� � ��������
{
    int temp = create_range(rows, colls); // ����������, �������� ��������� ���������� ������ create_range

    for (int i = 0; i < rows; i++) { // ��������� ���� ��� ������� ��������� ����� � ��������
        for (int j = 0; j < colls; j++) {

            start_x = rand() % (temp - 0 + 1);
            start_y = start_x;

            if (!check_out(rows, colls, start_x)) // �������� ���������� �����������
            {
                continue;
            }

            if (maze[start_x][start_y] == 1) // ��������, ��� ������� ����� �� �������� ������
            {
                maze[start_x][start_y] = 2; // ���������� ����� ����� � ������� �������� �������� 2
                return;
            }
        }
    }
}

void Mazecreate::end_point(int** maze, int rows, int colls) // ���������� ������, ��������� ����� ������ � ��������
{
    int temp = create_range(rows, colls); // ����������, �������� ��������� ���������� ������ create_range

    for (int i = 0; i < rows; i++) { // ��������� ���� ��� ������� ��������� ����� � ��������
        for (int j = 0; j < colls; j++) {

            end_x = rand() % (temp - 0 + 1);
            end_y = end_x;

            if (!check_out(rows, colls, end_x)) // �������� ���������� �����������
            {
                continue;
            }

            if (maze[end_x][end_y] == 1) // ��������, ��� ������� ������ �� �������� ������
            {
                maze[end_x][end_y] = 3; // ���������� ����� ����� � ������� �������� �������� 3
                return;
            }
        }
    }
}

void Mazecreate::visual(int** maze, int rows, int colls) // �����, ����������� ����� ��������� � ������� 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colls; j++) {
            switch (maze[i][j]) // ����� �������� �������� ���������
            {
           // case 4: cout << "- "; break; 
            case 3: cout << "^ "; break; // ������ 3 - ����� ����� ������ �� ���������
            case 2: cout << "* "; break; // ������ 2 - ����� ����� ����� � ��������
            case 1: cout << "  "; break; // ������ 1 - ����� ������-�������
            case 0: cout << "0 "; break; // ������ 0 - ����� ������-�����
            }
        }
        cout << '\n';
    }
}

bool Mazecreate::check_input(int rows, int colls) // ����� �������� ������������ ������� ������
{
    if (rows % 2 != 0 || colls % 2 != 0) // ���� ����� �������� ��� ����� ������ ������� 0 ����� ������� 1
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void Mazecreate::clear_memory(int** maze, int rows) // �����, ����������� ������� ������ ������������� �������
{
    for (int i = 0; i < rows; i++)
    {
        delete[] maze[i];
    }

    delete[] maze;
}