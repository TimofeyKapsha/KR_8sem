#pragma once

#ifndef MAZE_h
#define MAZE_h

class Mazecreate // ���������� ������ ��������
{
public:
    int start_x = 0, start_y = 0, end_x = 0, end_y = 0; // ������������� ����������, �������� ���������� ����� � ������ �� ���������
    bool check_input(int, int); // ����� �������� �� ���������� ������� ������
    void mazemake(int**, int, int); // �����, ����������� ��������� ������� ��������
    void visual(int**, int, int); // ����� ��� ������ ��������� � �������
    bool no_ways(int, int, int**, int, int); // ����� ��� �������� ������� � ���������
    bool check_out(int, int, int); // ����� ��� ����������� ������������ ����������� �� ������� rand()
    void start_point(int**, int, int); // �����, �������� ��������� ����� ����� � ��������
    void end_point(int**, int, int); // �����, �������� ��������� ����� ������ �� ���������
    int create_range(int, int); // ����� ��� �������� ������ ������� rand()
    void clear_memory(int**, int); // ����� ��� ������� ������ ������������� �������
};

#endif 